#include "checkingaccount.h"
#include "bankwindow.h"
#include "savingsaccount.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Checkingaccount* firstAccount = new Checkingaccount(1,  "I M Rich", 1000.25, "2017-3-27" );
    Savingsaccount* secondAccount = new Savingsaccount(2,  "I M Rich", 13777.25, "2017-2-31");

    BankWindow bob(firstAccount, secondAccount);

    bob.show();

    return app.exec();
}
