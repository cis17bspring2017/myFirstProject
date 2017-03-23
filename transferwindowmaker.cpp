//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#include <QtGui>
#include <QtWidgets>
#include <Qwidget>
#include <QApplication>

#include "transferwindowmaker.h"

transferwindowmaker::transferwindowmaker()
{
    //createMenu();  //GoldPlating not yet needed
    createHorizontalGroupBox();
    createFormGroupBox();
    createGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox);
    setLayout(mainLayout);

    setWindowTitle(windowLabel);
}

//void transferwindowmaker::createMenu()
//{
//    menuBar = new QMenuBar;
//    NavigateMenu = new QMenu(tr("&NavigateMenu"), this);
//    menuBar->addMenu(NavigateMenu);
//}

void transferwindowmaker::createHorizontalGroupBox()
{
    //inserted last, to appear at bottom of window
    horizontalGroupBox = new QGroupBox(tr("Navigate Buttons"));
    QHBoxLayout *layout = new QHBoxLayout;

    buttons1 = new QPushButton(tr("Yes, Transfer"));
    layout->addWidget(buttons1);
    buttons2 = new QPushButton(tr("No, Cancel"));
    layout->addWidget(buttons2);

    horizontalGroupBox->setLayout(layout);
}

void transferwindowmaker::createFormGroupBox()
{   //this will be art of the section that wil have account selections
    // ,balances, and amount to transfer
    formGroupBox = new QGroupBox(tr("Account_Info"));
    QFormLayout *layout = new QFormLayout;
    layout->addRow(new QLabel(tr("Transfer funds from:")), new QLineEdit);
    layout->addRow(new QLabel(tr("Transfer funds to:")), new QLineEdit);
    formGroupBox->setLayout(layout);
}
void transferwindowmaker::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Choose Accounts, then enter amount to transfer"));
    QGridLayout *layout = new QGridLayout;
//    buttons3 = new QPushButton(tr("Select Account"));
//    layout->addWidget(buttons3,0,1);
//    buttons4 = new QPushButton(tr("Select Account"));
//    layout->addWidget(buttons4,1,1);

    labelsFromAccount = new QLabel(tr("Checking"));
    labelsFromBalance = new QLabel(tr("  $500.00"));
    lineTransferAmount = new QLineEdit(tr("50.00"));
    labelsDummy = new QLabel(tr("$"));
    buttons3 = new QPushButton(tr("Select From"));
    layout->addWidget(buttons3,2,0);
    layout->addWidget(labelsFromAccount,2,1);
    layout->addWidget(labelsFromBalance,2,2);
    layout->addWidget(labelsDummy,2,3);
    layout->addWidget(lineTransferAmount,2,3);
    buttons4 = new QPushButton(tr("Select To"));
    labelsToAccount = new QLabel(tr("Savings"));
    labelsToBalance = new QLabel(tr("  $200.00"));
    layout->addWidget(buttons4,3,0);
    layout->addWidget(labelsToAccount,3,1);
    layout->addWidget(labelsToBalance,3,2);
    layout->addWidget(labelsDummy,3,3);

    layout->setColumnStretch(0, 30);
    layout->setColumnStretch(1, 20);
    layout->setColumnStretch(2, 20);

    gridGroupBox->setLayout(layout);
}

