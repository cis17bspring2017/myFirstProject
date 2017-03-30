#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <QString>

class Savingsaccount
{
public:
    Savingsaccount();
    Savingsaccount(int, QString, float, QString);
    void setAccountId(int);
    void setOwner(QString);
    void setBalance(float);
    void setDate(QString);
    int getAccountId();
    float getAccountBalance();
    QString getUserName();
    QString getUpdate();
    float getInterestRate();
    QString getAccountType();

protected:
   int accountId = 0;
    float accountBalance= 0;
    QString userName;
    QString update;
    const double interestRate = 0.035; // percent as decimal
    QString accountType;
};

#endif // SAVINGSACCOUNT_H
