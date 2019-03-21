#ifndef BASKETTAB_H
#define BASKETTAB_H

#include "statsTab.h"
#include "Basketball.h"

class basketTab : public statsTab{


    Q_OBJECT

private:

    Array<Basketball>* basketArr1;
    Array<Basketball>* basketArr2;

    QLabel* PsLbl;
    QLabel* RoLbl;
    QLabel* RdLbl;
    QLabel* ALbl;
    QLabel* SLbl;
    QLabel* T2Lbl;
    QLabel* T2sLbl;
    QLabel* T3Lbl;
    QLabel* T3sLbl;
    QLabel* LLbl;
    QLabel* LsLbl;

    QLineEdit* PsInt;
    QLineEdit* RoInt;
    QLineEdit* RdInt;
    QLineEdit* AInt;
    QLineEdit* SInt;
    QLineEdit* T2Int;
    QLineEdit* T2sInt;
    QLineEdit* T3Int;
    QLineEdit* T3sInt;
    QLineEdit* LInt;
    QLineEdit* LsInt;

    Basketball* tempBask;

    void deleteAll();
    QString printArray(Array<Basketball>*) const;
    void updateArray(Array<Basketball>*) const;
    void checkZero();

public:

    basketTab(QWidget* =0);
    ~basketTab() = default;

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

#endif // BASKETTAB_H
