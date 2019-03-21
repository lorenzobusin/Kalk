
#include "calculator.h"
#include "colorTab.h"
#include "bandwidthTab.h"
#include "statsTab.h"
#include "footballTab.h"
#include "basketTab.h"

calculator::calculator(QWidget *parent) : QWidget(parent) {

    tabWidget = new QTabWidget;

    tabWidget->addTab(new colorTab(), tr("Colori"));
    tabWidget->addTab(new bandwidthTab(), tr("Bandwidth"));
    tabWidget->addTab(new statsTab(), tr("Statistiche sportive"));
    tabWidget->addTab(new footballTab(), tr("Statistiche calcio"));
    tabWidget->addTab(new basketTab(), tr("Statistiche basket"));

    tabLayout = new QGridLayout;
    tabLayout->addWidget(tabWidget, 0, 0);
    setLayout(tabLayout);

}

QGridLayout* calculator::getLayout()const {
    return tabLayout;
}
