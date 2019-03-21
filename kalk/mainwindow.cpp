
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

    setWindowTitle("Kalk - Your personal Multitype calculator");

    /* DIMENSIONS */
    setMinimumSize(1400,700);
    setMaximumWidth(700);

    /* MENU */
    widget = new QWidget;
    setCentralWidget(widget);
    menuBar = new menu(this);

    calc = new calculator(this);

    /* LAYOUT */
    layout = new QVBoxLayout;
    layout->setMargin(1);
    layout->addWidget(calc);
    widget->setLayout(layout);

    menuBar->mainWinLayout = calc->getLayout();

    /* STATUS BAR */
    statusBar()->showMessage("Benvenuto!");

}
