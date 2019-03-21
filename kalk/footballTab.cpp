#include "footballTab.h"

footballTab::footballTab(QWidget *parent){

    historyFont.setPointSize(historyFont.pointSize());
    history->setFont(historyFont);

    obj1Label->setText(tr("Calcio 1:"));
    obj2Label->setText(tr("Calcio 2:"));
    intLabel->setText(tr("Intero:"));

    intLineEdit->setValidator(new QIntValidator(0, 1000000, this));

    m1 = new Football();
    m2 = new Football();

    obj1Button->setStyleSheet("background-color:red");
    obj2Button->setStyleSheet("background-color:red");

    obj1Button->setStatusTip("Selezionare calcio 1!");
    obj1Button->setStyleSheet("background-color: red");
    obj2Button->setStatusTip("Selezionare calcio 2!");
    obj2Button->setStyleSheet("background-color: red");
    intLineEdit->setStatusTip("Inserire un intero");

    buttonPlus->setStatusTip("Somma 2 statistiche di calcio");
    buttonMinus->setStatusTip("Sottrai 2 statistiche di calcio");
    buttonTimes->setStatusTip("Moltiplica calcio 1 per l'intero");
    buttonDivision->setStatusTip("Dividi calcio 1 per l'intero");
    buttonModulus->setStatusTip("Calcola il modulo di calcio 1 per l'intero");
    buttonLessThan->setStatusTip("calcio 1 < calcio 2?");
    buttonGreaterThan->setStatusTip("calcio 1 > calcio 2?");
    buttonEqualsEquals->setStatusTip("Calcio 1 == calcio 2?");

    buttonNot->setEnabled(false);
    buttonNot->setStatusTip("Il metodo 'complementare' (not) non è stato implementato per questo tipo di calcolo");

    obj1PushButton->setStatusTip("Push Calcio 1 in Array 1");
    obj2PushButton->setStatusTip("Push Calcio 2 in Array 2");

    footArr1 = new Array<Football>(0,20);
    footArr2 = new Array<Football>(0,20);

}

