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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onProcessClicked();
    void onClearClicked();
    void onExitClicked();

private:
    // Элементы интерфейса
    QGroupBox *groupBoxInput;
    QGroupBox *groupBoxOutput;
    QGroupBox *groupBoxExample;
    
    QTextEdit *textEditInput;      // Поле для ввода строки
    QLineEdit *lineEditResult;      // Поле для вывода результата
    QLabel *labelStatus;            // Статусная строка
    
    QPushButton *btnProcess;        // Кнопка "Обработать"
    QPushButton *btnClear;          // Кнопка "Очистить"
    QPushButton *btnExit;           // Кнопка "Выход"
    
    QLabel *labelExample;           // Примеры для демонстрации
    
    // Функции для работы с данными
    void updateStatus(const QString &message, bool isError = false);
    QString removeParenthesesContent(const QString &input);
    bool validateInput(const QString &input);
};
