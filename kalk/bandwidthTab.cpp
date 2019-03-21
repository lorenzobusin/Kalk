
#include "bandwidthTab.h"

bandwidthTab::bandwidthTab(QWidget *parent) : tab(parent){

    historyFont.setPointSize(historyFont.pointSize() + 2);
    history->setFont(historyFont);

    obj1Label->setText(tr("Bandwidth 1:"));
    obj2Label->setText(tr("Bandwidth 2:"));
    intLabel->setText(tr("Intero:"));

    intLineEdit->setValidator(new QIntValidator(0, 1000000, this));
    intLineEdit->setValidator(new QDoubleValidator(0, 1000000, 2, this));

     b1 = new Bandwidth();
     b2 = new Bandwidth();

     obj1Button->setStyleSheet("background-color:red");
     obj2Button->setStyleSheet("background-color:red");

     obj1Button->setStatusTip("Selezionare Bandwidth 1!");
     obj1Button->setStyleSheet("background-color: red");
     obj2Button->setStatusTip("Selezionare Bandwidth 2!");
     obj2Button->setStyleSheet("background-color: red");
     intLineEdit->setStatusTip("Intero: ");

     buttonPlus->setStatusTip("Somma 2 bandwidth");
     buttonMinus->setStatusTip("Sottrai 2 bandwidth");
     buttonTimes->setStatusTip("Moltiplica bandwidth 1 per l'intero");
     buttonDivision->setStatusTip("Dividi bandwidth 1 per l'intero");
     buttonModulus->setStatusTip("Calcola il modulo di bandwidth 1 con l'intero");
     buttonLessThan->setStatusTip("Bandwidth 1 < Bandwidth 2?");
     buttonGreaterThan->setStatusTip("Bandwidth 1 > Bandwidth 2?");
     buttonEqualsEquals->setStatusTip("Bandwidth 1 == Bandwidth 2?");

     buttonNot->setEnabled(false);
     buttonNot->setStatusTip("Il metodo 'complementare' (not) non è stato implementato per questo tipo di calcolo");

     obj1PushButton->setStatusTip("Push bandwidth 1 in Array 1");
     obj2PushButton->setStatusTip("Push bandwidth 2 in Array 2");

     bandArr1 = new Array<Bandwidth>(0, 20);
     bandArr2 = new Array<Bandwidth>(0, 20);

}

void bandwidthTab::selector(){

    showButtons(false);

    tempButton = static_cast<QPushButton*>(sender());
    tempButton->setStyleSheet("background-color: red");

    if(tempButton == obj1Button){
        tempBand = b1;
    } else if(tempButton == obj2Button){
        tempBand = b2;
    }

    selectorLayout = new QGridLayout;

    PLabel = new QLabel("Ping: ");
    DLabel = new QLabel("Download(Mbps): ");
    ULabel = new QLabel("Upload(Mbps): ");

    PLabel->setMinimumWidth(300);
    DLabel->setMinimumWidth(300);
    ULabel->setMinimumWidth(300);

    PInt = new QLineEdit;
    DDouble = new QLineEdit;
    UDouble = new QLineEdit;

    PInt->setText(QString("%1").arg(tempBand->getPing()));
    DDouble->setText(QString("%1").arg(tempBand->getDown()));
    UDouble->setText(QString("%1").arg(tempBand->getUp()));

    PInt->setValidator(new QIntValidator(0, 1000000));
    DDouble->setValidator(new QDoubleValidator(0, 1000000, 2));
    UDouble->setValidator(new QDoubleValidator(0, 1000000, 2));

    okButton = new QPushButton("&Ok");
    cancelButton = new QPushButton("&Annulla");

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSelector()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelSelector()));

    selectorLayout->addWidget(PLabel, 0, 0);
    selectorLayout->addWidget(PInt, 0, 1);
    selectorLayout->addWidget(DLabel);
    selectorLayout->addWidget(DDouble);
    selectorLayout->addWidget(ULabel);
    selectorLayout->addWidget(UDouble);
    selectorLayout->addWidget(okButton);
    selectorLayout->addWidget(cancelButton);

    tabLayout->addLayout(selectorLayout, 0, 2, 5, 6, Qt::AlignVCenter);

}

void bandwidthTab::deleteAll(){

    delete selectorLayout;
    delete PLabel;
    delete DLabel;
    delete ULabel;
    delete PInt;
    delete DDouble;
    delete UDouble;
    delete okButton;
    delete cancelButton;

}

void bandwidthTab::okSelector(){

    tempBand->setBand(PInt->text().toInt(), DDouble->text().toDouble(), UDouble->text().toDouble());

    if(tempBand->getPing() && tempBand->getDown() && tempBand->getUp())
        tempButton->setStyleSheet("background-color: green");
    else
        tempButton->setStyleSheet("background-color: red");

    cancelSelector();

}

