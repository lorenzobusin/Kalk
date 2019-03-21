#ifndef FOOTBALLTAB_H
#define FOOTBALLTAB_H

#include "Football.h"
#include "statsTab.h"

class footballTab : public statsTab{

    Q_OBJECT

private:

    Array<Football>* footArr1;
    Array<Football>* footArr2;

    QLabel* PpallaLbl;
    QLabel* GsLbl;
    QLabel* CLbl;
    QLabel* CrossLbl;
    QLabel* RimLbl;
    QLabel* RLbl;
    QLabel* TLbl;
    QLabel* TportaLbl;
    QLabel* FLbl;
    QLabel* CgLbl;
    QLabel* CrLbl;

    QLineEdit* PpallaInt;
    QLineEdit* GsInt;
    QLineEdit* CInt;
    QLineEdit* CrossInt;
    QLineEdit* RimInt;
    QLineEdit* RInt;
    QLineEdit* TInt;
    QLineEdit* TportaInt;
    QLineEdit* FInt;
    QLineEdit* CgInt;
    QLineEdit* CrInt;

    Football* tempFoot;

    void deleteAll();
    QString printArray(Array<Football>*) const;
    void updateArray(Array<Football>*) const;
    void checkZero();

public:

    footballTab(QWidget* =0);
    ~footballTab() = default;

public slots:

    void selector();
    void okSelector();

    void buttonPlusClicked();
    void buttonMinusClicked();
    void buttonTimesClicked();
    void buttonDivisionClicked();
    void buttonModulusClicked();
    void buttonLessThanClicked();
    void buttonGreaterThanClicked();
    void buttonEqualsEqualsClicked();
    void buttonNotClicked();

    void obj1PushButtonClicked();
    void obj2PushButtonClicked();
    void obj1PopButtonClicked();
    void obj2PopButtonClicked();
    void obj1ClearButtonClicked();
    void obj2ClearButtonClicked();

    void arrButtonPlusClicked();
    void arrButtonMinusClicked();
    void arrButtonTimesClicked();
    void arrButtonDivisionClicked();
    void arrButtonModulusClicked();
    void arrButtonLessThanClicked();
    void arrButtonGreaterThanClicked();
    void arrButtonEqualsEqualsClicked();
    void arrButtonTotClicked();
    void arrButtonMediaClicked();
    void arrButtonMedianaClicked();
    void arrButtonModaClicked();
    void arrButtonMaxClicked();
    void arrButtonMinClicked();
    void arrButtonOrdinamentoCrescenteClicked();
    void arrButtonOrdinamentoDecrescenteClicked();
    void arrButtonUnioneClicked();
    void arrButtonIntersezioneClicked();

};

#endif // FOOTBALLTAB_H
