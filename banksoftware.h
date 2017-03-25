#ifndef BANKSOFTWARE_H
#define BANKSOFTWARE_H

#include <QObject>
#include <QWidget>

#include "account.h"
#include "summary.h"
#include "history.h"
#include "transfer.h"

class bankSoftware
{
public:
    bankSoftware();
    account* accountView;
    summary* summaryView;
    history* historyView;
    transfer* transferView;

public slots:
    void historyButtonClick(summary*, history*);
    void summaryButtonClick(history*, summary*);
    void transferButtonClick(history*, transfer*);
    void accountButtonClick(history*, account*);

};

#endif // BANKSOFTWARE_H
