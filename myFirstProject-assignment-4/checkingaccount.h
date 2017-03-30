#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <QString>

class Checkingaccount
{
    public:
        //Checkingaccount();
        Checkingaccount(int, QString, float, QString);
        ~Checkingaccount();
        void setAccountId(int);
        void setOwner(QString);
        void setBalance(float);
        void setDate(QString);
        int getAccountId();
        QString getOwner();
        float getBalance();
        QString getDate();
        int getOverDraftFee();
        QString getAccountType();

    protected:
        QString accountType;
        const int overDraftFee = 30; //in dollars
        int accountId = 0;
        double accountBalance= 0;
        QString userName;
        QString update;


    private:
};

#endif // CHECKINGACCOUNT_H