void bandwidthTab::checkZero(){

    if(b1->getPing() && b1->getDown() && b1->getUp())
        obj1Button->setStyleSheet("background-color: green");
    else
        obj1Button->setStyleSheet("background-color: red");

    if(b2->getPing() && b2->getDown() && b2->getUp())
        obj2Button->setStyleSheet("background-color: green");
    else
        obj2Button->setStyleSheet("background-color: red");

}

void bandwidthTab::buttonPlusClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Bandwidth* temp = b1;
    b1 = *b1 + *b2;

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> + </td>"
                                                           "<td align='center'>" + b2->print()) + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

    checkZero();

}

void bandwidthTab::buttonMinusClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Bandwidth* temp = b1;
    if(b1->getPing() >= b2->getPing())
        b1 = *b1 - *b2;
    else
        b1->setBand(0, b1->getDown() - b2->getDown(), b1->getUp() - b2->getUp());

    history->insertHtml(QString::fromStdString(std::string("<table>"
                                                           "<tr>"
                                                           "<td align='center'>" + temp->print() + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> - </td>"
                                                           "<td align='center'>" + b2->print()) + "</td>"
                                                           "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                                                           "<td align='center' style='width:100%'>" + b1->print() + "</td>"
                                                           "</tr>"
                                                           "</table>"
                                                           "<hr>"));

    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();

}

void bandwidthTab::buttonTimesClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Bandwidth* temp = b1;
    b1 = *b1 * intLineEdit->text().toInt();

    history->insertHtml("<table>"
                        "<tr>"
                        "<td align='center'>" + QString::fromStdString(temp->print()) + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> * </td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text() + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                        "<td align='center' style='width:100%'>" + QString::fromStdString(b1->print()) + "</td>"
                        "</tr>"
                        "</table>"
                        "<hr>");
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();

}

void bandwidthTab::buttonDivisionClicked(){

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

    Bandwidth* temp = b1;
    b1 = *b1 / intLineEdit->text().toInt();
    history->insertHtml("<table>"
                        "<tr>"
                        "<td align='center'>" + QString::fromStdString(temp->print()) + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> / </td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text() + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                        "<td align='center' style='width:100%'>" + QString::fromStdString(b1->print()) + "</td>"
                        "</tr>"
                        "</table>"
                        "<hr>");
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();

}

void bandwidthTab::buttonModulusClicked(){

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

    Bandwidth* temp = b1;
    b1 = *b1 % intLineEdit->text().toInt();

    history->insertHtml("<table>"
                        "<tr>"
                        "<td align='center'>" + QString::fromStdString(temp->print()) + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> % </td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'>" + intLineEdit->text() + "</td>"
                        "<td style='font-size: 35px; vertical-align:middle' align='center'> = </td>"
                        "<td align='center' style='width:100%'>" + QString::fromStdString(b1->print()) + "</td>"
                        "</tr>"
                        "</table>"
                        "<hr>");
    delete temp;

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    checkZero();

}

