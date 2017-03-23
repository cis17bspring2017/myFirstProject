//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#ifndef TRANSFER_H
#define TRANSFER_H

#include <QObject>
#include <QWidget>

#include <QDialog>
#include <QString>

class QAction;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
//class QMenu;
//class QMenuBar;
class QPushButton;

class transfer : public QDialog
{
    Q_OBJECT

public:
    transfer();

private:
    //void createMenu();
    void createFormGroupBox();
    void createHorizontalGroupBox();
    void createGridGroupBox();

    enum { NumGridRows = 2, NumButtons = 4 };


    //QMenu *NavigateMenu;
    //QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QGroupBox *formGroupBox;
    QGroupBox *gridGroupBox;
    QLabel *labelsFromAccount;
    QLabel *labelsFromBalance;
    QLabel *labelsToAccount;
    QLabel *labelsToBalance;
    QLabel *labelsDummy;  //placeholder, used to display"$"
    QLineEdit *lineTransferAmount;
    QPushButton *buttons1;
    QPushButton *buttons2;
    QPushButton *buttons3;
    QPushButton *buttons4;
    QDialogButtonBox *buttonBox;
    QString windowLabel = "Account Transfer Window";

};

#endif // TRANSFER_H
