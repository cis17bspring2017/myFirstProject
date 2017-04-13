#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <QString>

class Checkingaccount
{//checking class is currently used as base class
    //will fix in refactured version

public:
     Checkingaccount(int, QString, float, QString);
    ~Checkingaccount();
    void setAccountId(int);
    void setOwner(QString);
    void setBalance(float);
    void setDate(QString);
    void updateAttemptPassword(QString);
    void setCredentialCheck();
    bool getCredentialCheck();
    void checknamePassword(QString, QString);
    QString getUserName();
    QString getUserPassword();

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
    QString userLoginName = "Rich";
    QString userLoginPassword= "password";
    QString attemptPassword = "";
    QString attemptName;
    bool credentialCheck = false;
};

#endif // CHECKINGACCOUNT_H
