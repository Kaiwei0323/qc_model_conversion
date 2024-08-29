#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUploadButtonClicked();
    void onOutputButtonClicked();
    void onConvertButtonClicked();
    void onQuantizeButtonClicked();
    void onQuantizeChoiceChanged(const QString &text);
    void onConvertTypeChanged(const QString &text);
    
    void onUploadDLCButtonClicked();
    void onVisualizeButtonClicked();
    
    void executePythonScript(const QString &scriptPath, const QStringList &arguments, const QString &successMessagePrefix, const QString &errorMessagePrefix);

private:
    Ui::MainWindow *ui;
    QString ptFilePath;
    QString outputFolder;
    QString quantizeFolder;
    QString dlcFilePath;
    bool yolov5Convert = true;
    bool modelQuantize = false;
private:
    QProcess *process;
};
#endif // MAINWINDOW_H
