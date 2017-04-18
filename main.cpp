#include "checkingaccount.h"
#include "bankwindow.h"
#include "savingsaccount.h"
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Checkingaccount* firstAccount = new Checkingaccount(1,  "Rich", 1000.25, "2017-3-27" );
    Savingsaccount* secondAccount = new Savingsaccount(2,  "Rich", 13777.25, "2017-2-31");

    LoginWindow login(firstAccount);
    login.show();

    login.exec();


    if (firstAccount->getCredentialCheck() == true)
    {
        BankWindow bob(firstAccount, secondAccount);
        bob.show();
        bob.exec();
    }
    return app.exec();
}
