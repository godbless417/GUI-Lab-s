#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onOpenInputFileClicked();
    void onOpenOutputFileClicked();
    void onProcessClicked();
    void onClearClicked();
    void onExitClicked();

private:
    // Элементы интерфейса
    QGroupBox *groupBoxFiles;
    QGroupBox *groupBoxView;
    QGroupBox *groupBoxInfo;
    
    QLineEdit *lineEditInputPath;
    QLineEdit *lineEditOutputPath;
    
    QListWidget *listWidgetInputFile;
    QListWidget *listWidgetOutputFile;
    
    QLabel *labelLongestLineInfo;
    QLabel *labelProcessedInfo;
    
    QPushButton *btnOpenInput;
    QPushButton *btnOpenOutput;
    QPushButton *btnProcess;
    QPushButton *btnClear;
    QPushButton *btnExit;
    
    QLabel *labelStatus;
    
    // Пути к файлам
    QString inputFilePath;
    QString outputFilePath;
    
    // Функции для работы с данными
    void updateStatus(const QString &message, bool isError = false);
    void setProcessButtonState();
    void displayFileContent(const QString &filePath, QListWidget *listWidget);
    
    // Основные функции обработки (вариант 9)
    QString removeParenthesesContent(const QString &line);
    void processFiles(const QString &inputPath, const QString &outputPath, 
                      QListWidget *inputList, QListWidget *outputList,
                      QString &longestLine, int &longestLineLength);
};
