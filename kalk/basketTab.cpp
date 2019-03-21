#include "basketTab.h"

basketTab::basketTab(QWidget *parent){

    historyFont.setPointSize(historyFont.pointSize());
    history->setFont(historyFont);

    obj1Label->setText(tr("Basket 1:"));
    obj2Label->setText(tr("Basket 2:"));
    intLabel->setText(tr("Intero:"));

    intLineEdit->setValidator(new QIntValidator(0, 1000000, this));

    m1 = new Basketball();
    m2 = new Basketball();

    obj1Button->setStyleSheet("background-color:red");
    obj2Button->setStyleSheet("background-color:red");

    obj1Button->setStatusTip("Selezionare basket 1!");
    obj1Button->setStyleSheet("background-color: red");
    obj2Button->setStatusTip("Selezionare basket 2!");
    obj2Button->setStyleSheet("background-color: red");
    intLineEdit->setStatusTip("Inserire un intero");

    buttonPlus->setStatusTip("Somma 2 statistiche di basket");
    buttonMinus->setStatusTip("Sottrai 2 statistiche di basket");
    buttonTimes->setStatusTip("Moltiplica basket 1 per l'intero");
    buttonDivision->setStatusTip("Dividi basket 1 per l'intero");
    buttonModulus->setStatusTip("Calcola il modulo di basket 1 per l'intero");
    buttonLessThan->setStatusTip("basket 1 < basket 2?");
    buttonGreaterThan->setStatusTip("basket 1 > basket 2?");
    buttonEqualsEquals->setStatusTip("basket 1 == basket 2?");

    buttonNot->setEnabled(false);
    buttonNot->setStatusTip("Il metodo 'complementare' (not) non è stato implementato per questo tipo di calcolo");

    obj1PushButton->setStatusTip("Push Basket 1 in Array 1");
    obj2PushButton->setStatusTip("Push Basket 2 in Array 2");

    basketArr1 = new Array<Basketball>(0, 20);
    basketArr2 = new Array<Basketball>(0, 20);

}

