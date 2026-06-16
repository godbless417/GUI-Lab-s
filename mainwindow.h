#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTextEdit>
#include <QListWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSolveClicked();
    void onClearClicked();
    void onExitClicked();

private:
    void setupUI();
    void updateStatus(const QString& message, bool isError = false);
    
    // UI Elements
    QTextEdit* textEditInput;
    QListWidget* listWidgetResult;
    QPushButton* pushButtonSolve;
    QPushButton* pushButtonClear;
    QPushButton* pushButtonExit;
    QLabel* labelStatus;
};
