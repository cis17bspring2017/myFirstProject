#include <QCoreApplication>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>

#include "loginwindow.h"

LoginWindow::LoginWindow(Checkingaccount* thisAccount)
{
    loginAttempts = 3;
    currentAccount = thisAccount;
    QString tempValue = "";
    createLoginWindow();
    this->show();
    connect(cancelButton,SIGNAL(clicked()), this, SLOT(cancelLogin()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(checkNamePassword()));
}

void LoginWindow::createLoginWindow()
{
    setFixedSize(225,150);
    QFont font ("Tahoma",10,60);
    this->setFont(font);
    this->setWindowTitle("Form Login");

    loginButton = new QPushButton("&Login", this);
    loginButton->setGeometry(30,110, 75,25);
    cancelButton = new QPushButton("&Cancel", this);
    cancelButton->setGeometry(120,110, 75, 25);
    userNameLabel = new QLabel("User Name:", this);
    userNameLabel->setGeometry(20, 10,75,30);
    userPasswordLabel = new QLabel("Pasword:", this);
    userPasswordLabel->setGeometry(20, 50,75,30);
    userPasswordLineEdit = new QLineEdit("",this);
    userPasswordLineEdit->setGeometry(100,50,100,25);
    userPasswordLineEdit->setEchoMode(QLineEdit::Password);
    userNameLineEdit = new QLineEdit("", this);
    userNameLineEdit->setGeometry(100,10,100,25);
    attemptsLabel = new QLabel(QString::number(loginAttempts) + " attempts left.",this);
    attemptsLabel->setGeometry( 50,80,100,25);
    setTabOrder(userNameLineEdit, userPasswordLineEdit);
    setTabOrder(userPasswordLineEdit, loginButton);
    setTabOrder(loginButton,cancelButton );

}

void LoginWindow::checkNamePassword()
{
    currentAccount->checknamePassword
            (userNameLineEdit->text(), userPasswordLineEdit->text());
    if (currentAccount->getCredentialCheck() == true)
    {
        currentAccount->setCredentialCheck();
       close();
    }

    else if (loginAttempts == 1)
        {
            close();
            parentWidget()->close();
        }

   else
    {
        decrementLoginAttempts();
        attemptsLabel->setText(QString::number(loginAttempts) + " attempts left.");
        userPasswordLineEdit->setText(tr(""));
        userNameLineEdit->setText(tr(""));
        userNameLineEdit->setFocus();

    }

}

void LoginWindow::cancelLogin()
{
    close();
    parentWidget()->close();
}


  void LoginWindow::decrementLoginAttempts()
  {
        loginAttempts = loginAttempts - 1;

  }

  int LoginWindow::getLoginAttempts()
  {
      return loginAttempts;
  }
