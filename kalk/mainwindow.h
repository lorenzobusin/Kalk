
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "menu.h"
#include "calculator.h"

class MainWindow : public QMainWindow {

    Q_OBJECT

private:

    QWidget* widget;
    menu* menuBar;
    calculator* calc;
    QVBoxLayout *layout;

public:

    MainWindow(QWidget *parent = 0);
    ~MainWindow() =default;

};

#endif // MAINWINDOW_H
