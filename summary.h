//CIS17B, Spring 2017 Jon LaRock and Greg Hanna

#ifndef SUMMARY_H
#define SUMMARY_H

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
public slots:
    void switchWindow();

private:
    //void createMenu();
    void createFormGroupBox();
    void createHorizontalGroupBox();
    void createGridGroupBox();
    void exitWindow();

    enum { NumGridRows = 2, NumButtons = 4 };


    //QMenu *NavigateMenu;
    //QMenuBar *menuBar;
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
    QString windowLabel = "Account Summary Window";

};

#endif //SUMMARY_H
