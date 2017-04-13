#include "checkingaccount.h"

//Checkingaccount::Checkingaccount()
//{

//}

Checkingaccount::Checkingaccount(int IdNbr, QString owner
                                 , float balance, QString date)
{
    setAccountId(IdNbr);
    setOwner(owner);
    setBalance(balance);
    setDate(date);
    accountType = "Checking";

}

Checkingaccount::~Checkingaccount()
{
    //dtor
}

void Checkingaccount::setAccountId(int id)
{
    accountId = id;
}

void Checkingaccount::setOwner(QString owner)
{
    userName = owner;
}

void Checkingaccount::setBalance(float balance)
{
    accountBalance = balance;
}

void Checkingaccount::setDate(QString date)
{
    update = date;
}

int Checkingaccount::getAccountId()
{
    return accountId;
}

QString Checkingaccount::getOwner()
{
    return userName;
}

float Checkingaccount::getBalance()
{
    return accountBalance;
}

QString Checkingaccount::getDate()
{
    return update;
}

float Checkingaccount::getOverDraftFee()
{
    return overDraftFee;
}
float Checkingaccount::getOverDraft()
{
    return maxOverDraft;
}

QString Checkingaccount::getAccountType()
{
    return accountType;
}

void Checkingaccount::updateAttemptPassword(QString passwordEntry)
{
    QCharRef c = passwordEntry[passwordEntry.length()-1];
    QString attemptPassword = attemptPassword + c;

}

void Checkingaccount::checknamePassword(QString trialName,  QString trialPassword)
{
    QString storedUserName = this->getUserName();
    QString storedUserPassword = this->getUserPassword();


    if ((trialName == storedUserName)
            && (trialPassword == storedUserPassword))
        {
                 this->setCredentialCheck();
        }
}

QString Checkingaccount::getUserName()
{
    return userLoginName;
}

QString Checkingaccount::getUserPassword()
{
    return userLoginPassword;
}
void Checkingaccount::setCredentialCheck()
{
    credentialCheck = true;
    
}

bool Checkingaccount::getCredentialCheck()
{
    return credentialCheck;

}