void basketTab::selector(){

    showButtons(false);

    tempButton = static_cast<QPushButton*>(sender());
    tempButton->setStyleSheet("background-color: red");

    if(tempButton == obj1Button){
        tempBask = static_cast<Basketball*>(m1);
    } else if(tempButton == obj2Button){
        tempBask = static_cast<Basketball*>(m2);
    }

    selectorLayout = new QGridLayout;

    fsLbl = new QLabel("Falli subiti: ");
    fcLbl = new QLabel("Falli commessi: ");
    mLbl = new QLabel("Minuti giocati: ");
    ppLbl = new QLabel("Palle perse: ");
    prLbl = new QLabel("Palle recuperate: ");
    passLbl = new QLabel("Passaggi: ");
    passrLbl = new QLabel("Passaggi riusciti: ");
    puntLbl = new QLabel("Punti fatti: ");
    PsLbl = new QLabel("Punti subiti: ");
    RoLbl = new QLabel("Rimbalzi offensivi: ");
    RdLbl = new QLabel("Rimbalzi difensivi: ");
    ALbl = new QLabel("Assist: ");
    SLbl = new QLabel("Stoppate: ");
    T2Lbl = new QLabel("Tiri da 2: ");
    T2sLbl = new QLabel("Tiri 2 segnati: ");
    T3Lbl = new QLabel("Tiri da 3: ");
    T3sLbl = new QLabel("Tiri 3 segnati: ");
    LLbl = new QLabel("Tiri liberi: ");
    LsLbl = new QLabel("Tiri liberi segnati: ");

    fsLbl->setMinimumWidth(300);
    fcLbl->setMinimumWidth(300);
    mLbl->setMinimumWidth(300);
    ppLbl->setMinimumWidth(300);
    prLbl->setMinimumWidth(300);
    passLbl->setMinimumWidth(300);
    passrLbl->setMinimumWidth(300);
    puntLbl->setMinimumWidth(300);
    PsLbl->setMinimumWidth(300);
    RoLbl->setMinimumWidth(300);
    RdLbl->setMinimumWidth(300);
    ALbl->setMinimumWidth(300);
    SLbl->setMinimumWidth(300);
    T2Lbl->setMinimumWidth(300);
    T2sLbl->setMinimumWidth(300);
    T3Lbl->setMinimumWidth(300);
    T3sLbl->setMinimumWidth(300);
    LLbl->setMinimumWidth(300);
    LsLbl->setMinimumWidth(300);

    puntInt = new QLineEdit(QString("%1").arg(tempBask->getPunt()));
    fsInt = new QLineEdit(QString("%1").arg(tempBask->getFs()));
    fcInt = new QLineEdit(QString("%1").arg(tempBask->getFc()));
    mInt = new QLineEdit(QString("%1").arg(tempBask->getM()));
    ppInt = new QLineEdit(QString("%1").arg(tempBask->getPp()));
    prInt = new QLineEdit(QString("%1").arg(tempBask->getPr()));
    passInt = new QLineEdit(QString("%1").arg(tempBask->getPass()));
    passrInt = new QLineEdit(QString("%1").arg(tempBask->getPassr()));
    PsInt = new QLineEdit(QString("%1").arg(tempBask->getPs()));
    RoInt = new QLineEdit(QString("%1").arg(tempBask->getRo()));
    RdInt = new QLineEdit(QString("%1").arg(tempBask->getRd()));
    AInt = new QLineEdit(QString("%1").arg(tempBask->getA()));
    SInt = new QLineEdit(QString("%1").arg(tempBask->getS()));
    T2Int = new QLineEdit(QString("%1").arg(tempBask->getT2()));
    T2sInt = new QLineEdit(QString("%1").arg(tempBask->getT2s()));
    T3Int = new QLineEdit(QString("%1").arg(tempBask->getT3()));
    T3sInt = new QLineEdit(QString("%1").arg(tempBask->getT3s()));
    LInt = new QLineEdit(QString("%1").arg(tempBask->getL()));
    LsInt = new QLineEdit(QString("%1").arg(tempBask->getLs()));

    puntInt->setValidator(new QIntValidator(0, 1000000));
    fsInt->setValidator(new QIntValidator(0, 1000000));
    fcInt->setValidator(new QIntValidator(0, 1000000));
    mInt->setValidator(new QIntValidator(0, 1000000));
    ppInt->setValidator(new QIntValidator(0, 1000000));
    prInt->setValidator(new QIntValidator(0, 1000000));
    passInt->setValidator(new QIntValidator(0, 1000000));
    passrInt->setValidator(new QIntValidator(0, 1000000));

    PsInt->setValidator(new QIntValidator(0, 1000000));
    RoInt->setValidator(new QIntValidator(0, 1000000));
    RdInt->setValidator(new QIntValidator(0, 1000000));
    AInt->setValidator(new QIntValidator(0, 1000000));
    SInt->setValidator(new QIntValidator(0, 1000000));
    T2Int->setValidator(new QIntValidator(0, 1000000));
    T2sInt->setValidator(new QIntValidator(0, 1000000));
    T3Int->setValidator(new QIntValidator(0, 1000000));
    T3sInt->setValidator(new QIntValidator(0, 1000000));
    LInt->setValidator(new QIntValidator(0, 1000000));
    LsInt->setValidator(new QIntValidator(0, 1000000));

    okButton = new QPushButton("&Ok");
    cancelButton = new QPushButton("&Cancella");

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSelector()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelSelector()));

    selectorLayout->addWidget(puntLbl, 0, 0);
    selectorLayout->addWidget(puntInt, 0, 1);
    selectorLayout->addWidget(PsLbl);
    selectorLayout->addWidget(PsInt);
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

    selectorLayout->addWidget(RoLbl);
    selectorLayout->addWidget(RoInt);
    selectorLayout->addWidget(RdLbl);
    selectorLayout->addWidget(RdInt);
    selectorLayout->addWidget(ALbl);
    selectorLayout->addWidget(AInt);
    selectorLayout->addWidget(SLbl);
    selectorLayout->addWidget(SInt);
    selectorLayout->addWidget(T2Lbl);
    selectorLayout->addWidget(T2Int);
    selectorLayout->addWidget(T2sLbl);
    selectorLayout->addWidget(T2sInt);
    selectorLayout->addWidget(T3Lbl);
    selectorLayout->addWidget(T3Int);
    selectorLayout->addWidget(T3sLbl);
    selectorLayout->addWidget(T3sInt);
    selectorLayout->addWidget(LLbl);
    selectorLayout->addWidget(LInt);
    selectorLayout->addWidget(LsLbl);
    selectorLayout->addWidget(LsInt);
    selectorLayout->addWidget(okButton);
    selectorLayout->addWidget(cancelButton);

    tabLayout->addLayout(selectorLayout, 0, 2, 5, 6, Qt::AlignVCenter);

}

