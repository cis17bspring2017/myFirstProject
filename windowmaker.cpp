//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#include <QtGui>
#include <QtWidgets>
#include <Qwidget>
#include <QApplication>

#include "summary.h"

summary::summary()
{
    createHorizontalGroupBox();
    createFormGroupBox();
    createGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox);
    setLayout(mainLayout);

    setWindowTitle(windowLabel);
}

void summary::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Navigate Buttons"));
    QHBoxLayout *layout = new QHBoxLayout;

    buttons1 = new QPushButton(tr("Transfer"));
    layout->addWidget(buttons1);
    buttons2 = new QPushButton(tr("Select"));
    layout->addWidget(buttons2);
    buttons3 = new QPushButton(tr("Refresh"));
    layout->addWidget(buttons3);
    buttons4 = new QPushButton(tr("Logout"));
    layout->addWidget(buttons4);

    horizontalGroupBox->setLayout(layout);
}

void summary::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Account_Info"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Checking:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Savings:")), new QLineEdit);
    formGroupBox->setLayout(layout);
}
void summary::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Grid layout"));
    QGridLayout *layout = new QGridLayout;

    labelsChecking = new QLabel(tr("Checking_Account"));
    labelsCheckingBalance = new QLabel(tr("  $200.00"));
    labelsCheckingUpDate = new QLabel(tr("9 March 2017"));
    layout->addWidget(labelsChecking,1,0);//$200.00
    layout->addWidget(labelsCheckingBalance,1,1);
    layout->addWidget(labelsCheckingUpDate,1,2);//3/9/2017

    labelsSavings = new QLabel(tr("Savings_Account"));
    labelsSavingsBalance = new QLabel(tr("  $500.00"));
    labelsSavingsUpDate = new QLabel(tr("14 March 2017"));
    layout->addWidget(labelsSavings,2,0);//$500.00 3/16/2017
    layout->addWidget(labelsSavingsBalance,2,1);//$500.00 3/16/2017
    layout->addWidget(labelsSavingsUpDate,2,2);//$500.00 3/16/2017

    layout->setColumnStretch(1, 20);
    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);

    gridGroupBox->setLayout(layout);
}