void footballTab::selector(){

    showButtons(false);

    tempButton = static_cast<QPushButton*>(sender());
    tempButton->setStyleSheet("background-color: red");

    if(tempButton == obj1Button){
        tempFoot = static_cast<Football*>(m1);
    } else if(tempButton == obj2Button){
        tempFoot = static_cast<Football*>(m2);
    }

    selectorLayout = new QGridLayout;

    fsLbl = new QLabel("Falli subiti: ");
    fcLbl = new QLabel("Falli commessi: ");
    mLbl = new QLabel("Minuti giocati: ");
    ppLbl = new QLabel("Palle perse: ");
    prLbl = new QLabel("Palle recuperate: ");
    passLbl = new QLabel("Passaggi: ");
    passrLbl = new QLabel("Passaggi riusciti: ");
    PpallaLbl = new QLabel("Possesso palla: ");
    puntLbl = new QLabel("Gol fatti: ");
    GsLbl = new QLabel("Gol subiti: ");
    CLbl = new QLabel("Calci d'angolo: ");
    CrossLbl = new QLabel("Cross: ");
    RimLbl = new QLabel("Rimesse laterali: ");
    RLbl = new QLabel("Rigori: ");
    TLbl = new QLabel("Tiri: ");
    TportaLbl = new QLabel("Tiri in porta: ");
    FLbl = new QLabel("Fuorigioco: ");
    CgLbl = new QLabel("Cartellini gialli: ");
    CrLbl = new QLabel("Cartellini rossi: ");

    fsLbl->setMinimumWidth(300);
    fcLbl->setMinimumWidth(300);
    mLbl->setMinimumWidth(300);
    ppLbl->setMinimumWidth(300);
    prLbl->setMinimumWidth(300);
    passLbl->setMinimumWidth(300);
    passrLbl->setMinimumWidth(300);
    PpallaLbl->setMinimumWidth(300);
    puntLbl->setMinimumWidth(300);
    GsLbl->setMinimumWidth(300);
    CLbl->setMinimumWidth(300);
    CrossLbl->setMinimumWidth(300);
    RimLbl->setMinimumWidth(300);
    RLbl->setMinimumWidth(300);
    TLbl->setMinimumWidth(300);
    TportaLbl->setMinimumWidth(300);
    FLbl->setMinimumWidth(300);
    CgLbl->setMinimumWidth(300);
    CrLbl->setMinimumWidth(300);

    puntInt = new QLineEdit(QString("%1").arg(tempFoot->getPunt()));
    fsInt = new QLineEdit(QString("%1").arg(tempFoot->getFs()));
    fcInt = new QLineEdit(QString("%1").arg(tempFoot->getFc()));
    mInt = new QLineEdit(QString("%1").arg(tempFoot->getM()));
    ppInt = new QLineEdit(QString("%1").arg(tempFoot->getPp()));
    prInt = new QLineEdit(QString("%1").arg(tempFoot->getPr()));
    passInt = new QLineEdit(QString("%1").arg(tempFoot->getPass()));
    passrInt = new QLineEdit(QString("%1").arg(tempFoot->getPassr()));
    PpallaInt = new QLineEdit(QString("%1").arg(tempFoot->getPpalla()));
    GsInt = new QLineEdit(QString("%1").arg(tempFoot->getGs()));
    CInt = new QLineEdit(QString("%1").arg(tempFoot->getC()));
    CrossInt = new QLineEdit(QString("%1").arg(tempFoot->getCr()));
    RimInt = new QLineEdit(QString("%1").arg(tempFoot->getRim()));
    RInt = new QLineEdit(QString("%1").arg(tempFoot->getR()));
    TInt = new QLineEdit(QString("%1").arg(tempFoot->getT()));
    TportaInt = new QLineEdit(QString("%1").arg(tempFoot->getTporta()));
    FInt = new QLineEdit(QString("%1").arg(tempFoot->getF()));
    CgInt = new QLineEdit(QString("%1").arg(tempFoot->getCg()));
    CrInt = new QLineEdit(QString("%1").arg(tempFoot->getCr()));

    puntInt->setValidator(new QIntValidator(0, 1000000));
    fsInt->setValidator(new QIntValidator(0, 1000000));
    fcInt->setValidator(new QIntValidator(0, 1000000));
    mInt->setValidator(new QIntValidator(0, 1000000));
    ppInt->setValidator(new QIntValidator(0, 1000000));
    prInt->setValidator(new QIntValidator(0, 1000000));
    passInt->setValidator(new QIntValidator(0, 1000000));
    passrInt->setValidator(new QIntValidator(0, 1000000));

    PpallaInt->setValidator(new QIntValidator(0, 100));
    GsInt->setValidator(new QIntValidator(0, 1000000));
    CInt->setValidator(new QIntValidator(0, 1000000));
    CrossInt->setValidator(new QIntValidator(0, 1000000));
    RimInt->setValidator(new QIntValidator(0, 1000000));
    RInt->setValidator(new QIntValidator(0, 1000000));
    TInt->setValidator(new QIntValidator(0, 1000000));
    TportaInt->setValidator(new QIntValidator(0, 1000000));
    FInt->setValidator(new QIntValidator(0, 1000000));
    CgInt->setValidator(new QIntValidator(0, 1000000));
    CrInt->setValidator(new QIntValidator(0, 1000000));

    okButton = new QPushButton("&Ok");
    cancelButton = new QPushButton("&Cancella");

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSelector()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelSelector()));

    selectorLayout->addWidget(puntLbl, 0, 0);
    selectorLayout->addWidget(puntInt, 0, 1);
    selectorLayout->addWidget(GsLbl);
    selectorLayout->addWidget(GsInt);
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

    selectorLayout->addWidget(PpallaLbl);
    selectorLayout->addWidget(PpallaInt);
    selectorLayout->addWidget(CLbl);
    selectorLayout->addWidget(CInt);
    selectorLayout->addWidget(CrossLbl);
    selectorLayout->addWidget(CrossInt);
    selectorLayout->addWidget(RimLbl);
    selectorLayout->addWidget(RimInt);
    selectorLayout->addWidget(RLbl);
    selectorLayout->addWidget(RInt);
    selectorLayout->addWidget(TLbl);
    selectorLayout->addWidget(TInt);
    selectorLayout->addWidget(TportaLbl);
    selectorLayout->addWidget(TportaInt);
    selectorLayout->addWidget(FLbl);
    selectorLayout->addWidget(FInt);
    selectorLayout->addWidget(CgLbl);
    selectorLayout->addWidget(CgInt);
    selectorLayout->addWidget(CrLbl);
    selectorLayout->addWidget(CrInt);
    selectorLayout->addWidget(okButton);
    selectorLayout->addWidget(cancelButton);

    tabLayout->addLayout(selectorLayout, 0, 2, 5, 6, Qt::AlignVCenter);

}

void footballTab::deleteAll(){

    statsTab::deleteAll();

    delete PpallaLbl;
    delete CLbl;
    delete CrossLbl;
    delete RimLbl;
    delete RLbl;
    delete TLbl;
    delete TportaLbl;
    delete FLbl;
    delete CgLbl;
    delete CrLbl;
    delete GsLbl;

    delete PpallaInt;
    delete CInt;
    delete CrossInt;
    delete RimInt;
    delete RInt;
    delete TInt;
    delete TportaInt;
    delete FInt;
    delete CgInt;
    delete CrInt;
    delete GsInt;

}

