#include <QtWidgets>
#include <QWidget>
#include <QDialog>
#include <QString>
#include<QApplication>

#include "bankwindow.h"
#include "account.h"
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
    connect( toSelectCombobox, SIGNAL(currentIndexChanged(int)),
                this, SLOT(chooseToAccount(int)));
    connect( fromSelectCombobox, SIGNAL(currentIndexChanged(int)),
                this, SLOT(chooseFromAccount(int)));
    connect( buttonsYesTransfer, SIGNAL(clicked()),
                this, SLOT(tranferFunds()));
    connect( buttonsNoCancel, SIGNAL(clicked()),
                this, SLOT(cancelTransfer()));
}


void BankWindow::createBankGridGroupBox()
 {  // creates gridGroupBox,widgets and windowLayout

        gridGroupBox = new QGroupBox();
        this->setWindowTitle(windowLabel);
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
        buttonsYesTransfer = new QPushButton(tr("Yes, Transfer"));
        buttonsNoCancel = new QPushButton(tr("No, Cancel"));
        fromSelectCombobox = new QComboBox;
        fromSelectCombobox->insertItem(0 ,"Select Account");
        fromSelectCombobox->insertItem(1, "Checking");
        fromSelectCombobox->insertItem(2, "Savings");
        toSelectCombobox = new QComboBox;
        toSelectCombobox->insertItem(0 ,"Select Account");
        toSelectCombobox->insertItem(1, "Checking");
        toSelectCombobox->insertItem(2, "Savings");
        transferLineEdit = new QLineEdit;
        //transferLineEdit->setValidator(new QDoubleValidator(0, 10000000, this));//not expected to have more than $10,000,000
        QDoubleValidator* doubleValidator = new QDoubleValidator(0, 9999999, 2, this);
        doubleValidator->setNotation(QDoubleValidator::StandardNotation);
        transferLineEdit->setValidator(doubleValidator);
        //http://stackoverflow.com/questions/10119310/qdoublevalidator-is-not-working

        windowLayout->addWidget(buttonsSavings,2,0);
        windowLayout->addWidget(buttonsChecking,3,0);
        windowLayout->addWidget(buttonsNav1,5,1);
        windowLayout->addWidget(buttonsNav2,5,2);
        windowLayout->addWidget(buttonsNav3,5,3);
        windowLayout->addWidget(buttonsNav4,5,4);
        windowLayout->addWidget(fromSelectCombobox,2,0);
        windowLayout->addWidget(toSelectCombobox,3,0);
        windowLayout->addWidget(buttonsYesTransfer,4,2);
        windowLayout->addWidget(buttonsNoCancel,4,3);
        windowLayout->addWidget(transferLineEdit,2,3);

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
      rowOneLabels[2]->setText(QString::number(chkAcc->getBalance()));
      rowOneLabels[3]->setText(chkAcc->getDate());
      rowOneLabels[4]->setText(tr(""));


     //second row of fields
      rowTwoLabels[0]->setText(tr(""));
      rowTwoLabels[1]->setText(savAcc->getAccountType());
      rowTwoLabels[2]->setText(QString::number(savAcc->getAccountBalance()));
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
     buttonsNav4->show();
     toSelectCombobox->hide();
     fromSelectCombobox->hide();
     buttonsYesTransfer->hide();
     buttonsNoCancel->hide();
     buttonsChecking->show();
     buttonsSavings->show();
     transferLineEdit->hide();
     makeWindow();

 }

 void BankWindow::transferWindow()
 {
     //windowLayout->removeWidget(gridGroupBox);
    setWindowLabel("Transfer Window");

    this->setWindowTitle(windowLabel);

    for (int i = 0; i < numGridRows; i++)
    {
        columnLabels[i]->setText(transferColNames[i]);
    }
    //first row of fields
    fromSelectCombobox->show();
    for (int i = 0; i < numGridColumns; i++)
    {
        rowOneLabels[i]->setText("");
    }
    //second row of fields
    toSelectCombobox->show();
    for (int i = 0; i < numGridColumns; i++)
    {
        rowTwoLabels[i]->setText("");
    }
    //third row of fields
    for (int i = 0; i < numGridColumns; ++i)
    {
        rowThreeLabels[i]->setText("");
    }

    buttonsNav1->hide();
    buttonsNav2->hide();
    buttonsNav3->hide();
    buttonsNav4->hide();
    buttonsChecking->hide();
    buttonsSavings->hide();
    toSelectCombobox->show();
    fromSelectCombobox->show();
    buttonsYesTransfer->show();
    buttonsNoCancel->show();
    transferLineEdit->show();

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
    buttonsNav4->show();
    buttonsChecking->hide();
    buttonsSavings->hide();
    toSelectCombobox->hide();
    fromSelectCombobox->hide();

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
    buttonsNav1->show();
    buttonsNav2->show();
    buttonsNav3->show();
    buttonsNav4->show();
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
     rowOneLabels[2]->setText(QString::number(chkAcc->getBalance()));
     rowOneLabels[3]->setText(QString::number(chkAcc->getOverDraftFee()));
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
    buttonsNav1->show();
    buttonsNav2->show();
    buttonsNav3->show();
    buttonsNav4->show();
    buttonsChecking->hide();
    buttonsSavings->hide();

    setWindowLabel("Balance Window");

    //column Labels
    for (int i = 0; i < numColLabels; ++i)
    {
        columnLabels[i]->setText(savBalColNames[i]);
    }

    //first row of fields
     rowOneLabels[0]->setText(savAcc->getAccountType());
     rowOneLabels[1]->setText(savAcc->getUserName());
     rowOneLabels[2]->setText(QString::number(savAcc->getAccountBalance()));
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

void BankWindow::chooseToAccount(int index)
{
        switch (index)
        {
        case 0: //clear account info
            rowTwoLabels[2]->setText("");
        break;
        case 1: //read checking account info
            rowTwoLabels[2]->setText(QString::number(chkAcc->getBalance()));
        break;
        case 2: //read savings accoutn info
            rowTwoLabels[2]->setText(QString::number(savAcc->getAccountBalance()));
        break;
         }
        if (index == fromSelectCombobox->currentIndex())
        {
            fromSelectCombobox->setCurrentIndex(0);
        }
        if (index != toSelectCombobox->currentIndex())
        {
            toSelectCombobox->setCurrentIndex(index);
        }
}

void BankWindow::chooseFromAccount(int index)
{
    switch (index)
    {
    case 0: //clear account info
        rowOneLabels[2]->setText("");
    break;
    case 1: //read checking account info
        rowOneLabels[2]->setText(QString::number(chkAcc->getBalance()));
    break;
    case 2: //read savings accoutn info
        rowOneLabels[2]->setText(QString::number(savAcc->getAccountBalance()));
    break;

    }
    if (index == toSelectCombobox->currentIndex())
    {
        toSelectCombobox->setCurrentIndex(0);
    }
    if (index != fromSelectCombobox->currentIndex())
    {
        fromSelectCombobox->setCurrentIndex(index);
    }
}

void BankWindow::tranferFunds()
{
        float toSum = 0;
        float fromSum = 0;
        float fromAccountBalance = (rowOneLabels[2]->text().toFloat());
        float toAccountBalance = (rowTwoLabels[2]->text().toFloat());
        float transferFunds =(transferLineEdit->text().toFloat());

        if (transferFunds < 0)
        {
            transferLineEdit->setText(tr("0.0"));
        }
        else if (transferFunds  > (fromAccountBalance
                              + chkAcc->getOverDraftFee()
                              + chkAcc->getOverDraft()))
                //transferring too much
        {
            transferError();
        }
        else if (((fromAccountBalance) - transferFunds) > 0)
        {
                    toSum = toAccountBalance + transferFunds;
                    fromSum = fromAccountBalance - transferFunds;
                    transferLineEdit->setText(tr(""));
                    transferMoney(toSum, fromSum);
                    cancelTransfer(); //after transfer reset window and return
         }
        else if (transferFunds  < (fromAccountBalance
                           + chkAcc->getOverDraftFee()
                           + chkAcc->getOverDraft()) && ((fromAccountBalance -transferFunds)< 0) )
        {
            toSum = toAccountBalance + transferFunds;
            fromSum = fromAccountBalance
                    - (transferFunds + chkAcc->getOverDraftFee());
            transferLineEdit->setText(tr(""));
            transferMoney(toSum, fromSum);
            cancelTransfer(); //after transfer reset window and return

        }

}

void BankWindow::transferError()
{
     transferLineEdit->setText(tr("0.0"));
     fromSelectCombobox->setCurrentIndex(0);
     toSelectCombobox->setCurrentIndex(0);
     rowOneLabels[2]->setText(tr("   Insufficient"));
     rowTwoLabels[2]->setText(tr("       Funds!"));

}
void BankWindow::transferMoney(float newToBalance, float newFromBalance)
{
    if (toSelectCombobox->currentIndex() == 1)
    {
        chkAcc->setBalance(newFromBalance);
        savAcc->setBalance(newToBalance);
        chkAcc->setDate((QDate::currentDate().toString(Qt::ISODate)));
        savAcc->setDate((QDate::currentDate().toString(Qt::ISODate)));

    }
    else
    {
        savAcc->setBalance(newFromBalance);
        chkAcc->setBalance(newToBalance);
        chkAcc->setDate((QDate::currentDate().toString(Qt::ISODate)));
        savAcc->setDate((QDate::currentDate().toString(Qt::ISODate)));

     }
    chooseToAccount(0);
    chooseFromAccount(0);
}

void BankWindow::cancelTransfer()
{
    transferLineEdit->setText(tr(""));
    fromSelectCombobox->setCurrentIndex(0);
    toSelectCombobox->setCurrentIndex(0);
    summaryWindow();
}
