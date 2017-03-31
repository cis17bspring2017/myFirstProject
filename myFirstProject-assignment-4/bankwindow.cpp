//CIS-17B_Spring-2017_Jon LaRock, Greg Hanna
#include <QtWidgets>
#include <QWidget>
#include <QDialog>
#include <QString>
#include<QApplication>

#include "bankwindow.h"
#include "savingsaccount.h"
#include "checkingaccount.h"

//Checkingaccount*, Savingsaccount*
BankWindow::BankWindow(Checkingaccount* cAcc, Savingsaccount* sAcc)
//BankWindow::BankWindow()
{
    savAcc = sAcc;
    chkAcc = cAcc;

    mainLayout = new QVBoxLayout;
    windowLayout = new QGridLayout;
    setWindowLabel("Window");


    createBankGridGroupBox();
    summaryWindow();

//create accounts

    connect( buttonsNav2, SIGNAL(clicked()),
                this, SLOT(transferWindow()));
    connect( buttonsNav1, SIGNAL(clicked()),
                this, SLOT(summaryWindow()));//opening Window
    connect( buttonsNav3, SIGNAL(clicked()),
                this, SLOT(historyWindow()));
    connect( buttonsNav4, SIGNAL(clicked()),
                this, SLOT(exitWindow()));
    connect( buttonsChecking, SIGNAL(clicked()),
                this, SLOT(checkBalanceWindow()));
    connect( buttonsSavings, SIGNAL(clicked()),
                this, SLOT(savingsBalanceWindow()));
}


void BankWindow::createBankGridGroupBox()
 {  // creates gridGroupBox,widgets and windowLayout

        gridGroupBox = new QGroupBox();
        this->setWindowTitle(windowLabel);
        QFont font ("Tahoma",11,60);
        this->setFont(font);
        //column Labels
        for (int i = 0; i < numGridRows; i++)
        {
            columnLabels[i] = new QLabel(SummColNames[i]);
            windowLayout->addWidget(columnLabels[i],1,i);
        }
        //first row of fields
        for (int i = 0; i < numGridColumns; ++i)
        {
            rowOneLabels[i] = new QLabel(tr(""));
            windowLayout->addWidget(rowOneLabels[i],2,i);
        }
        //second row of fields
        for (int i = 0; i < numGridColumns; ++i)
        {
            rowTwoLabels[i] = new QLabel(tr(""));
            windowLayout->addWidget(rowTwoLabels[i],3,i);
        }
        //third row of fields
        for (int i = 0; i < numGridColumns; ++i)
        {
            rowThreeLabels[i] = new QLabel(tr(""));
            windowLayout->addWidget(rowThreeLabels[i],4,i);
        }

        buttonsNav1 = new QPushButton(tr("Summary"));
        buttonsNav2 = new QPushButton(tr("Transfer"));
        buttonsNav3 = new QPushButton(tr("History"));
        buttonsNav4 = new QPushButton(tr("Exit"));
        buttonsChecking = new QPushButton(tr("Checking"));
        buttonsSavings = new QPushButton(tr("Savings"));

        windowLayout->addWidget(buttonsSavings,3,0);
        windowLayout->addWidget(buttonsChecking,2,0);
        windowLayout->addWidget(buttonsNav1,5,1);
        windowLayout->addWidget(buttonsNav2,5,2);
        windowLayout->addWidget(buttonsNav3,5,3);
        windowLayout->addWidget(buttonsNav4,5,4);
        gridGroupBox->setLayout(windowLayout);

        setWindowTitle(windowLabel);

 }


 void BankWindow::summaryWindow()
 {  //setText() is used to change label text

     setWindowLabel("Summary Window");
     this->setWindowTitle(windowLabel);
     gridGroupBox->setTitle(tr("Select Account or choose other function."));

     //define column labels
     for (int i = 0; i < numGridRows; ++i)
     {
        columnLabels[i]->setText(SummColNames[i]);
     }

     //first row of fields
      rowOneLabels[0]->setText(tr(""));
      rowOneLabels[1]->setText(chkAcc->getAccountType());
      rowOneLabels[2]->setText(tr("$") + QString::number(chkAcc->getBalance()));
      rowOneLabels[3]->setText(chkAcc->getDate());
      rowOneLabels[4]->setText(chkAcc->getOwner());


     //second row of fields
      rowTwoLabels[0]->setText(tr(""));
      rowTwoLabels[1]->setText(savAcc->getAccountType());
      rowTwoLabels[2]->setText(tr("$") + QString::number(savAcc->getAccountBalance()));
      rowTwoLabels[3]->setText(savAcc->getUpdate());
      rowTwoLabels[4]->setText(tr(""));

     //third row of fields
     for (int i = 0; i < numGridColumns; ++i)
     {
        rowThreeLabels[i]->setText(tr(""));
        //windowLayout->addWidget(rowThreeLabels[i],3,i);
     }
     gridGroupBox->setLayout(windowLayout);
     setLayout(windowLayout);

     buttonsNav1->hide();
     buttonsNav2->show();
     buttonsNav3->hide();
     buttonsChecking->show();
     buttonsSavings->show();

     makeWindow();

 }

 void BankWindow::transferWindow()
 {
     //windowLayout->removeWidget(gridGroupBox);
    setWindowLabel("Transfer Window");

    this->setWindowTitle(windowLabel);

    for (int i = 0; i < numGridRows; i++)
    {
        columnLabels[i]->setText("");
    }
    //first row of fields
    for (int i = 0; i < numGridColumns; i++)
    {
        rowOneLabels[i]->setText("");
    }
    //second row of fields
    for (int i = 0; i < numGridColumns; i++)
    {
        rowTwoLabels[i]->setText("");
    }
    //third row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowThreeLabels[i]->setText("");
    }

    buttonsNav1->show();
    buttonsNav2->hide();
    buttonsNav3->hide();
    buttonsChecking->hide();
    buttonsSavings->hide();
    makeWindow();
 }


 void BankWindow::historyWindow()
 {
    setWindowLabel("History Window");

    //column Labels
    for (int i = 0; i < numGridRows; ++i)
    {
        columnLabels[i]->setText("");
    }

    //first row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowOneLabels[i]->setText("");
    }

    //second row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowTwoLabels[i]->setText("");
    }

    //third row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowThreeLabels[i]->setText("");
    }
    buttonsNav1->show();
    buttonsNav2->show();
    buttonsNav3->hide();
    buttonsChecking->hide();
    buttonsSavings->hide();

    makeWindow();
  }

 void BankWindow::exitWindow()
 {
     //close window, end app
     close();
 }

