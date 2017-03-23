//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#ifndef SUMMARY_H
#define SUMMARY_H

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

class summary : public QDialog
{
    Q_OBJECT

public:
    summary();

private:
    void createFormGroupBox();
    void createHorizontalGroupBox();
    void createGridGroupBox();

    enum { NumGridRows = 2, NumButtons = 4 };

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

#endif // SUMMARY_H