void bandwidthTab::buttonLessThanClicked(){
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

void bandwidthTab::buttonGreaterThanClicked(){
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

void bandwidthTab::buttonEqualsEqualsClicked(){
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

void bandwidthTab::buttonNotClicked(){}

void bandwidthTab::obj1PushButtonClicked(){

    bandArr1->push_back(*b1);
    updateArray(bandArr1);

}

void bandwidthTab::obj2PushButtonClicked(){

    bandArr2->push_back(*b2);
    updateArray(bandArr2);

}

void bandwidthTab::obj1PopButtonClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 1 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 1!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Bandwidth tempBand = bandArr1->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::obj2PopButtonClicked(){

    if(!bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 2 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 2!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Bandwidth tempBand = bandArr2->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Elemento eliminato: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr2);
    }

}

void bandwidthTab::obj1ClearButtonClicked(){

    while(bandArr1->getSize())
        bandArr1->pop_back();
    updateArray(bandArr1);

}

void bandwidthTab::obj2ClearButtonClicked(){

    while(bandArr2->getSize())
        bandArr2->pop_back();
    updateArray(bandArr2);

}

void bandwidthTab::arrButtonPlusClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Somma Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += printArray(bandArr1);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;+&#160;</td>"
                  "<td align='center' >";
        insert += printArray(bandArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *bandArr1 = *bandArr1 + *bandArr2;
        insert += printArray(bandArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonMinusClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sottrarre inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Sottrai Array 1 con Array 2");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(bandArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;-&#160;</td>"
                  "<td align='center' >";
        insert += printArray(bandArr2);
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *bandArr1 = *bandArr1 - *bandArr2;
        insert += printArray(bandArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonTimesClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di moltiplicare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica Array 1 per l'intero");
        QString insert = "<table>"
                         "<tr valign='middle'>"
                         "<td align='center' >";
        insert += (printArray(bandArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;*&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *bandArr1 = *bandArr1 * intLineEdit->text().toInt();
        insert += printArray(bandArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonDivisionClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
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
        insert += (printArray(bandArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;/&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *bandArr1 = *bandArr1 / intLineEdit->text().toInt();
        insert += printArray(bandArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonModulusClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
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
        insert += (printArray(bandArr1));
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;%&#160;</td>"
                  "<td align='center' >";
        insert += intLineEdit->text();
        insert += "</td>"
                  "<td align='center' style='font-size: 27px'>&#160;=&#160;</td>"
                  "<td align='center' >";
        *bandArr1 = *bandArr1 % intLineEdit->text().toInt();
        insert += printArray(bandArr1);
        insert += "</td>"
                  "</tr>"
                  "</table>"
                  "<hr>";
        history->insertHtml(insert);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*bandArr1 < *bandArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#60; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void bandwidthTab::arrButtonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*bandArr1 > *bandArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 &#62; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void bandwidthTab::arrButtonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*bandArr1 == *bandArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td><br>Array 1 == Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void bandwidthTab::arrButtonTotClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la somma degli elementi di Array 1");
        Bandwidth tempBand = bandArr1->tot();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Totale Array 1: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonMediaClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la media inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la media degli elementi di Array 1");
        Bandwidth tempBand = bandArr1->media();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Media Array 1: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonMedianaClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la mediana inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la mediana degli elementi di Array 1");
        Bandwidth tempBand = bandArr1->mediana();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Mediana Array 1: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonModaClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la moda inserire almeno un elemento in Array 1!");
    else{

        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la moda degli elementi di Array 1");

        Array<Bandwidth> tempBand = bandArr1->moda();

        QString insert = "<table><tr>"
                         "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Moda Array 1: </td>"
                         "<td align='center'>";
        insert += printArray(&tempBand);
        insert += "</td></tr></table><hr>";

        history->insertHtml(insert);

        history->insertHtml(QString::fromStdString(std::string("<br></div>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonMaxClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il massimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il massimo degli elementi di Array 1");
        Bandwidth tempBand = bandArr1->max();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Massimo Array 1: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonMinClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il minimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il minimo degli elementi di Array 1");
        Bandwidth tempBand = bandArr1->min();
        history->insertHtml(QString::fromStdString(std::string("<table><tr>"
                                                               "<td style='font-size: 25px; vertical-align:middle; padding:30px' align='center'> Minimo Array 1: </td>"
                                                               "<td align='center'>"+ tempBand.print() +"</td>"
                                                               "</tr></table><hr>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void bandwidthTab::arrButtonOrdinamentoCrescenteClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo crescente");
        bandArr1->ordinamentoCrescente();
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonOrdinamentoDecrescenteClicked(){

    if(!bandArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo decrescente");
        bandArr1->ordinamentoDecrescente();
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonUnioneClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di unire inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
        *bandArr1 = bandArr1->unione(*bandArr2);
        updateArray(bandArr1);
    }

}

void bandwidthTab::arrButtonIntersezioneClicked(){

    if(!bandArr1->getSize() && !bandArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di intersecare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");
        *bandArr1 = bandArr1->intersezione(*bandArr2);
        updateArray(bandArr1);
    }

}

QString bandwidthTab::printArray(Array<Bandwidth>* bandArr) const{

    std::string arrString;

    if(!bandArr->getSize()){
        arrString += "{ Ø }";
    }else{
        arrString += bandArr->getObj(0).print();
        for(int i = 1; i < bandArr->getSize(); ++i){
            arrString += "<hr>";
            arrString += bandArr->getObj(i).print();
        }
    }

    return QString::fromStdString(arrString);

}

void bandwidthTab::updateArray(Array<Bandwidth>* bandArr) const{

    QTextEdit* tempLine;

    if(bandArr == bandArr1)
        tempLine = arr1TextEdit;
    else
        tempLine = arr2TextEdit;

    tempLine->clear();

    //std::string arrString = "<table><tr><td valign='middle'align='center'>{</td> ";
    std::string arrString = "{";

    if(bandArr->getSize()){

        /*arrString += "<td valign='middle'align='center'>";
        arrString += (bandArr->getObj(0)).print();
        arrString += "</td>";*/
        arrString += " ⚡ [0] ";
        for(int i = 1; i < bandArr->getSize(); ++i){
            /*arrString += "<td valign='middle'align='center'> - </td>";
            arrString += "<td valign='middle'align='center'>";
            arrString += (bandArr->getObj(i)).print();
            arrString += "</td>";*/
            arrString += " - ⚡ [";
            arrString += std::to_string(i);
            arrString += "] ";
        }
    } else {
        arrString += " Ø ";
        //arrString += "<td valign='middle'align='center'>Ø</td>";
    }

    //arrString += " <td valign='middle'align='center'>}</td></tr></table>";
    arrString += "}";

    tempLine->setText(QString::fromStdString(arrString));

}
