#ifndef TRANSFER_H
#define TRANSFER_H

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
    void createFormGroupBox();
    void createHorizontalGroupBox();
    void createGridGroupBox();

    enum { NumGridRows = 2, NumButtons = 4 };

    QGroupBox *horizontalGroupBox;
    QGroupBox *formGroupBox;
    QGroupBox *gridGroupBox;
    QLabel *labelsChecking;
    QLabel *labelsCheckingBalance;
    QLabel *labelsCheckingUpDate;

    QLabel *labelsSavings;
    QLabel *labelsSavingsBalance;
    QLabel *labelsSavingsUpDate;

    QPushButton *buttons1;
    QPushButton *buttons2;
    QPushButton *buttons3;
    QPushButton *buttons4;
    QDialogButtonBox *buttonBox;
    QString windowLabel = "Account Transfer Window";

};

#endif // TRANSFER_H
