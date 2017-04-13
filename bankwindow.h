#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QDialog>
#include <QString>
#include<QApplication>
#include <QtWidgets>

#include "checkingaccount.h"
#include "savingsaccount.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QGroupBox;
class QBoxLayout;
class QDialog;
class QComboBox;



class  BankWindow : public QDialog
{
    Q_OBJECT

public:
    //BankWindow();
    BankWindow(Checkingaccount* , Savingsaccount* );

    void transferError();
    void transferMoney(float, float);
    void selectError();
    void loginToBank(Checkingaccount*);

    enum
    {
        numNavButtons = 4,
        numColLabels = 5,
        numGridRows = 5,
        numGridColumns = 5
    };

public slots:
    void transferWindow();
    void summaryWindow();
    void historyWindow();
    void exitWindow();
    void checkBalanceWindow();
    void savingsBalanceWindow();
    void chooseToAccount(int);
    void chooseFromAccount(int);
    void tranferFunds();
    void cancelTransfer();

private:
    void createBankGridGroupBox();
    void setWindowLabel(QString);
    void makeWindow();

    QPushButton *buttonsNav1;
    QPushButton *buttonsNav2;
    QPushButton *buttonsNav3;
    QPushButton *buttonsNav4;
    QPushButton *buttonsChecking;
    QPushButton *buttonsSavings;
    QPushButton *buttonsYesTransfer;
    QPushButton *buttonsNoCancel;

    QLineEdit *transferAmount;
    QLabel *rowOneLabels[numColLabels];
    QLabel *rowTwoLabels[numColLabels];
    QLabel *rowThreeLabels[numColLabels];
    QLabel *columnLabels[numColLabels];
    QGridLayout *windowLayout;
    QVBoxLayout *mainLayout;
    QGroupBox *gridGroupBox;
    QComboBox *toSelectCombobox;
    QComboBox *fromSelectCombobox;
    QLineEdit *transferLineEdit;
    QLabel *fillLabels;
    QLineEdit *lineEdits[numGridRows];
    QString SummColNames[numColLabels] =
    {" ", "Account", "Balance", "Updated", " "};
    QString chkBalColNames[numColLabels] =
            {"Account", "Owner", "Balance", "OverDraft Fee", "Last Update"};
    QString savBalColNames[numColLabels] =
            {"Account", "Owner", "Balance", "Interest Rate", "Last Update"};
    QString transferColNames[numColLabels] =
            {"", "Account", "Balance", "Amount to \nTransfer", ""};

    QString navButtonNames[numNavButtons] = {"Summary", "Transfer", "History", "Exit"};
    QString windowLabel;
    Checkingaccount* chkAcc;
    Savingsaccount* savAcc;
};

#endif // BANKWINDOW_H
