#include "savingsaccount.h"

Savingsaccount::Savingsaccount(int IdNbr, QString owner
                               , float balance, QString date)//constructor
{
    setAccountId(IdNbr);
    setOwner(owner);
    setBalance(balance);
    setDate(date);
    accountType = "Savings";
}

void Savingsaccount::setAccountId(int id)
{
    accountId = id;
}

void Savingsaccount::setOwner(QString owner)
{
    userName = owner;
}

void Savingsaccount::setBalance(float balance)
{
    accountBalance = balance;
}

void Savingsaccount::setDate(QString date)
{
    update = date;
}

int Savingsaccount::getAccountId()
{
    return accountId;
}

float Savingsaccount::getAccountBalance()
{
    return accountBalance;
}

QString Savingsaccount::getUserName()
{
    return userName;
}

QString Savingsaccount::getUpdate()
{
    return update;
}

float Savingsaccount::getInterestRate()
{
    return interestRate;
}

QString Savingsaccount::getAccountType()
{
    return accountType;
}
