#include <QObject>
#include <QWidget>
#include <QApplication>

#include "banksoftware.h"

bankSoftware::bankSoftware()
{
//    account* accountView = new account;
    history* historyView;
    historyView = new history;
    summary* summaryView;
    summaryView = new summary;
    //connect(summaryView->buttons1, SIGNAL(clicked()), this, SLOT(historyButtonClick()));

//    transfer* transferView = new transfer;
    summaryView->show();
    historyView->hide();
}

void createFormGroupBox()
{
    //may not need this
}

void createNavigationGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Navigate Buttons"));
    QHBoxLayout *layout = new QHBoxLayout;

    buttons1 = new QPushButton(tr("Transfer"),this);
    layout->addWidget(buttons1);
    buttons2 = new QPushButton(tr("Select"),this);
    layout->addWidget(buttons2);
    buttons3 = new QPushButton(tr("History"),this);
    layout->addWidget(buttons3);
    buttons4 = new QPushButton(tr("Logout"),this);
    layout->addWidget(buttons4);
    horizontalGroupBox->setLayout(layout);
}

void createSummaryGridGroupBox()
{
    summaryGridGroupBox = new QGroupBox(tr("Grid layout"));
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
    layout->setColumnStretch(1, 20);
    layout->setColumnStretch(2, 20);

    summaryGridGroupBox->setLayout(layout);
}

void createTransferGridGroupBox()
{
    transferGridGroupBox = new QGroupBox(tr("Choose Accounts, then enter amount to transfer"));
    QGridLayout *layout = new QGridLayout;

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

    transferGridGroupBox->setLayout(layout);
}

void createHistoryGridGroupBox()
{
    historyGridGroupBox = new QGroupBox(tr("Transaction History - Checking"));
    historyGridGroupBox *layout = new QGridLayout;

    QLabel *labelTransNum = new QLabel(tr("Transfer Num."));
    QLabel *labelOldBalance = new QLabel(tr("Previous Balance"));
    QLabel *labelNewBalance = new QLabel(tr("Current Balance"));
    QLabel *labelDateTitle = new QLabel(tr("Date-Time"));
    QLabel *labelTransNum1 = new QLabel(tr("#1"));
    QLabel *labelOldBalance1 = new QLabel(tr("$0"));
    QLabel *labelNewBalance1 = new QLabel(tr("$100"));
    QLabel *labelDate1 = new QLabel(tr("March 14 2017 2:00pm"));
    QLabel *labelTransNum2 = new QLabel(tr("#2"));
    QLabel *labelOldBalance2 = new QLabel(tr("$100"));
    QLabel *labelNewBalance2 = new QLabel(tr("$200"));
    QLabel *labelDate2 = new QLabel(tr("March 16 2017 4:30pm"));

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    layout->addWidget(labelTransNum,0,1);
    layout->addWidget(labelOldBalance,0,2);
    layout->addWidget(labelNewBalance,0,3);
    layout->addWidget(labelDateTitle,0,4);
    layout->addWidget(labelTransNum1,1,1);
    layout->addWidget(labelOldBalance1,1,2);
    layout->addWidget(labelNewBalance1,1,3);
    layout->addWidget(labelDate1,1,4);
    layout->addWidget(labelTransNum2,2,1);
    layout->addWidget(labelOldBalance2,2,2);
    layout->addWidget(labelNewBalance2,2,3);
    layout->addWidget(labelDate2,2,4);
    historyGridGroupBox->setLayout(layout);

}

void createBalancGridGroupBox()
{
//code last may be redundant of opening Window
}


void historyButtonClick()
{
    summaryView->hide();
    historyView->show();
}

void displaySummaryWindow()
{
    createNavigationGroupBox
    summaryGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(summaryGridGroupBox);
    mainLayout->addWidget(createNavigationGroupBox);
    setLayout(mainLayout);
    setWindowTitle(windowLabel);

}

void displayHistoryWindow()
{
    createNavigationGroupBox
    historyGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(historyGridGroupBox);
    mainLayout->addWidget(createNavigationGroupBox);
    setLayout(mainLayout);
    setWindowTitle(windowLabel);
 }
