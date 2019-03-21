
#include "tab.h"

tab::tab(QWidget *parent) : QWidget(parent){

    /* ROW 1 */
    historyLabel = new QLabel(tr("Operazioni:"));
    clearButton = new QPushButton(tr("Cancella"), this);

    clearButton->setStatusTip("Cancella");

    /* ROW 2 */
    history = new QTextEdit();
    history->setReadOnly(true);
    history->setMinimumWidth(580);
    history->setAlignment(Qt::AlignRight);

    historyCursor = history->textCursor();

    connect(clearButton, SIGNAL(clicked()), history, SLOT(clear()));

    historyFont = history->font();

    /* ROW 3 */
    obj1Label = new QLabel();
    obj2Label = new QLabel();
    intLabel = new QLabel();

    obj1Button = new QPushButton(this);
    obj2Button = new QPushButton(this);

    intLineEdit= new QLineEdit("0");
    intLineEdit->setAlignment(Qt::AlignCenter);

    /* ROW 4 */

    objOpLabel = new QLabel("Operazioni tra oggetti:");

    /* Buttons */

    buttonPlus = new QPushButton(tr("+"), this);
    buttonMinus = new QPushButton(tr("-"), this);
    buttonTimes = new QPushButton(tr("*"), this);
    buttonDivision = new QPushButton(tr("/"), this);
    buttonModulus = new QPushButton(tr("%"), this);
    buttonLessThan = new QPushButton(tr("<"), this);
    buttonGreaterThan = new QPushButton(tr(">"), this);
    buttonNot = new QPushButton(tr("!"), this);
    buttonEqualsEquals = new QPushButton(tr("=="), this);

    connect(obj1Button, SIGNAL(clicked(bool)), this, SLOT(selector()));
    connect(obj2Button, SIGNAL(clicked(bool)), this, SLOT(selector()));
    connect(buttonPlus, SIGNAL(clicked(bool)), this, SLOT(buttonPlusClicked()));
    connect(buttonMinus, SIGNAL(clicked(bool)), this, SLOT(buttonMinusClicked()));
    connect(buttonTimes, SIGNAL(clicked(bool)), this, SLOT(buttonTimesClicked()));
    connect(buttonDivision, SIGNAL(clicked(bool)), this, SLOT(buttonDivisionClicked()));
    connect(buttonModulus, SIGNAL(clicked(bool)), this, SLOT(buttonModulusClicked()));
    connect(buttonLessThan, SIGNAL(clicked(bool)), this, SLOT(buttonLessThanClicked()));
    connect(buttonGreaterThan, SIGNAL(clicked(bool)), this, SLOT(buttonGreaterThanClicked()));
    connect(buttonEqualsEquals, SIGNAL(clicked(bool)), this, SLOT(buttonEqualsEqualsClicked()));
    connect(buttonNot, SIGNAL(clicked(bool)), this, SLOT(buttonNotClicked()));

    buttonPlus->setFixedSize(70, 50);
    buttonMinus->setFixedSize(70, 50);
    buttonTimes->setFixedSize(70, 50);
    buttonDivision->setFixedSize(70, 50);
    buttonModulus->setFixedSize(70, 50);
    buttonNot->setFixedSize(70, 50);
    buttonLessThan->setFixedSize(70, 50);
    buttonEqualsEquals->setFixedSize(70, 50);
    buttonGreaterThan->setFixedSize(70, 50);

    buttonPlus->setStyleSheet("font-size: 20px");
    buttonMinus->setStyleSheet("font-size: 20px");
    buttonTimes->setStyleSheet("font-size: 20px");
    buttonDivision->setStyleSheet("font-size: 20px");
    buttonModulus->setStyleSheet("font-size: 20px");
    buttonNot->setStyleSheet("font-size: 20px");
    buttonLessThan->setStyleSheet("font-size: 20px");
    buttonEqualsEquals->setStyleSheet("font-size: 20px");
    buttonGreaterThan->setStyleSheet("font-size: 20px");

    /* Button layout */

    operators = new QGridLayout;

    operators->addWidget(buttonPlus         , 0, 0);
    operators->addWidget(buttonMinus        , 0, 1);
    operators->addWidget(buttonTimes        , 0, 2);
    operators->addWidget(buttonDivision     , 0, 3);
    operators->addWidget(buttonModulus      , 0, 4);
    operators->addWidget(buttonNot          , 0, 5);
    operators->addWidget(buttonLessThan     , 0, 6);
    operators->addWidget(buttonEqualsEquals , 0, 7);
    operators->addWidget(buttonGreaterThan  , 0, 8);

    tabLayout = new QGridLayout;
    setLayout(tabLayout);

    /* ARRAY */

    arrOpLabel = new QLabel("Operazioni tra array:");

    arr1Label = new QLabel("Array 1: ");
    arr2Label = new QLabel("Array 2: ");
    arr1TextEdit = new QTextEdit("{ Ø }");
    arr2TextEdit = new QTextEdit("{ Ø }");

    arr1TextEdit->setReadOnly(true);
    arr2TextEdit->setReadOnly(true);

    arr1TextEdit->setMinimumHeight(130);
    arr2TextEdit->setMinimumHeight(130);

    obj1PushButton = new QPushButton("← push");
    obj2PushButton = new QPushButton("← push");
    obj1PopButton = new QPushButton("→ pop");
    obj2PopButton = new QPushButton("→ pop");
    obj1ClearButton = new QPushButton("Clear()");
    obj2ClearButton = new QPushButton("Clear()");

    obj1PushButton->setMinimumHeight(42);
    obj2PushButton->setMinimumHeight(42);
    obj1PopButton->setMinimumHeight(42);
    obj2PopButton->setMinimumHeight(42);
    obj1ClearButton->setMinimumHeight(42);
    obj2ClearButton->setMinimumHeight(42);

    arrButtonPlus = new QPushButton("+");
    arrButtonMinus = new QPushButton("-");
    arrButtonTimes = new QPushButton("*");
    arrButtonDivision = new QPushButton("/");
    arrButtonModulus = new QPushButton("%");
    arrButtonLessThan = new QPushButton("<");
    arrButtonEqualsEquals = new QPushButton("==");
    arrButtonGreaterThan = new QPushButton(">");

    arrButtonTot = new QPushButton("TOT()");
    arrButtonMedia = new QPushButton("MEDIA()");
    arrButtonMediana = new QPushButton("MEDIANA()");
    arrButtonModa = new QPushButton("MODA()");
    arrButtonMax = new QPushButton("MAX()");
    arrButtonMin = new QPushButton("MIN()");
    arrButtonOrdinamentoCrescente = new QPushButton("ORD ↗");
    arrButtonOrdinamentoDecrescente = new QPushButton("ORD ↘");
    arrButtonUnione = new QPushButton("Arr 1 ⋃ Arr 2");
    arrButtonIntersezione = new QPushButton("Arr 1 ⋂ Arr 2");

    obj1PopButton->setStatusTip("Pop ultimo elemento di Array 1");
    obj2PopButton->setStatusTip("Pop ultimo elemento di Array 2");
    obj1ClearButton->setStatusTip("Rimuovi tutti gli elementi di Array 1");
    obj2ClearButton->setStatusTip("Rimuovi tutti gli elementi di Array 2");

    arrButtonPlus->setStatusTip("Somma Array 1 con Array 2");
    arrButtonMinus->setStatusTip("Sottrai Array 2 ad Array 1");
    arrButtonTimes->setStatusTip("Moltiplica gli elementi di Array 1 per l'intero");
    arrButtonDivision->setStatusTip("Dividi gli elementi di Array 1 per l'intero");
    arrButtonModulus->setStatusTip("Calcola il modulo degli elementi di Array 1 per l'intero");
    arrButtonLessThan->setStatusTip("Array 1 < Array 2?");
    arrButtonGreaterThan->setStatusTip("Array 1 > Array 2?");
    arrButtonEqualsEquals->setStatusTip("Array 1 == Array 2?");
    arrButtonTot->setStatusTip("Calcola la somma degli elementi di Array 1");
    arrButtonMedia->setStatusTip("Calcola la media degli elementi di Array 1");
    arrButtonMediana->setStatusTip("Calcola la mediana degli elementi di Array 1");
    arrButtonModa->setStatusTip("Calcola la moda degli elementi di Array 1");
    arrButtonMax->setStatusTip("Calcola il massimo degli elementi di Array 1");
    arrButtonMin->setStatusTip("Calcola il minimo degli elementi di Array 1");
    arrButtonOrdinamentoCrescente->setStatusTip("Ordina Array 1 in modo crescente");
    arrButtonOrdinamentoDecrescente->setStatusTip("Ordina Array 1 in modo decrescente");
    arrButtonUnione->setStatusTip("Unisci Array 1 con Array 2 (risultato in Array 1)");
    arrButtonIntersezione->setStatusTip("Interseca Array 1 con Array 2 (risultato in Array 1)");

    connect(obj1PushButton, SIGNAL(clicked(bool)), this, SLOT(obj1PushButtonClicked()));
    connect(obj2PushButton, SIGNAL(clicked(bool)), this, SLOT(obj2PushButtonClicked()));
    connect(obj1PopButton, SIGNAL(clicked(bool)), this, SLOT(obj1PopButtonClicked()));
    connect(obj2PopButton, SIGNAL(clicked(bool)), this, SLOT(obj2PopButtonClicked()));
    connect(obj1ClearButton, SIGNAL(clicked(bool)), this, SLOT(obj1ClearButtonClicked()));
    connect(obj2ClearButton, SIGNAL(clicked(bool)), this, SLOT(obj2ClearButtonClicked()));
    connect(arrButtonPlus, SIGNAL(clicked(bool)), this, SLOT(arrButtonPlusClicked()));
    connect(arrButtonMinus, SIGNAL(clicked(bool)), this, SLOT(arrButtonMinusClicked()));
    connect(arrButtonTimes, SIGNAL(clicked(bool)), this, SLOT(arrButtonTimesClicked()));
    connect(arrButtonDivision, SIGNAL(clicked(bool)), this, SLOT(arrButtonDivisionClicked()));
    connect(arrButtonModulus, SIGNAL(clicked(bool)), this, SLOT(arrButtonModulusClicked()));
    connect(arrButtonLessThan, SIGNAL(clicked(bool)), this, SLOT(arrButtonLessThanClicked()));
    connect(arrButtonGreaterThan, SIGNAL(clicked(bool)), this, SLOT(arrButtonGreaterThanClicked()));
    connect(arrButtonEqualsEquals, SIGNAL(clicked(bool)), this, SLOT(arrButtonEqualsEqualsClicked()));
    connect(arrButtonTot, SIGNAL(clicked(bool)), this, SLOT(arrButtonTotClicked()));
    connect(arrButtonMedia, SIGNAL(clicked(bool)), this, SLOT(arrButtonMediaClicked()));
    connect(arrButtonMediana, SIGNAL(clicked(bool)), this, SLOT(arrButtonMedianaClicked()));
    connect(arrButtonModa, SIGNAL(clicked(bool)), this, SLOT(arrButtonModaClicked()));
    connect(arrButtonMax, SIGNAL(clicked(bool)), this, SLOT(arrButtonMaxClicked()));
    connect(arrButtonMin, SIGNAL(clicked(bool)), this, SLOT(arrButtonMinClicked()));
    connect(arrButtonOrdinamentoCrescente, SIGNAL(clicked(bool)), this, SLOT(arrButtonOrdinamentoCrescenteClicked()));
    connect(arrButtonOrdinamentoDecrescente, SIGNAL(clicked(bool)), this, SLOT(arrButtonOrdinamentoDecrescenteClicked()));
    connect(arrButtonUnione, SIGNAL(clicked(bool)), this, SLOT(arrButtonUnioneClicked()));
    connect(arrButtonIntersezione, SIGNAL(clicked(bool)), this, SLOT(arrButtonIntersezioneClicked()));

    obj1PushButton->setStyleSheet("font-size: 15px");
    obj2PushButton->setStyleSheet("font-size: 15px");
    obj1PopButton->setStyleSheet("font-size: 15px");
    obj2PopButton->setStyleSheet("font-size: 15px");
    arrButtonPlus->setStyleSheet("font-size: 15px");
    arrButtonMinus->setStyleSheet("font-size: 15px");
    arrButtonTimes->setStyleSheet("font-size: 15px");
    arrButtonDivision->setStyleSheet("font-size: 15px");
    arrButtonModulus->setStyleSheet("font-size: 15px");
    arrButtonLessThan->setStyleSheet("font-size: 15px");
    arrButtonGreaterThan->setStyleSheet("font-size: 15px");
    arrButtonEqualsEquals->setStyleSheet("font-size: 15px");
    arrButtonTot->setStyleSheet("font-size: 15px");
    arrButtonMedia->setStyleSheet("font-size: 15px");
    arrButtonMediana->setStyleSheet("font-size: 15px");
    arrButtonModa->setStyleSheet("font-size: 15px");
    arrButtonMax->setStyleSheet("font-size: 15px");
    arrButtonMin->setStyleSheet("font-size: 15px");
    arrButtonOrdinamentoCrescente->setStyleSheet("font-size: 15px");
    arrButtonOrdinamentoDecrescente->setStyleSheet("font-size: 15px");
    arrButtonUnione->setStyleSheet("font-size: 15px");
    arrButtonIntersezione->setStyleSheet("font-size: 15px");
    obj1ClearButton->setStyleSheet("font-size: 15px");
    obj2ClearButton->setStyleSheet("font-size: 15px");

    arrButtonPlus->setFixedSize(120, 30);
    arrButtonMinus->setFixedSize(120, 30);
    arrButtonTimes->setFixedSize(120, 30);
    arrButtonDivision->setFixedSize(120, 30);
    arrButtonModulus->setFixedSize(120, 30);
    arrButtonLessThan->setFixedSize(120, 30);
    arrButtonGreaterThan->setFixedSize(120, 30);
    arrButtonEqualsEquals->setFixedSize(120, 30);
    arrButtonTot->setFixedSize(120, 30);
    arrButtonMedia->setFixedSize(120, 30);
    arrButtonMediana->setFixedSize(120, 30);
    arrButtonModa->setFixedSize(120, 30);
    arrButtonMax->setFixedSize(120, 30);
    arrButtonMin->setFixedSize(120, 30);
    arrButtonOrdinamentoCrescente->setFixedSize(120, 30);
    arrButtonOrdinamentoDecrescente->setFixedSize(120, 30);
    arrButtonUnione->setFixedSize(120, 30);
    arrButtonIntersezione->setFixedSize(120, 30);

    arrOperators = new QGridLayout;

    arrOperators->addWidget(arrButtonPlus, 0 , 0);
    arrOperators->addWidget(arrButtonMinus, 0, 1);
    arrOperators->addWidget(arrButtonTimes, 0, 2);
    arrOperators->addWidget(arrButtonModa, 0, 3);
    arrOperators->addWidget(arrButtonMedia, 0, 4);
    arrOperators->addWidget(arrButtonMediana, 0, 5);

    arrOperators->addWidget(arrButtonLessThan);
    arrOperators->addWidget(arrButtonEqualsEquals);
    arrOperators->addWidget(arrButtonGreaterThan);
    arrOperators->addWidget(arrButtonMax);
    arrOperators->addWidget(arrButtonMin);
    arrOperators->addWidget(arrButtonUnione);

    arrOperators->addWidget(arrButtonDivision);
    arrOperators->addWidget(arrButtonModulus);
    arrOperators->addWidget(arrButtonTot);
    arrOperators->addWidget(arrButtonOrdinamentoDecrescente);
    arrOperators->addWidget(arrButtonOrdinamentoCrescente);
    arrOperators->addWidget(arrButtonIntersezione);

    arrLayout = new QGridLayout;

    arrLayout->addWidget(arr1Label      , 0, 0, 3, 1);
    arrLayout->addWidget(arr1TextEdit   , 0, 1, 3, 1);
    arrLayout->addWidget(obj1PushButton , 0, 2, 1, 1);
    arrLayout->addWidget(obj1PopButton  , 1, 2, 1, 1);
    arrLayout->addWidget(obj1ClearButton, 2, 2, 1, 1);

    arrLayout->addWidget(arr2Label      , 3, 0, 3, 1);
    arrLayout->addWidget(arr2TextEdit   , 3, 1, 3, 1);
    arrLayout->addWidget(obj2PushButton , 3, 2, 1, 1);
    arrLayout->addWidget(obj2PopButton  , 4, 2, 1, 1);
    arrLayout->addWidget(obj2ClearButton, 5, 2, 1, 1);

    arrLayout->addLayout(arrOperators, 6, 0, 1, arrLayout->columnCount());

    /*  ...  */

    //tabLayout->addWidget(QWidget *    , int fromRow, int fromColumn, int rowSpan, int columnSpan,             Qt::Alignment       );

    tabLayout->addWidget(historyLabel   , 0,           0,              1,           1                                               );
    tabLayout->addWidget(clearButton    , 0,           1,              1,           1,                          Qt::AlignRight      );
    tabLayout->addWidget(history        , 1,           0,              8,           2                                               );
    tabLayout->addWidget(obj1Label      , 0,           2,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(obj1Button     , 0,           3,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(obj2Label      , 0,           4,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(obj2Button     , 0,           5,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(intLabel       , 0,           6,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(intLineEdit    , 0,           7,              1,           1,                          Qt::AlignCenter     );
    tabLayout->addWidget(objOpLabel     , 1,           2,              1,           6                                               );
    tabLayout->addLayout(operators      , 2,           2,              1,           6                                               );
    tabLayout->addWidget(arrOpLabel     , 3,           2,              1,           6                                               );
    tabLayout->addLayout(arrLayout      , 4,           2,              5,           6                                               );

}

void tab::showButtons(bool show){

    objOpLabel->setVisible(show);

    intLabel->setVisible(show);
    intLineEdit->setVisible(show);
    obj1Label->setVisible(show);
    obj1Button->setVisible(show);
    obj2Label->setVisible(show);
    obj2Button->setVisible(show);
    buttonPlus->setVisible(show);
    buttonMinus->setVisible(show);
    buttonTimes->setVisible(show);
    buttonDivision->setVisible(show);
    buttonModulus->setVisible(show);
    buttonLessThan->setVisible(show);
    buttonGreaterThan->setVisible(show);
    buttonNot->setVisible(show);
    buttonEqualsEquals->setVisible(show);

    arr1Label->setVisible(show);
    arr2Label->setVisible(show);
    arr1TextEdit->setVisible(show);
    arr2TextEdit->setVisible(show);
    obj1PushButton->setVisible(show);
    obj2PushButton->setVisible(show);
    obj1PopButton->setVisible(show);
    obj2PopButton->setVisible(show);
    obj1ClearButton->setVisible(show);
    obj2ClearButton->setVisible(show);

    arrOpLabel->setVisible(show);

    arrButtonPlus->setVisible(show);
    arrButtonMinus->setVisible(show);
    arrButtonTimes->setVisible(show);
    arrButtonDivision->setVisible(show);
    arrButtonModulus->setVisible(show);
    arrButtonLessThan->setVisible(show);
    arrButtonGreaterThan->setVisible(show);
    arrButtonEqualsEquals->setVisible(show);

    arrButtonTot->setVisible(show);
    arrButtonMedia->setVisible(show);
    arrButtonMediana->setVisible(show);
    arrButtonModa->setVisible(show);
    arrButtonMax->setVisible(show);
    arrButtonMin->setVisible(show);
    arrButtonOrdinamentoCrescente->setVisible(show);
    arrButtonOrdinamentoDecrescente->setVisible(show);
    arrButtonUnione->setVisible(show);
    arrButtonIntersezione->setVisible(show);

}

void tab::cancelSelector(){

    deleteAll();
    showButtons(true);

}
