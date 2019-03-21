
#include "menu.h"

menu::menu(QMainWindow* parent){

    mainWindow = parent;

    /* FILE */

    file = parent->menuBar()->addMenu("&File");

    quit = new QAction("&Quit", this);
    file->addAction(quit);

    /* ABOUT */

    about = parent->menuBar()->addMenu("&About");

    aboutKalk = new QAction("&About Kalk", this);
    about->addAction(aboutKalk);

    /* HELP */

    help = parent->menuBar()->addMenu("&Help");
    helpKalk = new QAction("&Help Kalk", this);
    help->addAction(helpKalk);

    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    connect(helpKalk, SIGNAL(triggered(bool)), this, SLOT(openHelp()));
    connect(aboutKalk, SIGNAL(triggered(bool)), this, SLOT(openAbout()));

}

void menu::openAbout(){

    aboutTextEdit = new QTextEdit();
    aboutTextEdit->setEnabled(false);
    aboutTextEdit->setStyleSheet("border: 0px; color: black;");

    aboutTextEdit->insertHtml("<span style='font: 17px;'>"
                              "<h3>About menu:</h3>"
                              "Kalk è un progetto realizzato per il calcolo di oggetti di tipo:"
                              "<ul style='padding: 5px; list-style-type: circle;'>"
                              "<li>Colore"
                              "<li>Bandwidth"
                              "<li>Statistiche:"
                              "<li><ul style='list-style-type: square;'>"
                              "<li>Calcio"
                              "<li>Basket"
                              "</ul></li>"
                              "</ul>"
                              "<br>"
                              "<b>Colore:</b> questa classe rappresenta oggetti di tipo colore espressi nel formato RGB(Red, Green, Blue), "
                              "che si compone tre numeri compresi tra 0 e 255 per produrre come risultato finale un preciso colore.<br><br>"
                              "<b>Bandwidth:</b> gli oggetti di questa classe rappresentano delle velocità di connessione in una Internet fornite"
                              " da un ISP espresse nel formato ping, download e upload.<br><br>"
                              "<b>Statistiche:</b> gli oggetti di questa classe sono formati da una serie di informazioni statistiche relative ad una squadra"
                              " in merito ad un evento sportivo. <br><br>"
                              "<b>Calcio: </b>questi oggetti contengono informazioni statistiche piu' precise e rivolte allo sport del calcio.<br><br>"
                              "<b>Basket: </b>questi oggetti contengono informazioni statistiche piu' precise e rivolte allo sport della pallacanestro.<br><br>"
                              "</span>");

    menuAboutOk = new QPushButton("Ok");
    menuAboutOk->setFixedSize(100,50);

    connect(menuAboutOk, SIGNAL(clicked(bool)), this, SLOT(closeAbout()));

    mainWinLayout->addWidget(aboutTextEdit, 0, 0);
    mainWinLayout->addWidget(menuAboutOk, 0, 0, 1, 1, Qt::AlignRight);

}

void menu::openHelp(){

    helpTextEdit = new QTextEdit();
    helpTextEdit->setEnabled(false);
    helpTextEdit->setStyleSheet("border: 0px; color: black;");

    helpTextEdit->insertHtml("<span style='font: 17px;'>"
                             "<h3>Help menu:</h3>"
                             "<span style='color:red'>Elenco delle operazioni possibili tra singoli oggetti:</span><br>"
                             "<b>operator+ :</b> esegue la somma campo a campo tra due oggetti.<br>"
                             "<b>operator- :</b> esegue la sottrazione campo  a campo tra due oggetti.<br>"
                             "<b>operator* :</b> esegue il prodotto di ogni campo dati con un intero.<br>"
                             "<b>operator/ :</b> esegue la divisione di ogni campo dati con un intero.<br>"
                             "<b>operator% :</b> esegue il modulo di ogni campo dati con un intero.<br>"
                             "<b>operator== :</b> ritorna TRUE se i due oggetti sono uguali.<br>"
                             "<b>operator> :</b> ritorna TRUE se il primo oggetto è maggiore del secondo.<br>"
                             "<b>operator&#60; :</b> ritorna TRUE se il primo oggetto è minore del secondo.<br>"
                             "<b>operator! :</b> esegue l’inversione dei colori secondo la formula (255 - R),(255 - G), (255 - B).<br>"
                             "<span style='color:red'>Elenco delle operazioni possibili tra array di oggetti:</span><br>"
                             "<b>operator+ :</b> esegue la somma tra gli oggetti di due array che si trovano nella stessa i-esima posizione.<br>"
                             "<b>operator- :</b> esegue la sottrazione tra gli oggetti di due array che si trovano nella stessa i-esima posizione.<br>"
                             "<b>operator* :</b> esegue la moltiplicazione di ogni elemento dell’array con un intero.<br>"
                             "<b>operator/ :</b> esegue la divisione di ogni elemento dell’array con un intero.<br>"
                             "<b>operator% :</b> esegue il modulo di ogni elemento dell’array con un intero.<br>"
                             "<b>operator== :</b> ritorna TRUE se tutti gli oggetti del primo array sono uguali a tutti gli oggetti del secondo array e si trovano nella stessa posizione.<br>"
                             "<b>operator> :</b> ritorna TRUE se il totale del primo array è maggiore di quello del secondo.<br>"
                             "<b>operator&#60; :</b> ritorna TRUE se  il totale del primo array è minore di quello del secondo.<br>"
                             "<b>tot : </b>restituisce un oggetto che è la somma di tutti gli oggetti dell’array.<br>"
                             "<b>media : </b>ritorna un oggetto che è la media di tutti gli oggetti dell’array.<br>"
                             "<b>mediana : </b>ritorna l’oggetto che si trova a metà dell’array.<br>"
                             "<b>moda : </b>ritorna l’oggetto o gli oggetti che si ripetono con più frequenza dentro l’array.<br>"
                             "<b>max : </b>ritorna il massimo dell’array.<br>"
                             "<b>min :</b>ritorna il minimo dell’array.<br>"
                             "<b>ordinamentoCrescente :</b>ordina gli elementi dell’array in modo crescente.<br>"
                             "<b>ordinamentoDecrescente :</b>ordina gli elementi dell’array in modo decrescente.<br>"
                             "<b>unione :</b>esegue l’unione tra due array.<br>"
                             "<b>intersezione :</b>ritorna gli oggetti in comune tra due array.<br>"
                             "</span>");

    menuHelpOk = new QPushButton("Ok");
    menuHelpOk->setFixedSize(100,50);

    connect(menuHelpOk, SIGNAL(clicked(bool)), this, SLOT(closeHelp()));

    mainWinLayout->addWidget(helpTextEdit, 0, 0);
    mainWinLayout->addWidget(menuHelpOk, 0, 0, 1, 1, Qt::AlignRight);

}

void menu::closeAbout(){

    mainWinLayout->removeWidget(aboutTextEdit);
    mainWinLayout->removeWidget(menuAboutOk);

    delete aboutTextEdit;
    delete menuAboutOk;

}

void menu::closeHelp(){

    mainWinLayout->removeWidget(helpTextEdit);
    mainWinLayout->removeWidget(menuHelpOk);

    delete helpTextEdit;
    delete menuHelpOk;

}
