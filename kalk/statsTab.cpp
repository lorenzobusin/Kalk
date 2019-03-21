
#include "statsTab.h"

statsTab::statsTab(QWidget *parent) : tab(parent){

    historyFont.setPointSize(historyFont.pointSize() + 2);
    history->setFont(historyFont);

    obj1Label->setText(tr("Statistiche 1:"));
    obj2Label->setText(tr("Statistiche 2:"));
    intLabel->setText(tr("Intero:"));

    intLineEdit->setValidator(new QIntValidator(0, 1000000, this));

    m1 = new Match_stats();
    m2 = new Match_stats();

    obj1Button->setStyleSheet("background-color:red");
    obj2Button->setStyleSheet("background-color:red");

    obj1Button->setStatusTip("Selezionare statistiche 1!");
    obj1Button->setStyleSheet("background-color: red");
    obj2Button->setStatusTip("Selezionare statistiche 2!");
    obj2Button->setStyleSheet("background-color: red");
    intLineEdit->setStatusTip("Inserire un intero");

    buttonPlus->setStatusTip("Somma 2 statistiche");
    buttonMinus->setStatusTip("Sottrai 2 statistiche");
    buttonTimes->setStatusTip("Moltiplica Statistica 1 per l'intero");
    buttonDivision->setStatusTip("Dividi Statistica 1 per l'intero");
    buttonModulus->setStatusTip("Calcola il modulo di Statistica 1 per l'intero");
    buttonLessThan->setStatusTip("Statistica 1 < Statistica 2?");
    buttonGreaterThan->setStatusTip("Statistica 1 > Statistica 2?");
    buttonEqualsEquals->setStatusTip("Statistica 1 == Statistica 2?");

    buttonNot->setEnabled(false);
    buttonNot->setStatusTip("Il metodo 'complementare' (not) non è stato implementato per questo tipo di calcolo");

    obj1PushButton->setStatusTip("Push Statistica 1 in Array 1");
    obj2PushButton->setStatusTip("Push Statistica 2 in Array 2");

    statsArr1 = new Array<Match_stats>(0, 20);
    statsArr2 = new Array<Match_stats>(0, 20);

}

void statsTab::selector(){

    showButtons(false);

    tempButton = static_cast<QPushButton*>(sender());
    tempButton->setStyleSheet("background-color: red");

    if(tempButton == obj1Button){
        tempMatch = m1;
    } else if(tempButton == obj2Button){
        tempMatch = m2;
    }

    selectorLayout = new QGridLayout;

    puntLbl = new QLabel("Punteggio: ");
    fsLbl = new QLabel("Falli subiti: ");
    fcLbl = new QLabel("Falli commessi: ");
    mLbl = new QLabel("Minuti giocati: ");
    ppLbl = new QLabel("Palle perse: ");
    prLbl = new QLabel("Palle recuperate: ");
    passLbl = new QLabel("Passaggi: ");
    passrLbl = new QLabel("Passaggi riusciti: ");

    puntLbl->setMinimumWidth(300);
    fsLbl->setMinimumWidth(300);
    fcLbl->setMinimumWidth(300);
    mLbl->setMinimumWidth(300);
    ppLbl->setMinimumWidth(300);
    prLbl->setMinimumWidth(300);
    passLbl->setMinimumWidth(300);
    passrLbl->setMinimumWidth(300);

    puntInt = new QLineEdit(QString("%1").arg(tempMatch->getPunt()));
    fsInt = new QLineEdit(QString("%1").arg(tempMatch->getFs()));
    fcInt = new QLineEdit(QString("%1").arg(tempMatch->getFc()));
    mInt = new QLineEdit(QString("%1").arg(tempMatch->getM()));
    ppInt = new QLineEdit(QString("%1").arg(tempMatch->getPp()));
    prInt = new QLineEdit(QString("%1").arg(tempMatch->getPr()));
    passInt = new QLineEdit(QString("%1").arg(tempMatch->getPass()));
    passrInt = new QLineEdit(QString("%1").arg(tempMatch->getPassr()));

    puntInt->setValidator(new QIntValidator(0, 1000000));
    fsInt->setValidator(new QIntValidator(0, 1000000));
    fcInt->setValidator(new QIntValidator(0, 1000000));
    mInt->setValidator(new QIntValidator(0, 1000000));
    ppInt->setValidator(new QIntValidator(0, 1000000));
    prInt->setValidator(new QIntValidator(0, 1000000));
    passInt->setValidator(new QIntValidator(0, 1000000));
    passrInt->setValidator(new QIntValidator(0, 1000000));

    okButton = new QPushButton("&Ok");
    cancelButton = new QPushButton("&Cancella");

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSelector()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelSelector()));

    selectorLayout->addWidget(puntLbl, 0, 0);
    selectorLayout->addWidget(puntInt, 0, 1);
    selectorLayout->addWidget(fsLbl);
    selectorLayout->addWidget(fsInt);
    selectorLayout->addWidget(fcLbl);
    selectorLayout->addWidget(fcInt);
    selectorLayout->addWidget(mLbl);
    selectorLayout->addWidget(mInt);
    selectorLayout->addWidget(ppLbl);
    selectorLayout->addWidget(ppInt);
    selectorLayout->addWidget(prLbl);
    selectorLayout->addWidget(prInt);
    selectorLayout->addWidget(passLbl);
    selectorLayout->addWidget(passInt);
    selectorLayout->addWidget(passrLbl);
    selectorLayout->addWidget(passrInt);
    selectorLayout->addWidget(okButton);
    selectorLayout->addWidget(cancelButton);

    tabLayout->addLayout(selectorLayout, 0, 2, 5, 6, Qt::AlignVCenter);
}