void basketTab::deleteAll(){

    statsTab::deleteAll();

    delete RoLbl;
    delete RdLbl;
    delete ALbl;
    delete SLbl;
    delete T2Lbl;
    delete T2sLbl;
    delete T3Lbl;
    delete T3sLbl;
    delete LLbl;
    delete LsLbl;
    delete PsLbl;

    delete RoInt;
    delete RdInt;
    delete AInt;
    delete SInt;
    delete T2Int;
    delete T2sInt;
    delete T3Int;
    delete T3sInt;
    delete LInt;
    delete LsInt;
    delete PsInt;
}

void basketTab::okSelector(){
    tempBask->setBasketMatch(puntInt->text().toInt(), fsInt->text().toInt(), fcInt->text().toInt(), mInt->text().toInt(), ppInt->text().toInt(), prInt->text().toInt(), passInt->text().toInt(), passrInt->text().toInt(),
                             PsInt->text().toInt(), RoInt->text().toInt(), RdInt->text().toInt(), AInt->text().toInt(), SInt->text().toInt(), T2Int->text().toInt(), T2sInt->text().toInt(), T3Int->text().toInt(), T3sInt->text().toInt(), LInt->text().toInt(), LsInt->text().toInt());

    if(tempBask->getPunt() || tempBask->getFs() || tempBask->getFc() || tempBask->getM() || tempBask->getPp() || tempBask->getPr() || tempBask->getPass() ||
       tempBask->getPs() || tempBask->getRo() || tempBask->getRd() || tempBask->getA() || tempBask->getS() || tempBask->getT2() || tempBask->getT3() || tempBask->getL() )
        tempButton->setStyleSheet("background-color: green");
    else
        tempButton->setStyleSheet("background-color: red");

   cancelSelector();
}

void basketTab::checkZero(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    if(b1->getPunt() || b1->getFs() || b1->getFc() || b1->getM() || b1->getPp() || b1->getPr() || b1->getPass() ||
       b1->getPs() || b1->getRo() || b1->getRd() || b1->getA() || b1->getS() || b1->getT2() || b1->getT3() || b1->getL())
        obj1Button->setStyleSheet("background-color: green");
    else
        obj1Button->setStyleSheet("background-color: red");

    if(b2->getPunt() || b2->getFs() || b2->getFc() || b2->getM() || b2->getPp() || b2->getPr() || b2->getPass() ||
       b2->getPs() || b2->getRo() || b2->getRd() || b2->getA() || b1->getS() || b2->getT2() || b2->getT3() || b2->getL())
        obj2Button->setStyleSheet("background-color: green");
    else
        obj2Button->setStyleSheet("background-color: red");
}

void basketTab::buttonPlusClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Basketball* temp = b1;
    b1 = *b1 + *b2;
    m1 = b1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> + </td>"
                                                           "<td align='center'>" + b2->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();

}

void basketTab::buttonMinusClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    Basketball* temp = b1;
    b1 = *b1 - *b2;
    m1 = b1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> - </td>"
                                                           "<td align='center'>" + b2->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();
}

void basketTab::buttonTimesClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Basketball* temp = b1;
    b1 = *b1 * intLineEdit->text().toInt();
    m1 = b1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> * &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void basketTab::buttonDivisionClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
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

    Basketball* temp = b1;
    b1 = *b1 / intLineEdit->text().toInt();
    m1 = b1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> / &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void basketTab::buttonModulusClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
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

    Basketball* temp = b1;
    b1 = *b1 % intLineEdit->text().toInt();
    m1 = b1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> % &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void basketTab::buttonLessThanClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    if(*b1 < *b2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void basketTab::buttonGreaterThanClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*b1 > *b2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
}

void basketTab::buttonEqualsEqualsClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    Basketball* b2 = static_cast<Basketball*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    if (*b1 == *b2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + b1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + b2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
}

void basketTab::buttonNotClicked(){}

void basketTab::obj1PushButtonClicked(){
    Basketball* b1 = static_cast<Basketball*>(m1);
    basketArr1->push_back(*b1);
    updateArray(basketArr1);

}

void basketTab::obj2PushButtonClicked(){
    Basketball* b2 = static_cast<Basketball*>(m2);
    basketArr2->push_back(*b2);
    updateArray(basketArr2);

}

void basketTab::obj1PopButtonClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 1 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 1!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Basketball tempBasket = basketArr1->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::obj2PopButtonClicked(){

    if(!basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 2 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 2!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Basketball tempBasket = basketArr2->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr2);
    }

}

