#ifndef BANKSOFTWARE_H
#define BANKSOFTWARE_H

#include <QObject>
#include <QWidget>

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
//class QMenu;
//class QMenuBar;
class QPushButton;
class bankSoftware


{
public:
    bankSoftware();

public slots:
    void historyButtonClick();
    void summaryButtonClick();
    void transferButtonClick();
    void accountButtonClick();
    void activateSummaryWindow();
    void activateHistoryWindow();
    void activateTransferWindow();
    void activateBalanceWindow();

private
    void createFormGroupBox();
    void createNavigationGroupBox();
    void createSummaryGridGroupBox();
    void createTransferGridGroupBox();
    void createHistoryGridGroupBox();
    void createBalancGridGroupBox();

    QGroupBox *horizontalGroupBox;
    QGroupBox *formGroupBox;
    QGroupBox *gridGroupBox;
    QLabel *labelsChecking;
    QLabel *labelsCheckingBalance;
    QLabel *labelsCheckingUpDate;

    QLabel *labelsSavings;
    QLabel *labelsSavingsBalance;
    QLabel *labelsSavingsUpDate;

    QPushButton *buttons1;// Summarry
    QPushButton *buttons2;// Balance
    QPushButton *buttons3;// Transfer
    QPushButton *buttons4;// History
    QPushButton *buttons5;// Logout
    QPushButton *buttons6;// Select Transfer From
    QPushButton *buttons7;// Select Transfer To
    QPushButton *buttons7;// Yes, Transfer
    QPushButton *buttons7;// No, Cancel

    QDialogButtonBox *buttonBox;
    QString summaryWindowLabel = "Account Summary Window";
    QString transferWindowLabel = "Account Transfer Window";
    QString historyWindowLabel = "Account History Window";
    QString accountWindowLabel = "Account Balance Window";



};

#endif // BANKSOFTWARE_H
