
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets>

class calculator : public QWidget{

    Q_OBJECT

private:

    QTabWidget *tabWidget;
    QGridLayout *tabLayout;

public:

    calculator(QWidget* =0);

    QGridLayout* getLayout() const;

};

#endif // CALCULATOR_H
