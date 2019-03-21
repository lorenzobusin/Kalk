
#ifndef STATSTAB_H
#define STATSTAB_H

#include "tab.h"
#include "Match_stats.h"

class statsTab : public tab {

    Q_OBJECT

protected:

    Match_stats* m1;
    Match_stats* m2;

    QGridLayout* selectorLayout;

    Array<Match_stats>* statsArr1;
    Array<Match_stats>* statsArr2;

    QLabel* puntLbl;
    QLabel* fsLbl;
    QLabel* fcLbl;
    QLabel* mLbl;
    QLabel* ppLbl;
    QLabel* prLbl;
    QLabel* passLbl;
    QLabel* passrLbl;

    QLineEdit* puntInt;
    QLineEdit* fsInt;
    QLineEdit* fcInt;
    QLineEdit* mInt;
    QLineEdit* ppInt;
    QLineEdit* prInt;
    QLineEdit* passInt;
    QLineEdit* passrInt;

    Match_stats* tempMatch;
    QPushButton* tempButton;

    QPushButton* okButton;
    QPushButton* cancelButton;

    void deleteAll();
    QString printArray(Array<Match_stats>*) const;
    void updateArray(Array<Match_stats>*) const;
    void checkZero();

public:

    statsTab(QWidget* =0);
     ~statsTab() =default;

private slots:

     virtual void selector();
     virtual void okSelector();

     virtual void buttonPlusClicked();
     virtual void buttonMinusClicked();
     virtual void buttonTimesClicked();
     virtual void buttonDivisionClicked();
     virtual void buttonModulusClicked();
     virtual void buttonLessThanClicked();
     virtual void buttonGreaterThanClicked();
     virtual void buttonEqualsEqualsClicked();
     virtual void buttonNotClicked();
     virtual void obj1PushButtonClicked();
     virtual void obj2PushButtonClicked();
     virtual void obj1PopButtonClicked();
     virtual void obj2PopButtonClicked();
     virtual void obj1ClearButtonClicked();
     virtual void obj2ClearButtonClicked();
     virtual void arrButtonPlusClicked();
     virtual void arrButtonMinusClicked();
     virtual void arrButtonTimesClicked();
     virtual void arrButtonDivisionClicked();
     virtual void arrButtonModulusClicked();
     virtual void arrButtonLessThanClicked();
     virtual void arrButtonGreaterThanClicked();
     virtual void arrButtonEqualsEqualsClicked();
     virtual void arrButtonTotClicked();
     virtual void arrButtonMediaClicked();
     virtual void arrButtonMedianaClicked();
     virtual void arrButtonModaClicked();
     virtual void arrButtonMaxClicked();
     virtual void arrButtonMinClicked();
     virtual void arrButtonOrdinamentoCrescenteClicked();
     virtual void arrButtonOrdinamentoDecrescenteClicked();
     virtual void arrButtonUnioneClicked();
     virtual void arrButtonIntersezioneClicked();

};

#endif // STATSTAB_H
