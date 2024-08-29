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

    connect(ui->uploadDLCButton, &QPushButton::clicked, this, &MainWindow::onUploadDLCButtonClicked);
    connect(ui->quantizeChoiceComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onQuantizeChoiceChanged);
    connect(ui->convertTypeComboBox, &QComboBox::currentTextChanged, this, &MainWindow::onConvertTypeChanged);
    
    connect(ui->visualizeButton, &QPushButton::clicked, this, &MainWindow::onVisualizeButtonClicked);


    ui->quantizeChoiceComboBox->setCurrentText("No");
    // Set default conversion type
    ui->convertTypeComboBox->setCurrentText("yolov5");

    ui->quantizeButton->setEnabled(false);
    // Disable Convert button initially
    ui->convertButton->setEnabled(false);
    
    ui->visualizeButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    if (process->state() == QProcess::Running) {
        process->terminate();
        process->waitForFinished(); // Ensure the process finishes before destroying
    }
    delete process;
    delete ui;
}

void MainWindow::onUploadButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open PyTorch Model", "", "PyTorch Models (*.pt);;All Files (*)");

    if (!filePath.isEmpty()) {
        ptFilePath = filePath;
        ui->uploadStatusLabel->setText("Selected file: " + filePath);
        ui->convertButton->setEnabled(true);
    } else {
        ui->uploadStatusLabel->setText("No file selected.");
    }
}

void MainWindow::onUploadDLCButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open DLC Model", "", "DLC Models (*.DLC);;All Files (*)");

    if (!filePath.isEmpty()) {
        dlcFilePath = filePath;
        ui->uploadDLCStatusLabel->setText("Selected file: " + filePath);
        ui->visualizeButton->setEnabled(true);
    } else {
        ui->uploadDLCStatusLabel->setText("No file selected.");
        ui->visualizeButton->setEnabled(false);
    }
}

void MainWindow::onConvertTypeChanged(const QString &text)
{
    yolov5Convert = (text == "yolov5"); // Set the flag based on the selected conversion type
    if(yolov5Convert) {
        ui->modelStatusLabel->setText("You Select: Yolov5");
    } else {
        ui->modelStatusLabel->setText("You Select: Yolov8");
    }
}

void MainWindow::onQuantizeChoiceChanged(const QString &text)
{
    modelQuantize = (text == "Yes"); // Set the flag based on the selected conversion type
    if(modelQuantize) {
        ui->quantizeStatusLabel->setText("Quantize Your Model: Yes");
        ui->quantizeButton->setEnabled(true);
    } else {
        ui->quantizeStatusLabel->setText("Quantize Your Model: No");
        ui->quantizeButton->setEnabled(false);
    }
}



void MainWindow::onOutputButtonClicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Output Folder");

    if (!folder.isEmpty()) {
        outputFolder = folder;
        ui->outputStatusLabel->setText("Output folder set: " + folder);
    } else {
        ui->outputStatusLabel->setText("No output folder selected.");
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
    process->waitForFinished();

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
    } else {
        ui->quantizeImageStatusLabel->setText("No Quantize folder selected.");
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
    
    process.waitForFinished();

    QString output(process.readAllStandardOutput());
    QString error(process.readAllStandardError());

    if (process.exitStatus() == QProcess::NormalExit && process.exitCode() == 0) {
        ui->convertStatusLabel->setText(successMessagePrefix + output);
    } else {
        ui->convertStatusLabel->setText(errorMessagePrefix + error);
    }
}

void MainWindow::onConvertButtonClicked() {
    if (ptFilePath.isEmpty() || outputFolder.isEmpty()) {
        ui->convertStatusLabel->setText("Please select a model and an output folder.");
        return;
    }

    if (modelQuantize && quantizeFolder.isEmpty()) {
        ui->convertStatusLabel->setText("Please select an Input Image folder for quantization.");
        return;
    }
    
    if(modelQuantize) {
        // Generate raw Image
        QString gen_raw_Script = "../create_inceptionv3_raws.py";
        QStringList genRawArguments;
        genRawArguments << "-s" << "640" << "-i" << quantizeFolder << "-d" << quantizeFolder;

        executePythonScript(gen_raw_Script, genRawArguments, "Generate raw image successfully. ", "Error during generating raw image: ");

        // Create image_file_list.txt
        QString gen_file_Script = "../create_file_list.py";
        QString fileName = "image_file_list.txt";
        QString fullPath = quantizeFolder + "/" + fileName;
        QStringList fileListArguments;
        fileListArguments << "-i" << quantizeFolder << "-o" << fullPath << "-e" << "*.raw";

        executePythonScript(gen_file_Script, fileListArguments, "File list generated successfully. ", "Error during generating file list: ");
    }

    

    // Convert to ONNX and DLC model
    QString pythonScript = "../convert_model.py";
    QStringList convertArguments;
    convertArguments << ptFilePath << outputFolder << (yolov5Convert ? "yolov5" : "yolov8") << (modelQuantize ? "YES" : "NO") << quantizeFolder;

    executePythonScript(pythonScript, convertArguments, "Model converted successfully. ", "Error during conversion: ");
}