void basketTab::obj1ClearButtonClicked(){

    while(basketArr1->getSize())
        basketArr1->pop_back();
    updateArray(basketArr1);

}

void basketTab::obj2ClearButtonClicked(){

    while(basketArr2->getSize())
        basketArr2->pop_back();
    updateArray(basketArr2);

}

void basketTab::arrButtonPlusClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Somma Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += printArray(basketArr1);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;+&#160;</td>"
                  "<td align='center' >";
        insert += printArray(basketArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *basketArr1 = *basketArr1 + *basketArr2;
        insert += printArray(basketArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonMinusClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sottrarre inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Sottrai Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(basketArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;-&#160;</td>"
                  "<td align='center' >";
        insert += printArray(basketArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *basketArr1 = *basketArr1 - *basketArr2;
        insert += printArray(basketArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonTimesClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di moltiplicare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(basketArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;*&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *basketArr1 = *basketArr1 * intLineEdit->text().toInt();
        insert += printArray(basketArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonDivisionClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
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
        insert += (printArray(basketArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;/&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *basketArr1 = *basketArr1 / intLineEdit->text().toInt();
        insert += printArray(basketArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonModulusClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
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
        insert += (printArray(basketArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;%&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *basketArr1 = *basketArr1 % intLineEdit->text().toInt();
        insert += printArray(basketArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*basketArr1 < *basketArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void basketTab::arrButtonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*basketArr1 > *basketArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#62; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void basketTab::arrButtonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*basketArr1 == *basketArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void basketTab::arrButtonTotClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la somma degli elementi di Array 1");
        Basketball tempBasket = basketArr1->tot();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Totale Array 1: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonMediaClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la media inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la media degli elementi di Array 1");
        Basketball tempBasket = basketArr1->media();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Media Array 1: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonMedianaClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la mediana inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la mediana degli elementi di Array 1");
        Basketball tempBasket = basketArr1->mediana();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Mediana Array 1: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonModaClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la moda inserire almeno un elemento in Array 1!");
    else{

        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la moda degli elementi di Array 1");

        Array<Basketball> tempBasket = basketArr1->moda();

        QString insert = "<table><tr>"
                         "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Moda Array 1: </td>"
                         "<td align='center'>";
        insert += printArray(&tempBasket);
        insert += "</td></tr></table><hr>";

        history->insertHtml(insert);

        history->insertHtml(QString::fromStdString(std::string("<br></div>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonMaxClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il massimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il massimo degli elementi di Array 1");
        Basketball tempBasket = basketArr1->max();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Massimo Array 1: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonMinClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il minimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il minimo degli elementi di Array 1");
        Basketball tempBasket = basketArr1->min();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Minimo Array 1: </td>"
                                                               "<td align='center'>"+ tempBasket.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void basketTab::arrButtonOrdinamentoCrescenteClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo crescente");
        basketArr1->ordinamentoCrescente();
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonOrdinamentoDecrescenteClicked(){

    if(!basketArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo decrescente");
        basketArr1->ordinamentoDecrescente();
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonUnioneClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di unire inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
        *basketArr1 = basketArr1->unione(*basketArr2);
        updateArray(basketArr1);
    }

}

void basketTab::arrButtonIntersezioneClicked(){

    if(!basketArr1->getSize() && !basketArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di intersecare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");
        *basketArr1 = basketArr1->intersezione(*basketArr2);
        updateArray(basketArr1);
    }

}

QString basketTab::printArray(Array<Basketball>* basketArr) const{

    std::string arrString;

    if(!basketArr->getSize()){
        arrString += "{ Ø }";
    }else{
        arrString += basketArr->getObj(0).print();
        for(int i = 1; i < basketArr->getSize(); ++i){
            arrString += "<hr>";
            arrString += basketArr->getObj(i).print();
        }
    }

    return QString::fromStdString(arrString);

}

void basketTab::updateArray(Array<Basketball>* basketArr) const{

    QTextEdit* tempLine;

    if(basketArr == basketArr1)
        tempLine = arr1TextEdit;
    else
        tempLine = arr2TextEdit;

    tempLine->clear();

    std::string arrString = "{";

    if(basketArr->getSize()){
        arrString += " 🏀 [0] ";
        for(int i = 1; i < basketArr->getSize(); ++i){
            arrString += " - 🏀 [";
            arrString += std::to_string(i);
            arrString += "] ";
        }
    } else {
        arrString += " Ø ";
    }

    arrString += "}";

    tempLine->setText(QString::fromStdString(arrString));

}

