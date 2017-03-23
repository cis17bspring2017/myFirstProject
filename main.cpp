//reference http://www.ics.com/files/qtdocs/layouts-basiclayouts.html
//CIS17B, Spring 2017 Jon LaRock and Greg Hanna
#include <Qwidget>
#include <QApplication>


#include "summary.h"
#include "transfer.h"
#include "history.h"
#include "account.h"

int summaryWindow();
int transferWindow();
int historyWindow();
int accountWindow();
void changeWindow(int);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int newWindowNumber = 1;
    changeWindow(newWindowNumber);
    newWindowNumber = 2;
        changeWindow(newWindowNumber);
        newWindowNumber = 3;
            changeWindow(newWindowNumber);
            newWindowNumber = 4;
                changeWindow(newWindowNumber);
    return app.exec();
}

int summaryWindow()
{
    summary newSummaryWindow;

    return newSummaryWindow.exec();

}

int transferWindow()
{
    transfer newTransferWindow;
    return newTransferWindow.exec();
}

int historyWindow()
{
    history newHistoryWindow;
    return newHistoryWindow.exec();
}

int accountWindow()
{
    account newAccountWindow;
    return newAccountWindow.exec();
}

void changeWindow(int windowNumber)
{
    switch(windowNumber)
    {
        case 1:
            summaryWindow();
            //call code to create Opening Window
        break;
        case 2:
            transferWindow();
            //call code to create Account Transfer Window
        break;
        case 3:
            historyWindow();
            //call code to create Account history window
        break;
        case 4:
            accountWindow();
            //call code to create Account information window
        break;
        case 5: //exit or logout
            break;
        default:
            summaryWindow();
        break;
    }
}

