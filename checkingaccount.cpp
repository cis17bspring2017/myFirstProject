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

int Checkingaccount::getOverDraftFee()
{
    return overDraftFee;
}

QString Checkingaccount::getAccountType()
{
    return accountType;
}
