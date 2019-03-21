
#include "colorTab.h"

colorTab::colorTab(QWidget *parent) : tab(parent){

    historyFont.setPointSize(historyFont.pointSize() + 25);
    history->setFont(historyFont);

    obj1Label->setText(tr("Colore 1:"));
    obj2Label->setText(tr("Colore 2:"));
    intLabel->setText(tr("Intero:"));

    intLineEdit->setValidator(new QIntValidator(0, 255, this));

    c1 = new Color();
    c2 = new Color();

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    obj2Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c2->print())));

    obj1Button->setStatusTip("Selezionare colore 1!");
    obj2Button->setStatusTip("Selezionare colore 2!");
    intLineEdit->setStatusTip("Inserire un intero (0 - 255)");

    buttonPlus->setStatusTip("Somma 2 colori");
    buttonMinus->setStatusTip("Sottrai 2 colori");
    buttonTimes->setStatusTip("Moltiplica colore 1 per l'intero");
    buttonDivision->setStatusTip("Dividi colore 1 per l'intero");
    buttonModulus->setStatusTip("Calcola il modulo di colore 1 con l'intero");
    buttonLessThan->setStatusTip("Colore 1 > Colore 2? (media dei valori rgb)");
    buttonGreaterThan->setStatusTip("Colore 1 < Colore 2? (media dei valori rgb)");
    buttonEqualsEquals->setStatusTip("Colore 1 == Colore 2?");
    buttonNot->setStatusTip("Complementare di colore 1");

    obj1PushButton->setStatusTip("Push colore 1 in Array 1");
    obj2PushButton->setStatusTip("Push colore 2 in Array 2");

    colArr1 = new Array<Color>(0, 20);
    colArr2 = new Array<Color>(0, 20);

}

void colorTab::selector(){

    showButtons(false);

    tempButton = static_cast<QPushButton*>(sender());

    if(tempButton == obj1Button){
        tempColor = c1;
    } else if(tempButton == obj2Button){
        tempColor = c2;
    }

    selectorLayout = new QGridLayout;

    RLabel = new QLabel("R: ");
    GLabel = new QLabel("G: ");
    BLabel = new QLabel("B: ");

    RSlider = new QSlider(Qt::Horizontal);
    GSlider = new QSlider(Qt::Horizontal);
    BSlider = new QSlider(Qt::Horizontal);

    RSlider->setMinimum(0);
    GSlider->setMinimum(0);
    BSlider->setMinimum(0);

    RSlider->setMaximum(255);
    GSlider->setMaximum(255);
    BSlider->setMaximum(255);

    RSlider->setValue(tempColor->getR());
    GSlider->setValue(tempColor->getG());
    BSlider->setValue(tempColor->getB());

    connect(RSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged()));
    connect(GSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged()));
    connect(BSlider, SIGNAL(sliderMoved(int)), this, SLOT(sliderValueChanged()));

    RInt = new QLineEdit(QString("%1").arg(RSlider->value()));
    GInt = new QLineEdit(QString("%1").arg(GSlider->value()));
    BInt = new QLineEdit(QString("%1").arg(BSlider->value()));

    RInt->setValidator(new QIntValidator(0, 255));
    GInt->setValidator(new QIntValidator(0, 255));
    BInt->setValidator(new QIntValidator(0, 255));

    connect(RInt, SIGNAL(textEdited(QString)), this, SLOT(intValueChanged()));
    connect(GInt, SIGNAL(textEdited(QString)), this, SLOT(intValueChanged()));
    connect(BInt, SIGNAL(textEdited(QString)), this, SLOT(intValueChanged()));

    colorBox = new QTextEdit();

    colorBox->setReadOnly(true);
    colorBox->setFixedWidth(200);
    colorBox->setFixedHeight(200);
    colorBox->setStyleSheet(QString::fromStdString(std::string("background-color: " + tempColor->print() + "; border-style: solid; border-width:1px; border-radius:50px;")));

    RSlider->setFixedWidth(400);
    GSlider->setFixedWidth(400);
    BSlider->setFixedWidth(400);

    okButton = new QPushButton("&Ok");
    cancelButton = new QPushButton("&Annulla");

    connect(okButton, SIGNAL(clicked(bool)), this, SLOT(okSelector()));
    connect(cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelSelector()));

    selectorLayout->addWidget(RLabel        , 0, 0, 1, 1);
    selectorLayout->addWidget(RSlider       , 0, 1, 1, 3);
    selectorLayout->addWidget(RInt          , 0, 4, 1, 1);
    selectorLayout->addWidget(GLabel        , 1, 0, 1, 1);
    selectorLayout->addWidget(GSlider       , 1, 1, 1, 3);
    selectorLayout->addWidget(GInt          , 1, 4, 1, 1);
    selectorLayout->addWidget(BLabel        , 2, 0, 1, 1);
    selectorLayout->addWidget(BSlider       , 2, 1, 1, 3);
    selectorLayout->addWidget(BInt          , 2, 4, 1, 1);
    selectorLayout->addWidget(colorBox      , 3, 0, 1, 5, Qt::AlignCenter);
    selectorLayout->addWidget(okButton      , 4, 0, 1, 4);
    selectorLayout->addWidget(cancelButton  , 4, 4, 1, 1);

    tabLayout->addLayout(selectorLayout, 0, 2, 5, 6, Qt::AlignVCenter);

}