void statsTab::deleteAll(){

    delete selectorLayout;
    delete puntLbl;
    delete fsLbl;
    delete fcLbl;
    delete mLbl;
    delete ppLbl;
    delete prLbl;
    delete passLbl;
    delete passrLbl;

    delete puntInt;
    delete fsInt;
    delete fcInt;
    delete mInt;
    delete ppInt;
    delete prInt;
    delete passInt;
    delete passrInt;

    delete okButton;
    delete cancelButton;
}

void statsTab::okSelector(){
    tempMatch->setMatch(puntInt->text().toInt(), fsInt->text().toInt(), fcInt->text().toInt(), mInt->text().toInt(), ppInt->text().toInt(), prInt->text().toInt(), passInt->text().toInt(), passrInt->text().toInt());

    if(tempMatch->getPunt() || tempMatch->getFs() || tempMatch->getFc() || tempMatch->getM() || tempMatch->getPp() || tempMatch->getPr() || tempMatch->getPass())
        tempButton->setStyleSheet("background-color: green");
    else
        tempButton->setStyleSheet("background-color: red");

    cancelSelector();
}

void statsTab::checkZero(){

    if(m1->getPunt() || m1->getFs() || m1->getFc() || m1->getM() || m1->getPp() || m1->getPr() || m1->getPass())
        obj1Button->setStyleSheet("background-color: green");
    else
        obj1Button->setStyleSheet("background-color: red");

    if(m2->getPunt() || m2->getFs() || m2->getFc() || m2->getM() || m2->getPp() || m2->getPr() || m2->getPass())
        obj2Button->setStyleSheet("background-color: green");
    else
        obj2Button->setStyleSheet("background-color: red");
}

void statsTab::buttonPlusClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Match_stats* temp = m1;
    m1 = *m1 + *m2;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> + </td>"
                                                           "<td align='center'>" + m2->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + m1->print_basic() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();

}

void statsTab::buttonMinusClicked(){
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Match_stats* temp = m1;
    m1 = *m1 - *m2;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> - </td>"
                                                           "<td align='center'>" + m2->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + m1->print_basic() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();
}

