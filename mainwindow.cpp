#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize QProcess
    process = new QProcess(this);
    
    // Load custom stylesheet
    QFile file("../styles/style.qss");
    if (file.open(QFile::ReadOnly)) {
        QString stylesheet = QLatin1String(file.readAll());
        setStyleSheet(stylesheet);
    } else {
        qWarning() << "Failed to open stylesheet file:" << file.errorString();
    }
    
    // Connect buttons to their slots
    connect(ui->uploadButton, &QPushButton::clicked, this, &MainWindow::onUploadButtonClicked);
    connect(ui->outputButton, &QPushButton::clicked, this, &MainWindow::onOutputButtonClicked);
    connect(ui->convertButton, &QPushButton::clicked, this, &MainWindow::onConvertButtonClicked);
    connect(ui->quantizeButton, &QPushButton::clicked, this, &MainWindow::onQuantizeButtonClicked);
    
    connect(ui->uploadEncodeButton, &QPushButton::clicked, this, &MainWindow::onUploadEncodeButtonClicked);

    connect(ui->uploadDLCButton, &QPushButton::clicked, this, &MainWindow::onUploadDLCButtonClicked);
    connect(ui->quantizeChoiceComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onQuantizeChoiceChanged);
    connect(ui->encodeChoiceComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onEncodeChoiceChanged);
    
    connect(ui->resolutionChoiceComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onResolutionChoiceChanged);
    
    connect(ui->visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeButtonClicked);


    ui->quantizeChoiceComboBox->setCurrentText("No");
    // Set default conversion type
    ui->encodeChoiceComboBox->setCurrentText("No");

    ui->resolutionChoiceComboBox->setEnabled(false);
    ui->uploadEncodeButton->setEnabled(false);

    ui->quantizeButton->setEnabled(false);
    // Disable Convert button initially
    ui->convertButton->setEnabled(false);
    
    ui->visualizeButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (process->state() == QProcess::Running) {
        process->close();
        process->waitForFinished(-1); // Ensure the process finishes before destroying
    }
    delete process;
    delete ui;
}

void MainWindow::onUploadButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open ONNX Model", "", "ONNX Models (*.onnx);;All Files (*)");

    if (!filePath.isEmpty()) {
        onnxFilePath = filePath;
        ui->uploadStatusLabel->setText("Selected file: " + filePath);
        // Enable the convert button only if both the ONNX model and output folder are selected
        ui->convertButton->setEnabled(!onnxFilePath.isEmpty() && !outputFolder.isEmpty());
    } else {
        ui->uploadStatusLabel->setText("No file selected.");
    }
}

void MainWindow::onUploadDLCButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open DLC Model", "", "DLC Models (*.dlc);;All Files (*)");

    if (!filePath.isEmpty()) {
        dlcFilePath = filePath;
        ui->uploadDLCStatusLabel->setText("Selected file: " + filePath);
        ui->visualizeButton->setEnabled(true);
    } else {
        ui->uploadDLCStatusLabel->setText("No file selected.");
        ui->visualizeButton->setEnabled(false);
    }
}

void MainWindow::onEncodeChoiceChanged(const QString &text)
{
    encode_choice = (text == "Yes"); // Set the flag based on the selected conversion type
    if(encode_choice) {
        ui->encodeStatusLabel->setText("Enable Encoding");
        ui->uploadEncodeButton->setEnabled(true);
        ui->convertButton->setEnabled(false);
    } else {
        ui->encodeStatusLabel->setText("Disable Encoding");
        ui->uploadEncodeButton->setEnabled(false);
        ui->convertButton->setEnabled(true);
    }
}

void MainWindow::onUploadEncodeButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open Encodings File", "", "DLC Models (*.encodings);;All Files (*)");

    if (!filePath.isEmpty()) {
        encodeFilePath = filePath;
        ui->uploadEncodeStatusLabel->setText("Selected file: " + filePath);
        ui->convertButton->setEnabled(!encodeFilePath.isEmpty() && !outputFolder.isEmpty());
    } else {
        ui->uploadEncodeStatusLabel->setText("No file selected.");
        ui->convertButton->setEnabled(false);
    }
}

void MainWindow::onQuantizeChoiceChanged(const QString &text)
{
    modelQuantize = (text == "Yes"); // Set the flag based on the selected conversion type
    if(modelQuantize) {
        ui->quantizeStatusLabel->setText("Quantize Your Model: Yes");
        ui->quantizeButton->setEnabled(true);
        ui->resolutionChoiceComboBox->setEnabled(true);
        ui->convertButton->setEnabled(false);
    } else {
        ui->quantizeStatusLabel->setText("Quantize Your Model: No");
        ui->quantizeButton->setEnabled(false);
        ui->resolutionChoiceComboBox->setEnabled(false);
        ui->resolutionChoiceComboBox->setCurrentText("");
        ui->resolutionStatusLabel->setText("");
    }
}

void MainWindow::onResolutionChoiceChanged(const QString &text)
{
    if(text == "480x480") {
        resolution = "480";
        ui->resolutionStatusLabel->setText("480x480 Selected");
    }
    else if(text == "640x640") {
        resolution = "640";
        ui->resolutionStatusLabel->setText("640x640 Selected");
    }
}



