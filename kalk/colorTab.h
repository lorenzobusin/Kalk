
#ifndef COLORTAB_H
#define COLORTAB_H

#include "tab.h"
#include "color.h"

class colorTab : public tab {

    Q_OBJECT

private:

    Color* c1;
    Color* c2;

    Array<Color>* colArr1;
    Array<Color>* colArr2;

    QGridLayout* selectorLayout;

    QLabel* RLabel;
    QLabel* GLabel;
    QLabel* BLabel;

    QSlider* RSlider;
    QSlider* GSlider;
    QSlider* BSlider;

    QLineEdit* RInt;
    QLineEdit* GInt;
    QLineEdit* BInt;

    QTextEdit* colorBox;

    Color* tempColor;
    QPushButton* tempButton;

    QPushButton* okButton;
    QPushButton* cancelButton;

    void deleteAll();

    void updateArray(Array<Color>*) const;
    QString printArray(Array<Color>*) const;

public:

    colorTab(QWidget* =0);
    ~colorTab() =default;

private slots:

    void sliderValueChanged();
    void intValueChanged();

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

#endif // COLORTAB_H
