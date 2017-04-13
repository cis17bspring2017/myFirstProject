#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QWidget>

#include "checkingaccount.h"

class QPushButton;
class QLabel;
class QLineEdit;
class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    LoginWindow(Checkingaccount*);
    explicit LoginWindow(QDialog *parent = 0);

    void createLoginWindow();
    void setValidCredentials();
    bool getValidCredentials();
    void decrementLoginAttempts();
    int getLoginAttempts();

signals:

public slots:
    void checkNamePassword();
    void cancelLogin();

protected:
    int loginAttempts = 0;

private:
    QPushButton *loginButton;
    QPushButton *cancelButton;
    QLabel *userNameLabel;
    QLabel *userPasswordLabel;
    QLabel *attemptsLabel;
    QLineEdit *userNameLineEdit;
    QLineEdit *userPasswordLineEdit;
    bool validCredentials = 0;
    Checkingaccount *currentAccount;


};

#endif // LOGINWINDOW_H
