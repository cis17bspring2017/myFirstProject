//CIS-17B_Spring-2017_Jon LaRock, Greg Hanna
#include "checkingaccount.h"
#include "bankwindow.h"
#include "savingsaccount.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Checkingaccount* firstAccount = new Checkingaccount(1,  "I M Rich", 1000.25, "3/27/2017" );
    Savingsaccount* secondAccount = new Savingsaccount(2,  "I M Rich", 13777.25, "2/31/2017");

    BankWindow bob(firstAccount, secondAccount);

    bob.show();

    return app.exec();
}
