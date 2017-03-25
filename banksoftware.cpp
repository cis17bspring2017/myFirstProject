#include <QObject>
#include <QWidget>
#include <QApplication>

#include "banksoftware.h"

bankSoftware::bankSoftware()
{
//    account* accountView = new account;
    history* historyView;
    historyView = new history;
    summary* summaryView;
    summaryView = new summary;
    //connect(summaryView->buttons1, SIGNAL(clicked()), this, SLOT(historyButtonClick()));

//    transfer* transferView = new transfer;
    summaryView->show();
    historyView->hide();
}

void historyButtonClick()
{
    summaryView->hide();
    historyView->show();
}
