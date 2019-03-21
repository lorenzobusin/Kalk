
#ifndef TAB_H
#define TAB_H

#include <QtWidgets>

#include "array.h"

class tab : public QWidget {

    Q_OBJECT

private:

    QLabel* historyLabel;
    QPushButton* clearButton;

    QLabel* objOpLabel;

    QLabel* arrOpLabel;

    QLabel* arr1Label;
    QLabel* arr2Label;

    QGridLayout* arrLayout;

    QGridLayout* arrOperators;

protected:

    QTextEdit* history;
    QFont historyFont;
    QTextCursor historyCursor;

    QLabel* obj1Label;
    QLabel* obj2Label;
    QLabel* intLabel;

    QPushButton* obj1Button;
    QPushButton* obj2Button;
    QLineEdit* intLineEdit;

    QPushButton* buttonPlus;
    QPushButton* buttonMinus;
    QPushButton* buttonTimes;
    QPushButton* buttonDivision;
    QPushButton* buttonModulus;
    QPushButton* buttonLessThan;
    QPushButton* buttonGreaterThan;
    QPushButton* buttonEqualsEquals;
    QPushButton* buttonNot;

    QGridLayout* operators;

    QGridLayout* tabLayout;

    QTextEdit* arr1TextEdit;
    QTextEdit* arr2TextEdit;

    QPushButton* obj1PushButton;
    QPushButton* obj2PushButton;
    QPushButton* obj1PopButton;
    QPushButton* obj2PopButton;
    QPushButton* obj1ClearButton;
    QPushButton* obj2ClearButton;

    QPushButton* arrButtonPlus;
    QPushButton* arrButtonMinus;
    QPushButton* arrButtonTimes;
    QPushButton* arrButtonDivision;
    QPushButton* arrButtonModulus;
    QPushButton* arrButtonLessThan;
    QPushButton* arrButtonGreaterThan;
    QPushButton* arrButtonEqualsEquals;

    QPushButton* arrButtonTot;
    QPushButton* arrButtonMedia;
    QPushButton* arrButtonMediana;
    QPushButton* arrButtonModa;
    QPushButton* arrButtonMax;
    QPushButton* arrButtonMin;
    QPushButton* arrButtonOrdinamentoCrescente;
    QPushButton* arrButtonOrdinamentoDecrescente;
    QPushButton* arrButtonUnione;
    QPushButton* arrButtonIntersezione;

    void showButtons(bool);

public:

    tab(QWidget* =0);
    virtual ~tab() =default;

protected slots:

    virtual void selector() =0;
    virtual void okSelector() =0;
    void cancelSelector();
    virtual void deleteAll() =0;

    virtual void buttonPlusClicked() =0;
    virtual void buttonMinusClicked() =0;
    virtual void buttonTimesClicked() =0;
    virtual void buttonDivisionClicked() =0;
    virtual void buttonModulusClicked() =0;
    virtual void buttonLessThanClicked() =0;
    virtual void buttonGreaterThanClicked() =0;
    virtual void buttonEqualsEqualsClicked() =0;
    virtual void buttonNotClicked() =0;

    virtual void obj1PushButtonClicked() =0;
    virtual void obj2PushButtonClicked() =0;
    virtual void obj1PopButtonClicked() =0;
    virtual void obj2PopButtonClicked() =0;
    virtual void obj1ClearButtonClicked() =0;
    virtual void obj2ClearButtonClicked() =0;

    virtual void arrButtonPlusClicked() =0;
    virtual void arrButtonMinusClicked() =0;
    virtual void arrButtonTimesClicked() =0;
    virtual void arrButtonDivisionClicked() =0;
    virtual void arrButtonModulusClicked() =0;
    virtual void arrButtonLessThanClicked() =0;
    virtual void arrButtonGreaterThanClicked() =0;
    virtual void arrButtonEqualsEqualsClicked() =0;
    virtual void arrButtonTotClicked() =0;
    virtual void arrButtonMediaClicked() =0;
    virtual void arrButtonMedianaClicked() =0;
    virtual void arrButtonModaClicked() =0;
    virtual void arrButtonMaxClicked() =0;
    virtual void arrButtonMinClicked() =0;
    virtual void arrButtonOrdinamentoCrescenteClicked() =0;
    virtual void arrButtonOrdinamentoDecrescenteClicked() =0;
    virtual void arrButtonUnioneClicked() =0;
    virtual void arrButtonIntersezioneClicked() =0;

};

#endif // TAB_H
