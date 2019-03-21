
#ifndef MENU_H
#define MENU_H

#include <QtWidgets>

class menu : public QObject {

    Q_OBJECT

private:

    QMainWindow* mainWindow;

    QMenu *file;
    QMenu *about;
    QMenu *help;

    QAction *quit;
    QAction *aboutKalk;
    QAction *helpKalk;

    QTextEdit* aboutTextEdit;
    QTextEdit* helpTextEdit;
    QPushButton* menuAboutOk;
    QPushButton* menuHelpOk;

private slots:

    void openAbout();
    void openHelp();

    void closeAbout();
    void closeHelp();

public:

    QGridLayout* mainWinLayout;

    menu(QMainWindow* =0);

};

#endif // MENU_H