void statsTab::buttonTimesClicked(){
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Match_stats* temp = m1;
    m1 = *m1 * intLineEdit->text().toInt();

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> * &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + m1->print_basic() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void statsTab::buttonDivisionClicked(){

    if(!intLineEdit->text().toInt()){
        history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                            "<tr><td><br>"
                            "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                            "<br></td></tr>"
                            "</table>");
        intLineEdit->setText("1");
    }

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Match_stats* temp = m1;
    m1 = *m1 / intLineEdit->text().toInt();

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> / &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + m1->print_basic() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void statsTab::buttonModulusClicked(){

    if(!intLineEdit->text().toInt()){
        history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                            "<tr><td><br>"
                            "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                            "<br></td></tr>"
                            "</table>");
        intLineEdit->setText("1");
    }
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Match_stats* temp = m1;
    m1 = *m1 % intLineEdit->text().toInt();

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print_basic() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> % &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + m1->print_basic() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void statsTab::buttonLessThanClicked(){
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    if(*m1 < *m2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void statsTab::buttonGreaterThanClicked(){
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*m1 > *m2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void statsTab::buttonEqualsEqualsClicked(){
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if (*m1 == *m2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + m1->print_basic() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + m2->print_basic()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
}

void statsTab::buttonNotClicked(){}

void statsTab::obj1PushButtonClicked(){

    statsArr1->push_back(*m1);
    updateArray(statsArr1);

}

void statsTab::obj2PushButtonClicked(){

    statsArr2->push_back(*m2);
    updateArray(statsArr2);

}

void statsTab::obj1PopButtonClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 1 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 1!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Match_stats tempStats = statsArr1->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::obj2PopButtonClicked(){

    if(!statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 2 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 2!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Match_stats tempStats = statsArr2->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr2);
    }

}

void statsTab::obj1ClearButtonClicked(){

    while(statsArr1->getSize())
        statsArr1->pop_back();
    updateArray(statsArr1);

}

void statsTab::obj2ClearButtonClicked(){

    while(statsArr2->getSize())
        statsArr2->pop_back();
    updateArray(statsArr2);

}

void statsTab::arrButtonPlusClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Somma Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(statsArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;+&#160;</td>"
                  "<td align='center' >";
        insert += printArray(statsArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *statsArr1 = *statsArr1 + *statsArr2;
        insert += printArray(statsArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonMinusClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sottrarre inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Sottrai Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(statsArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;-&#160;</td>"
                  "<td align='center' >";
        insert += printArray(statsArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *statsArr1 = *statsArr1 - *statsArr2;
        insert += printArray(statsArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonTimesClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di moltiplicare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(statsArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;*&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *statsArr1 = *statsArr1 * intLineEdit->text().toInt();
        insert += printArray(statsArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonDivisionClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        if(!intLineEdit->text().toInt()){
            history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                                "<tr><td><br>"
                                "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                                "<br></td></tr>"
                                "</table>");
            intLineEdit->setText("1");
        }
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(statsArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;/&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *statsArr1 = *statsArr1 / intLineEdit->text().toInt();
        insert += printArray(statsArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonModulusClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        if(!intLineEdit->text().toInt()){
            history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                                "<tr><td><br>"
                                "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                                "<br></td></tr>"
                                "</table>");
            intLineEdit->setText("1");
        }
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(statsArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;%&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *statsArr1 = *statsArr1 % intLineEdit->text().toInt();
        insert += printArray(statsArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*statsArr1 < *statsArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void statsTab::arrButtonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*statsArr1 > *statsArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#62; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void statsTab::arrButtonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*statsArr1 == *statsArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void statsTab::arrButtonTotClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la somma degli elementi di Array 1");
        Match_stats tempStats = statsArr1->tot();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Totale Array 1: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonMediaClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la media inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la media degli elementi di Array 1");
        Match_stats tempStats = statsArr1->media();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Media Array 1: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonMedianaClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la mediana inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la mediana degli elementi di Array 1");
        Match_stats tempStats = statsArr1->mediana();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Mediana Array 1: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonModaClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la moda inserire almeno un elemento in Array 1!");
    else{

        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la moda degli elementi di Array 1");

        Array<Match_stats> tempStats = statsArr1->moda();

        QString insert = "<table><tr>"
                         "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Moda Array 1: </td>"
                         "<td align='center'>";
        insert += printArray(&tempStats);
        insert += "</td></tr></table><hr>";

        history->insertHtml(insert);

        history->insertHtml(QString::fromStdString(std::string("<br></div>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonMaxClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il massimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il massimo degli elementi di Array 1");
        Match_stats tempStats = statsArr1->max();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Massimo Array 1: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonMinClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il minimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il minimo degli elementi di Array 1");
        Match_stats tempStats = statsArr1->min();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Minimo Array 1: </td>"
                                                               "<td align='center'>"+ tempStats.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void statsTab::arrButtonOrdinamentoCrescenteClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo crescente");
        statsArr1->ordinamentoCrescente();
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonOrdinamentoDecrescenteClicked(){

    if(!statsArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo decrescente");
        statsArr1->ordinamentoDecrescente();
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonUnioneClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di unire inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
        *statsArr1 = statsArr1->unione(*statsArr2);
        updateArray(statsArr1);
    }

}

void statsTab::arrButtonIntersezioneClicked(){

    if(!statsArr1->getSize() && !statsArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di intersecare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");
        *statsArr1 = statsArr1->intersezione(*statsArr2);
        updateArray(statsArr1);
    }

}

QString statsTab::printArray(Array<Match_stats>* statsArr) const{

    std::string arrString;

    if(!statsArr->getSize()){
        arrString += "{ Ø }";
    }else{
        arrString += statsArr->getObj(0).print();
        for(int i = 1; i < statsArr->getSize(); ++i){
            arrString += "<hr>";
            arrString += statsArr->getObj(i).print();
        }
    }

    return QString::fromStdString(arrString);

}

void statsTab::updateArray(Array<Match_stats>* statsArr) const{

    QTextEdit* tempLine;

    if(statsArr == statsArr1)
        tempLine = arr1TextEdit;
    else
        tempLine = arr2TextEdit;

    tempLine->clear();

    std::string arrString = "{";

    if(statsArr->getSize()){
        arrString += " ✎ [0] ";
        for(int i = 1; i < statsArr->getSize(); ++i){
            arrString += " - ✎ [";
            arrString += std::to_string(i);
            arrString += "] ";
        }
    } else {
        arrString += " Ø ";
    }

    arrString += "}";

    tempLine->setText(QString::fromStdString(arrString));

}

