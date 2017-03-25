#include <QObject>
#include <QWidget>
#include <QApplication>

#include "banksoftware.h"

bankSoftware::bankSoftware()
{
// create pointers then create windows
    history* historyView;
    historyView = new history;
    summary* summaryView;
    summaryView = new summary;
//    transfer* transferView = new transfer;
//    account* accountView = new account;
    //setting defaults for the application,
    //after creating the windows, hide all but the summary window
    summaryView->show();
    historyView->hide();
}

void historyButtonClick()
{//this function should be called when
 //  the history button is clicked on the summary window
    summaryView->hide();
    historyView->show();
}