void colorTab::deleteAll(){

    delete selectorLayout;
    delete RLabel;
    delete GLabel;
    delete BLabel;
    delete RSlider;
    delete GSlider;
    delete BSlider;
    delete RInt;
    delete GInt;
    delete BInt;
    delete colorBox;
    delete okButton;
    delete cancelButton;

}

void colorTab::okSelector(){

    tempColor->setColor(RSlider->value(), GSlider->value(), BSlider->value());
    tempButton->setStyleSheet(QString::fromStdString(std::string("background-color: " + tempColor->print())));
    cancelSelector();

}

void colorTab::sliderValueChanged(){

    colorBox->setStyleSheet(QString("border-style: solid; border-width:1px; border-radius:50px; background:rgb(%1,%2,%3);").arg(RSlider->value()).arg(GSlider->value()).arg(BSlider->value()));

    RInt->setText(QString("%1").arg(RSlider->value()));
    GInt->setText(QString("%1").arg(GSlider->value()));
    BInt->setText(QString("%1").arg(BSlider->value()));

}

void colorTab::intValueChanged(){

    RSlider->setValue(RInt->text().toInt());
    GSlider->setValue(GInt->text().toInt());
    BSlider->setValue(BInt->text().toInt());

    sliderValueChanged();

}

void colorTab::buttonPlusClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Color* temp = c1;
    c1 = *c1 + *c2;

    history->insertHtml(QString::fromStdString(std::string("<table align='center'>"
                                                           "<tr>"
                                                           "<td>"
                                                           "<span style='color:" + temp->print() + ";'>●</span>"
                                                           " + "
                                                           "<span style='color:" + c2->print() + ";'>●</span>"
                                                           " = "
                                                           "<span style='color:" + c1->print() + ";'>●</span>"
                                                           "</td>"
                                                           "</tr>")));

    delete temp;

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonMinusClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    Color* temp = c1;
    c1 = *c1 - *c2;

    history->insertHtml(QString::fromStdString(std::string("<table align='center'>"
                                                           "<tr>"
                                                           "<td>"
                                                           "<span style='color:" + temp->print() + ";'>●</span>"
                                                           " - "
                                                           "<span style='color:" + c2->print() + ";'>●</span>"
                                                           " = "
                                                           "<span style='color:" + c1->print() + ";'>●</span>"
                                                           "</td>"
                                                           "</tr>")));

    delete temp;

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonTimesClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    QString temp(QString::fromStdString(c1->print()));
    c1->setColor(c1->getR()*intLineEdit->text().toInt(), c1->getG()*intLineEdit->text().toInt(), c1->getB()*intLineEdit->text().toInt());

    history->insertHtml("<table align='center'>"
                        "<tr>"
                        "<td>"
                        "<span style='color:" + temp + ";'>●</span>"
                        " * "
                        "<span style='color:" + intLineEdit->text() + ";'>●</span>"
                        " = "
                        "<span style='color:" + QString::fromStdString(c1->print()) + ";'>●</span>"
                        "</td>"
                        "</tr>");

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonDivisionClicked(){

    if(!intLineEdit->text().toInt()){
        history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                            "<tr><td>"
                            "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                            "<br></td></tr>"
                            "</table>");
        intLineEdit->setText("1");
    }

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    QString temp(QString::fromStdString(c1->print()));
    c1->setColor(c1->getR()/intLineEdit->text().toInt(), c1->getG()/intLineEdit->text().toInt(), c1->getB()/intLineEdit->text().toInt());

    history->insertHtml("<table align='center'>"
                        "<tr>"
                        "<td>"
                        "<span style='color:" + temp + ";'>●</span>"
                        " / "
                        "<span style='color:" + intLineEdit->text() + ";'>●</span>"
                        " = "
                        "<span style='color:" + QString::fromStdString(c1->print()) + ";'>●</span>"
                        "</td>"
                        "</tr>");

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonModulusClicked(){

    if(!intLineEdit->text().toInt()){
        history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                            "<tr><td>"
                            "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                            "<br></td></tr>"
                            "</table>");
        intLineEdit->setText("1");
    }

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    QString temp(QString::fromStdString(c1->print()));
    c1->setColor(c1->getR()%intLineEdit->text().toInt(), c1->getG()%intLineEdit->text().toInt(), c1->getB()%intLineEdit->text().toInt());

    history->insertHtml("<table align='center'>"
                        "<tr>"
                        "<td>"
                        "<span style='color:" + temp + ";'>●</span>"
                        " % "
                        "<span style='color:" + intLineEdit->text() + ";'>●</span>"
                        " = "
                        "<span style='color:" + QString::fromStdString(c1->print()) + ";'>●</span>"
                        "</td>"
                        "</tr>");

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if (*c1 == *c2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:red'>✕</span></td></tr></table>")));
    else if(*c1 < *c2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if (*c1 == *c2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:red'>✕</span></td></tr></table>")));
    else if(*c1 > *c2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*c1 == *c2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:green'>✔</span></td></tr></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td><span style='color:" + c1->print() + ";'>●</span> &#62; <span style='color:" + c2->print() + ";'>●</span><span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::buttonNotClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    std::string temp = c1->print();
    !*c1;
    history->insertHtml(QString::fromStdString(std::string("<table align='center'><tr><td>!<span style='color:" + temp + ";'>●</span> = <span style='color:" + c1->print() + "'>●</span>")));

    obj1Button->setStyleSheet(QString::fromStdString(std::string("background-color: " + c1->print())));
    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::obj1PushButtonClicked(){

    colArr1->push_back(*c1);
    updateArray(colArr1);

}

void colorTab::obj2PushButtonClicked(){

    colArr2->push_back(*c2);
    updateArray(colArr2);

}

void colorTab::obj1PopButtonClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 1 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 1!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Color tempColor = colArr1->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 20px'><tr><td>Elemento eliminato: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::obj2PopButtonClicked(){

    if(!colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Array 2 non contiene alcun elemento!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Pop ultimo elemento di Array 2!");
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        Color tempColor = colArr2->pop_back();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 20px'><tr><td>Elemento eliminato: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr2);
    }

}

void colorTab::obj1ClearButtonClicked(){

    while(colArr1->getSize())
        colArr1->pop_back();
    updateArray(colArr1);

}

void colorTab::obj2ClearButtonClicked(){

    while(colArr2->getSize())
        colArr2->pop_back();
    updateArray(colArr2);

}

void colorTab::arrButtonPlusClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Somma Array 1 con Array 2");
        QString temp("<table align='center' style='font-size: 30px;'>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr1) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "+"
                     "</td></tr>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr2) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "="
                     "</td></tr>");
        *colArr1 = *colArr1 + *colArr2;
        temp += "<tr><td style='text-align:center'>" +
                printArray(colArr1) +
                "</td></tr>"
                "</table>"
                "<hr>";
        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::arrButtonMinusClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sottrarre inserire almeno un elemento in Array 1 / Array 2!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Sottrai Array 2 ad Array 1");
        QString temp("<table align='center' style='font-size: 30px;'>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr1) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "-"
                     "</td></tr>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr2) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "="
                     "</td></tr>");
        *colArr1 = *colArr1 - *colArr2;
        temp += "<tr><td style='text-align:center'>" +
                printArray(colArr1) +
                "</td></tr>"
                "</table>"
                "<hr>";
        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::arrButtonTimesClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di moltiplicare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Moltiplica gli elementi di Array 1 per l'intero");
        QString temp("<table align='center' style='font-size: 30px;'>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr1) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "*"
                     "</td></tr>"
                     "<tr><td style='text-align:center'>" +
                     intLineEdit->text() +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "="
                     "</td></tr>");
        *colArr1 = *colArr1 * intLineEdit->text().toInt();
        temp += "<tr><td style='text-align:center'>" +
                printArray(colArr1) +
                "</td></tr>"
                "</table>"
                "<hr>";
        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::arrButtonDivisionClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di dividere inserire almeno un elemento in Array 1!");
    else{
        if(!intLineEdit->text().toInt()){
            history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                                "<tr><td>"
                                "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                                "<br></td></tr>"
                                "</table>");
            intLineEdit->setText("1");
        }
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Dividi gli elementi di Array 1 per l'intero");
        QString temp("<table align='center' style='font-size: 30px;'>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr1) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "/"
                     "</td></tr>"
                     "<tr><td style='text-align:center'>" +
                     intLineEdit->text() +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "="
                     "</td></tr>");
        *colArr1 = *colArr1 / intLineEdit->text().toInt();
        temp += "<tr><td style='text-align:center'>" +
                printArray(colArr1) +
                "</td></tr>"
                "</table>"
                "<hr>";
        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::arrButtonModulusClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il modulo inserire almeno un elemento in Array 1!");
    else{
        if(!intLineEdit->text().toInt()){
            history->insertHtml("<table align='center' style='margin-top: 25px; color: red; font-size: 15px;'>"
                                "<tr><td>"
                                "Tentata divisione per 0! Valore dell'intero cambiata in automatico ad 1!"
                                "<br></td></tr>"
                                "</table>");
            intLineEdit->setText("1");
        }
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il modulo degli elementi di Array 1 per l'intero");
        QString temp("<table align='center' style='font-size: 30px;'>"
                     "<tr><td style='text-align:center'>" +
                     printArray(colArr1) +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "%"
                     "</td></tr>"
                     "<tr><td style='text-align:center'>" +
                     intLineEdit->text() +
                     "</td></tr>"
                     "<tr><td style='text-align:center'>"
                     "="
                     "</td></tr>");
        *colArr1 = *colArr1 % intLineEdit->text().toInt();
        temp += "<tr><td style='text-align:center'>" +
                printArray(colArr1) +
                "</td></tr>"
                "</table>"
                "<hr>";
        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        updateArray(colArr1);
    }

}

void colorTab::arrButtonLessThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*colArr1 < *colArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#60; Array 2 <span style='color:green'>✔</span></td></td></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#60; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::arrButtonGreaterThanClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*colArr1 > *colArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:green'>✔</span></td></td></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 &#62; Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::arrButtonEqualsEqualsClicked(){

    historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    history->setTextCursor(historyCursor);

    if(*colArr1 == *colArr2)
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 == Array 2 <span style='color:green'>✔</span></td></td></table>")));
    else
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Array 1 == Array 2 <span style='color:red'>✕</span></td></tr></table>")));

    history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());

}