void footballTab::okSelector(){
    tempFoot->setFootballMatch(puntInt->text().toInt(), fsInt->text().toInt(), fcInt->text().toInt(), mInt->text().toInt(), ppInt->text().toInt(), prInt->text().toInt(), passInt->text().toInt(), passrInt->text().toInt(),
                                PpallaInt->text().toInt(), GsInt->text().toInt(), CInt->text().toInt(), CrossInt->text().toInt(), RimInt->text().toInt(), RInt->text().toInt(), TInt->text().toInt(), TportaInt->text().toInt(), FInt->text().toInt(), CgInt->text().toInt(), CrInt->text().toInt());

    if(tempFoot->getPunt() || tempFoot->getFs() || tempFoot->getFc() || tempFoot->getM() || tempFoot->getPp() || tempFoot->getPr() || tempFoot->getPass() || tempFoot->getPassr() ||
       tempFoot->getPpalla() || tempFoot->getGs() || tempFoot->getC() || tempFoot->getCross() || tempFoot->getRim() || tempFoot->getR() || tempFoot->getT() || tempFoot->getF() || tempFoot->getCg() || tempFoot->getCr() )
        tempButton->setStyleSheet("background-color: green");
    else
        tempButton->setStyleSheet("background-color: red");

   cancelSelector();
}

void footballTab::checkZero(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m2);
    if(f1->getPunt() || f1->getFs() || f1->getFc() || f1->getM() || f1->getPp() || f1->getPr() || f1->getPass() ||
       f1->getGs() || f1->getPpalla() || f1->getC() || f1->getCross() || f1->getRim() || f1->getR() || f1->getT() || f1->getF() || f1->getCg() || f1->getCr())
        obj1Button->setStyleSheet("background-color: green");
    else
        obj1Button->setStyleSheet("background-color: red");

    if(f2->getPunt() || f2->getFs() || f2->getFc() || f2->getM() || f2->getPp() || f2->getPr() || f2->getPass() ||
       f2->getGs() || f2->getPpalla() || f2->getC() || f2->getCross() || f1->getRim() || f2->getR() || f2->getT() || f2->getF() || f2->getCg() || f2->getCr())
        obj2Button->setStyleSheet("background-color: green");
    else
        obj2Button->setStyleSheet("background-color: red");
}

void footballTab::buttonPlusClicked(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Football* temp = f1;
    f1 = *f1 + *f2;
    m1 = f1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> + </td>"
                                                           "<td align='center'>" + f2->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + f1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;


    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();

}

void footballTab::buttonMinusClicked(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m2);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    Football* temp = f1;
    f1 = *f1 - *f2;
    m1 = f1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> - </td>"
                                                           "<td align='center'>" + f2->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + f1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>")));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();
}

void footballTab::buttonTimesClicked(){
    Football* f1 = static_cast<Football*>(m1);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Football* temp = f1;
    f1 = *f1 * intLineEdit->text().toInt();
    m1 = f1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> * &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + f1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void footballTab::buttonDivisionClicked(){
    Football* f1 = static_cast<Football*>(m1);
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

    Football* temp = f1;
    f1 = *f1 / intLineEdit->text().toInt();
    m1 = f1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> / &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + f1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void footballTab::buttonModulusClicked(){
    Football* f1 = static_cast<Football*>(m1);
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

    Football* temp = f1;
    f1 = *f1 % intLineEdit->text().toInt();
    m1 = f1;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> % &nbsp;&nbsp;</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text().toStdString()) +  "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'>&nbsp;&nbsp; = </td>"
                                                           "<td align='center' style='width:100%'>" + f1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();
}

void footballTab::buttonLessThanClicked(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m1);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    if(*f1 < *f2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#60; </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void footballTab::buttonGreaterThanClicked(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m1);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*f1 > *f2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> &#62; </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
}

void footballTab::buttonEqualsEqualsClicked(){
    Football* f1 = static_cast<Football*>(m1);
    Football* f2 = static_cast<Football*>(m1);
    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);


    if (*f1 == *f2)
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:green'>✔</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));
    else
        history->insertHtml(QString::fromStdString(std::string("<table>"
                                                               "<tr>"
                                                               "<td align='center'>" + f1->print() + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> == </td>"
                                                               "<td align='center'>" + f2->print()) + "</td>"
                                                               "<td style='font-size: 35px; vertical-align:middle' align='center'> <span style='color:red'>✕</span> </td>"
                                                               "</tr>"
                                                               "</table>"
                                                               "<hr>"));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
}

void footballTab::buttonNotClicked(){}

void footballTab::obj1PushButtonClicked(){
    Football* f1 = static_cast<Football*>(m1);

    footArr1->push_back(*f1);
    updateArray(footArr1);

}

void footballTab::obj2PushButtonClicked(){
    Football* f2 = static_cast<Football*>(m1);
    footArr2->push_back(*f2);
    updateArray(footArr2);

}