void MainWindow::onOutputButtonClicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Output Folder");

    if (!folder.isEmpty()) {
        outputFolder = folder;
        ui->outputStatusLabel->setText("Output folder set: " + folder);
        // Enable the convert button only if both the ONNX model and output folder are selected
        ui->convertButton->setEnabled(!onnxFilePath.isEmpty() && !outputFolder.isEmpty());
    } else {
        ui->outputStatusLabel->setText("No output folder selected.");
        ui->convertButton->setEnabled(false);  // Disable the convert button if no output folder is selected
    }
}

void MainWindow::onVisualizeButtonClicked()
{
    if (dlcFilePath.isEmpty()) {
        ui->visualizeStatusLabel->setText("Please select a dlc model.");
        return;
    }
    
    QString pythonScript = "../visualize_model.py"; // Path to your Python script
    QFileInfo scriptInfo(pythonScript);
    if (!scriptInfo.exists()) {
        ui->visualizeStatusLabel->setText("Python script not found: " + pythonScript);
        return;
    }
    
    QStringList arguments;


    arguments << dlcFilePath;

    process->start("python", QStringList() << pythonScript << arguments);
    process->waitForFinished(-1);

    QString output(process->readAllStandardOutput());
    QString error(process->readAllStandardError());

    if (process->exitStatus() == QProcess::NormalExit && process->exitCode() == 0) {
        ui->visualizeStatusLabel->setText("Model visualized successfully. " + output);
    } else {
        ui->visualizeStatusLabel->setText("Error during visualization: " + error);
    }
}

void MainWindow::onQuantizeButtonClicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Output Folder");

    if (!folder.isEmpty()) {
        quantizeFolder = folder;
        ui->quantizeImageStatusLabel->setText("Quantize folder set: " + folder);
        // Enable the convert button only if both the ONNX model, output folder, and quantization folder are selected
        ui->convertButton->setEnabled(!onnxFilePath.isEmpty() && !outputFolder.isEmpty() && !quantizeFolder.isEmpty());
    } else {
        ui->quantizeImageStatusLabel->setText("No Quantize folder selected.");
        ui->convertButton->setEnabled(false);  // Disable the convert button if no quantize folder is selected
    }
}

void MainWindow::executePythonScript(const QString &scriptPath, const QStringList &arguments, const QString &successMessagePrefix, const QString &errorMessagePrefix) {
    QProcess process;

    QFileInfo scriptInfo(scriptPath);
    if (!scriptInfo.exists()) {
        ui->convertStatusLabel->setText("Python script not found: " + scriptPath);
        return;
    }

    process.start("python", QStringList() << scriptPath << arguments);
    if (!process.waitForStarted()) {
        ui->convertStatusLabel->setText("Failed to start the Python script: " + scriptPath);
        return;
    }
    
    process.waitForFinished(-1);

    QString output(process.readAllStandardOutput());
    QString error(process.readAllStandardError());

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
        ui->convertStatusLabel->setText(successMessagePrefix + output);
    } else {
        ui->convertStatusLabel->setText(errorMessagePrefix + error);
    }
}

void MainWindow::onConvertButtonClicked() {
    ui->convertStatusLabel->setText("Starting Conversion Process...");
    QCoreApplication::processEvents();
    if (onnxFilePath.isEmpty() || outputFolder.isEmpty()) {
        ui->convertStatusLabel->setText("Please select a model and an output folder.");
        return;
    }

    if (modelQuantize && quantizeFolder.isEmpty()) {
        ui->convertStatusLabel->setText("Please select an Input Image folder for quantization.");
        return;
    }
    
    if(modelQuantize) {
        // Generate raw Image
        quantizeOutputFolder = quantizeFolder + "_" + resolution;
        
        // Check if the folder exists, delete if it does, and create an empty folder
        QDir dir(quantizeOutputFolder);
        if (dir.exists()) {
            dir.removeRecursively();
        }
        dir.mkpath(".");
        
        QString gen_raw_Script = "../create_inceptionv3_raws.py";
        QStringList genRawArguments;
        genRawArguments << "-s" << resolution << "-i" << quantizeFolder << "-d" << quantizeOutputFolder;

        executePythonScript(gen_raw_Script, genRawArguments, "Generate raw image successfully. ", "Error during generating raw image: ");

        // Create image_file_list.txt
        QString gen_file_Script = "../create_file_list.py";
        QString fileName = "image_file_list.txt";
        QString fullPath = quantizeOutputFolder + "/" + fileName;
        QStringList fileListArguments;
        fileListArguments << "-i" << quantizeOutputFolder << "-o" << fullPath << "-e" << "*.raw";

        executePythonScript(gen_file_Script, fileListArguments, "File list generated successfully. ", "Error during generating file list: ");
    }

    

    // Convert to ONNX and DLC model
    QString pythonScript = "../convert_model.py";
    QStringList convertArguments;
    convertArguments << onnxFilePath << outputFolder << (encode_choice ? "YES" : "NO") << encodeFilePath << (modelQuantize ? "YES" : "NO") << quantizeOutputFolder;

    executePythonScript(pythonScript, convertArguments, "Model converted successfully. ", "Error during conversion: ");
}