void colorTab::arrButtonTotClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di sommare inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la somma degli elementi di Array 1");
        Color tempColor = colArr1->tot();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Totale Array 1: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void colorTab::arrButtonMediaClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la media inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la media degli elementi di Array 1");
        Color tempColor = colArr1->media();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Media Array 1: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void colorTab::arrButtonMedianaClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la mediana inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la mediana degli elementi di Array 1");
        Color tempColor = colArr1->mediana();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Mediana Array 1: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
        //TODO: stampare risultato in history
    }

}

void colorTab::arrButtonModaClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare la moda inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola la moda degli elementi di Array 1");
        Array<Color> tempColor = colArr1->moda();

        QString temp("<table align='center' style='font-size: 27px'><tr><td>Moda Array 1:</td><td>" + printArray(&tempColor) + "</td></tr></table>");


        history->insertHtml(temp);
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void colorTab::arrButtonMaxClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il massimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il massimo degli elementi di Array 1");
        Color tempColor = colArr1->max();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Max Array 1: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void colorTab::arrButtonMinClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di calcolare il minimo inserire almeno un elemento in Array 1!");
    else{
        historyCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        history->setTextCursor(historyCursor);
        (static_cast<QPushButton*>(sender()))->setStatusTip("Calcola il minimo degli elementi di Array 1");
        Color tempColor = colArr1->min();
        history->insertHtml(QString::fromStdString(std::string("<table align='center' style='font-size: 27px'><tr><td>Min Array 1: </td><td><span style='color:" + tempColor.print() + ";'>●</span></td><td> { "+tempColor.print()+" }</td></tr></table>")));
        history->verticalScrollBar()->setValue(history->verticalScrollBar()->maximum());
    }

}