void footballTab::obj1PopButtonClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 1 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 1!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Football tempFoot = footArr1->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::obj2PopButtonClicked(){

    if(!footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 2 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 2!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Football tempFoot = footArr2->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr2);
    }

}

void footballTab::obj1ClearButtonClicked(){

    while(footArr1->getSize())
        footArr1->pop_back();
    updateArray(footArr1);

}

void footballTab::obj2ClearButtonClicked(){

    while(footArr2->getSize())
        footArr2->pop_back();
    updateArray(footArr2);

}

void footballTab::arrButtonPlusClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Somma Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += printArray(footArr1);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;+&#160;</td>"
                  "<td align='center' >";
        insert += printArray(footArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *footArr1 = *footArr1 + *footArr2;
        insert += printArray(footArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::arrButtonMinusClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sottrarre inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Sottrai Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(footArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;-&#160;</td>"
                  "<td align='center' >";
        insert += printArray(footArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *footArr1 = *footArr1 - *footArr2;
        insert += printArray(footArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::arrButtonTimesClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di moltiplicare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(footArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;*&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *footArr1 = *footArr1 * intLineEdit->text().toInt();
        insert += printArray(footArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::arrButtonDivisionClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
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
        insert += (printArray(footArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;/&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *footArr1 = *footArr1 / intLineEdit->text().toInt();
        insert += printArray(footArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::arrButtonModulusClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
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
        insert += (printArray(footArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;%&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *footArr1 = *footArr1 % intLineEdit->text().toInt();
        insert += printArray(footArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(footArr1);
    }

}

void footballTab::arrButtonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*footArr1 < *footArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void footballTab::arrButtonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*footArr1 > *footArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#62; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void footballTab::arrButtonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*footArr1 == *footArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void footballTab::arrButtonTotClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la somma degli elementi di Array 1");
        Football tempFoot = footArr1->tot();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Totale Array 1: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonMediaClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la media inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la media degli elementi di Array 1");
        Football tempFoot = footArr1->media();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Media Array 1: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonMedianaClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la mediana inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la mediana degli elementi di Array 1");
        Football tempFoot = footArr1->mediana();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Mediana Array 1: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonModaClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la moda inserire almeno un elemento in Array 1!");
    else{

        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la moda degli elementi di Array 1");

        Array<Football> tempFoot = footArr1->moda();

        QString insert = "<table><tr>"
                         "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Moda Array 1: </td>"
                         "<td align='center'>";
        insert += printArray(&tempFoot);
        insert += "</td></tr></table><hr>";

        history->insertHtml(insert);

        history->insertHtml(QString::fromStdString(std::string("<br></div>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonMaxClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il massimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il massimo degli elementi di Array 1");
        Football tempFoot = footArr1->max();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Massimo Array 1: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonMinClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il minimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il minimo degli elementi di Array 1");
        Football tempFoot = footArr1->min();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Minimo Array 1: </td>"
                                                               "<td align='center'>"+ tempFoot.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void footballTab::arrButtonOrdinamentoCrescenteClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo crescente");
        footArr1->ordinamentoCrescente();
        updateArray(footArr1);
    }

}

void footballTab::arrButtonOrdinamentoDecrescenteClicked(){

    if(!footArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo decrescente");
        footArr1->ordinamentoDecrescente();
        updateArray(footArr1);
    }

}

void footballTab::arrButtonUnioneClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di unire inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
        *footArr1 = footArr1->unione(*footArr2);
        updateArray(footArr1);
    }

}

void footballTab::arrButtonIntersezioneClicked(){

    if(!footArr1->getSize() && !footArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di intersecare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");
        *footArr1 = footArr1->intersezione(*footArr2);
        updateArray(footArr1);
    }

}

QString footballTab::printArray(Array<Football>* footArr) const{

    std::string arrString;

    if(!footArr->getSize()){
        arrString += "{ Ø }";
    }else{
        arrString += footArr->getObj(0).print();
        for(int i = 1; i < footArr->getSize(); ++i){
            arrString += "<hr>";
            arrString += footArr->getObj(i).print();
        }
    }

    return QString::fromStdString(arrString);

}

void footballTab::updateArray(Array<Football>* footArr) const{

    QTextEdit* tempLine;

    if(footArr == footArr1)
        tempLine = arr1TextEdit;
    else
        tempLine = arr2TextEdit;

    tempLine->clear();

    std::string arrString = "{";

    if(footArr->getSize()){
        arrString += " ⚽ [0] ";
        for(int i = 1; i < footArr->getSize(); ++i){
            arrString += " - ⚽ [";
            arrString += std::to_string(i);
            arrString += "] ";
        }
    } else {
        arrString += " Ø ";
    }

    arrString += "}";

    tempLine->setText(QString::fromStdString(arrString));

}

