/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *uploadButton;
    QPushButton *outputButton;
    QPushButton *convertButton;
    QLabel *uploadStatusLabel;
    QLabel *outputStatusLabel;
    QLabel *convertStatusLabel;
    QComboBox *convertTypeComboBox;
    QLabel *modelStatusLabel;
    QComboBox *quantizeChoiceComboBox;
    QLabel *quantizeStatusLabel;
    QPushButton *quantizeButton;
    QLabel *quantizeImageStatusLabel;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *uploadDLCButton;
    QLabel *label_8;
    QLabel *uploadDLCStatusLabel;
    QLabel *label_10;
    QPushButton *visualizeButton;
    QLabel *visualizeStatusLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1128, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        uploadButton->setGeometry(QRect(40, 80, 351, 31));
        outputButton = new QPushButton(centralwidget);
        outputButton->setObjectName(QString::fromUtf8("outputButton"));
        outputButton->setGeometry(QRect(30, 290, 361, 41));
        convertButton = new QPushButton(centralwidget);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));
        convertButton->setGeometry(QRect(30, 500, 381, 71));
        uploadStatusLabel = new QLabel(centralwidget);
        uploadStatusLabel->setObjectName(QString::fromUtf8("uploadStatusLabel"));
        uploadStatusLabel->setGeometry(QRect(40, 120, 351, 31));
        outputStatusLabel = new QLabel(centralwidget);
        outputStatusLabel->setObjectName(QString::fromUtf8("outputStatusLabel"));
        outputStatusLabel->setGeometry(QRect(30, 330, 361, 41));
        convertStatusLabel = new QLabel(centralwidget);
        convertStatusLabel->setObjectName(QString::fromUtf8("convertStatusLabel"));
        convertStatusLabel->setGeometry(QRect(30, 580, 961, 71));
        convertTypeComboBox = new QComboBox(centralwidget);
        convertTypeComboBox->addItem(QString());
        convertTypeComboBox->addItem(QString());
        convertTypeComboBox->setObjectName(QString::fromUtf8("convertTypeComboBox"));
        convertTypeComboBox->setGeometry(QRect(40, 190, 351, 31));
        modelStatusLabel = new QLabel(centralwidget);
        modelStatusLabel->setObjectName(QString::fromUtf8("modelStatusLabel"));
        modelStatusLabel->setGeometry(QRect(40, 220, 341, 31));
        quantizeChoiceComboBox = new QComboBox(centralwidget);
        quantizeChoiceComboBox->addItem(QString());
        quantizeChoiceComboBox->addItem(QString());
        quantizeChoiceComboBox->setObjectName(QString::fromUtf8("quantizeChoiceComboBox"));
        quantizeChoiceComboBox->setGeometry(QRect(30, 390, 191, 25));
        quantizeStatusLabel = new QLabel(centralwidget);
        quantizeStatusLabel->setObjectName(QString::fromUtf8("quantizeStatusLabel"));
        quantizeStatusLabel->setGeometry(QRect(30, 420, 191, 21));
        quantizeButton = new QPushButton(centralwidget);
        quantizeButton->setObjectName(QString::fromUtf8("quantizeButton"));
        quantizeButton->setGeometry(QRect(230, 390, 221, 51));
        quantizeImageStatusLabel = new QLabel(centralwidget);
        quantizeImageStatusLabel->setObjectName(QString::fromUtf8("quantizeImageStatusLabel"));
        quantizeImageStatusLabel->setGeometry(QRect(250, 450, 201, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 20, 131, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 160, 67, 17));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 260, 67, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 370, 67, 17));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 480, 67, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(510, 50, 67, 17));
        uploadDLCButton = new QPushButton(centralwidget);
        uploadDLCButton->setObjectName(QString::fromUtf8("uploadDLCButton"));
        uploadDLCButton->setGeometry(QRect(530, 80, 151, 51));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(550, 20, 161, 17));
        uploadDLCStatusLabel = new QLabel(centralwidget);
        uploadDLCStatusLabel->setObjectName(QString::fromUtf8("uploadDLCStatusLabel"));
        uploadDLCStatusLabel->setGeometry(QRect(530, 140, 161, 17));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(510, 180, 67, 17));
        visualizeButton = new QPushButton(centralwidget);
        visualizeButton->setObjectName(QString::fromUtf8("visualizeButton"));
        visualizeButton->setGeometry(QRect(530, 210, 151, 41));
        visualizeStatusLabel = new QLabel(centralwidget);
        visualizeStatusLabel->setObjectName(QString::fromUtf8("visualizeStatusLabel"));
        visualizeStatusLabel->setGeometry(QRect(520, 260, 561, 211));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1128, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        uploadButton->setText(QCoreApplication::translate("MainWindow", "Upload .pt Model", nullptr));
        outputButton->setText(QCoreApplication::translate("MainWindow", "Choose Output Folder", nullptr));
        convertButton->setText(QCoreApplication::translate("MainWindow", "Convert Model", nullptr));
        uploadStatusLabel->setText(QCoreApplication::translate("MainWindow", "Choose a .pt Model", nullptr));
        outputStatusLabel->setText(QCoreApplication::translate("MainWindow", "Choose a output path", nullptr));
        convertStatusLabel->setText(QCoreApplication::translate("MainWindow", "Model Convert Status", nullptr));
        convertTypeComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "yolov5", nullptr));
        convertTypeComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "yolov8", nullptr));

        modelStatusLabel->setText(QCoreApplication::translate("MainWindow", "You Select: Yolov5", nullptr));
        quantizeChoiceComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Yes", nullptr));
        quantizeChoiceComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "No", nullptr));

        quantizeStatusLabel->setText(QCoreApplication::translate("MainWindow", "Quantize Your Model: Yes", nullptr));
        quantizeButton->setText(QCoreApplication::translate("MainWindow", "Choose Quantize Image", nullptr));
        quantizeImageStatusLabel->setText(QCoreApplication::translate("MainWindow", "Quantize Model Input (.jpg)", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Model Conversion", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "STEP1:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "STEP2:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "STEP3:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "STEP4:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "STEP5:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "STEP1:", nullptr));
        uploadDLCButton->setText(QCoreApplication::translate("MainWindow", "Upload .dlc Model", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Model Visualization", nullptr));
        uploadDLCStatusLabel->setText(QCoreApplication::translate("MainWindow", "Choose a .dlc Model", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "STEP2:", nullptr));
        visualizeButton->setText(QCoreApplication::translate("MainWindow", "Visualize", nullptr));
        visualizeStatusLabel->setText(QCoreApplication::translate("MainWindow", "Model Visualize Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H