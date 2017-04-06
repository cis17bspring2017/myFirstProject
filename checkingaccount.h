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
        float getOverDraftFee();
        float getOverDraft();
        QString getAccountType();

    protected:
        QString accountType;
        const float overDraftFee = 35; //in dollars
        int accountId = 0;
        float accountBalance= 0;
        QString userName;
        QString update;
        float maxOverDraft = 300.00;


    private:
};

#endif // CHECKINGACCOUNT_H
