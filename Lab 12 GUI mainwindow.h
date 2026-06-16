#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <vector>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSolveClicked();
    void onExitClicked();

private:
    // Элементы интерфейса
    QGroupBox *groupBoxInput;
    QGroupBox *groupBoxOutput;
    
    QLineEdit *txtM;        // Количество строк
    QLineEdit *txtN;        // Количество столбцов
    QLineEdit *txtMin;      // Минимальное значение
    QLineEdit *txtMax;      // Максимальное значение
    
    QListWidget *lstOriginal;   // Исходная матрица
    QListWidget *lstResult;     // Результат
    
    QPushButton *btnSolve;
    QPushButton *btnExit;
    
    QLabel *labelStatus;
    
    // Функции для работы с данными
    int getInt(QLineEdit *edit);
    bool validateInput();
    void updateStatus(const QString &message, bool isError = false);
    
    // Функции решения задачи
    std::vector<std::vector<double>> createMatrix(int m, int n, double minVal, double maxVal);
    void processMatrix(std::vector<std::vector<double>> &matrix);
    void displayMatrix(const std::vector<std::vector<double>> &matrix, QListWidget *listWidget);
    QString formatDouble(double value);
};