void colorTab::arrButtonOrdinamentoCrescenteClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo crescente");
        colArr1->ordinamentoCrescente();
        updateArray(colArr1);
    }

}

void colorTab::arrButtonOrdinamentoDecrescenteClicked(){

    if(!colArr1->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di ordinare inserire almeno un elemento in Array 1!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Ordina Array 1 in modo decrescente");
        colArr1->ordinamentoDecrescente();
        updateArray(colArr1);
    }

}

void colorTab::arrButtonUnioneClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di unire inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
        *colArr1 = colArr1->unione(*colArr2);
        updateArray(colArr1);
    }

}

void colorTab::arrButtonIntersezioneClicked(){

    if(!colArr1->getSize() && !colArr2->getSize())
        (static_cast<QPushButton*>(sender()))->setStatusTip("ERRORE! Prima di intersecare inserire almeno un elemento in Array 1 / Array 2!");
    else{
        (static_cast<QPushButton*>(sender()))->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");
        *colArr1 = colArr1->intersezione(*colArr2);
        updateArray(colArr1);
    }

}

QString colorTab::printArray(Array<Color>* colArr) const{

    std::string arrString = "{ ";

    if(!colArr->getSize()){
        arrString += "Ø";
    }else{
        arrString += "<span style='color:";
        arrString += colArr->getObj(0).print();
        arrString += ";'>●</span>";

        for(int i = 1; i < colArr->getSize(); ++i){
            arrString += " - <span style='color:";
            arrString += colArr->getObj(i).print();
            arrString += ";'>●</span>";
        }
    }

    arrString += " }";

    return QString::fromStdString(arrString);

}

void colorTab::updateArray(Array<Color>* colArr) const{

    QTextEdit* tempLine;

    if(colArr == colArr1)
        tempLine = arr1TextEdit;
    else
        tempLine = arr2TextEdit;

    tempLine->clear();

    std::string arrString = "{ ";

    if(colArr->getSize()){
        arrString += (colArr->getObj(0)).print();
        for(int i = 1; i < colArr->getSize(); ++i){
            arrString += " - ";
            arrString += (colArr->getObj(i)).print();
        }
    } else {
        arrString += "Ø";
    }

    arrString += " }";

    tempLine->setText(QString::fromStdString(arrString));

}
