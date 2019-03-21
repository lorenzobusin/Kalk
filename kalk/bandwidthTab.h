
#ifndef BANDWIDTHTAB_H
#define BANDWIDTHTAB_H

#include "tab.h"
#include "bandwidth.h"

class bandwidthTab : public tab {

    Q_OBJECT

private:

    Bandwidth* b1;
    Bandwidth* b2;

    Array<Bandwidth>* bandArr1;
    Array<Bandwidth>* bandArr2;

    QGridLayout* selectorLayout;

    QLabel* PLabel;
    QLabel* DLabel;
    QLabel* ULabel;

    QLineEdit* PInt;
    QLineEdit* DDouble;
    QLineEdit* UDouble;

    Bandwidth* tempBand;
    QPushButton* tempButton;

    QPushButton* okButton;
    QPushButton* cancelButton;

    void deleteAll();
    void updateArray(Array<Bandwidth>*) const;
    QString printArray(Array<Bandwidth>*) const;
    void checkZero();

public:


    bandwidthTab(QWidget* =0);
    ~bandwidthTab() =default;


private slots:

    /* Virtuali in superclasse */
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

#endif // BANDWIDTHTAB_H