void BankWindow::setWindowLabel(QString newLabel)
{
    windowLabel = newLabel;
}

void BankWindow::checkBalanceWindow()
{
    setWindowLabel("Checking Balance Window");
    this->setWindowTitle(windowLabel);
    buttonsNav1->show();
    buttonsNav2->show();
    buttonsNav3->hide();
    buttonsChecking->hide();
    buttonsSavings->hide();

    setWindowLabel("Balance Window");

    //column Labels
    for (int i = 0; i < numColLabels; ++i)
    {
        columnLabels[i]->setText(chkBalColNames[i]);
    }

    //first row of fields
     rowOneLabels[0]->setText(chkAcc->getAccountType());
     rowOneLabels[1]->setText(chkAcc->getOwner());
     rowOneLabels[2]->setText(tr("$") + QString::number(chkAcc->getBalance()));
     rowOneLabels[3]->setText(tr("$") + QString::number(chkAcc->getOverDraftFee()));
     rowOneLabels[4]->setText(chkAcc->getDate());


    //second row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowTwoLabels[i]->setText("");
    }

    makeWindow();
}

void BankWindow::savingsBalanceWindow()
{
    setWindowLabel("Savings Balance Window");
    this->setWindowTitle(windowLabel);
    buttonsNav1->show();
    buttonsNav2->show();
    buttonsNav3->hide();
    buttonsChecking->hide();
    buttonsSavings->hide();

    setWindowLabel("Balance Window");

    //column Labels
    for (int i = 0; i < numColLabels; ++i)
    {
        columnLabels[i]->setText(chkBalColNames[i]);
    }

    //first row of fields
     rowOneLabels[0]->setText(savAcc->getAccountType());
     rowOneLabels[1]->setText(savAcc->getUserName());
     rowOneLabels[2]->setText(tr("$") + QString::number(savAcc->getAccountBalance()));
     rowOneLabels[3]->setText(QString::number(savAcc->getInterestRate()));
     rowOneLabels[4]->setText(savAcc->getUpdate());


    //second row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowTwoLabels[i]->setText("");
    }

    makeWindow();

}

void BankWindow::makeWindow()
{
   mainLayout->addWidget(gridGroupBox);
   setLayout(mainLayout);
}
