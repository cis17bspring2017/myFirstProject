#include <QtGui>
#include <QtWidgets>

#include "history.h"

history::history()
{
    createHorizontalGroupBox();
    createGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Account History Window"));
}

void history::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Transaction History - Checking"));
    QGridLayout *layout = new QGridLayout;

QLabel *labelTransNum = new QLabel(tr("Transfer Num."));
    QLabel *labelOldBalance = new QLabel(tr("Previous Balance"));
    QLabel *labelNewBalance = new QLabel(tr("Current Balance"));
    QLabel *labelDateTitle = new QLabel(tr("Date-Time"));
    QLabel *labelTransNum1 = new QLabel(tr("#1"));
    QLabel *labelOldBalance1 = new QLabel(tr("$0"));
    QLabel *labelNewBalance1 = new QLabel(tr("$100"));
    QLabel *labelDate1 = new QLabel(tr("March 14 2017 2:00pm"));
    QLabel *labelTransNum2 = new QLabel(tr("#2"));
    QLabel *labelOldBalance2 = new QLabel(tr("$100"));
    QLabel *labelNewBalance2 = new QLabel(tr("$200"));
    QLabel *labelDate2 = new QLabel(tr("March 16 2017 4:30pm"));

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    layout->addWidget(labelTransNum,0,1);
    layout->addWidget(labelOldBalance,0,2);
    layout->addWidget(labelNewBalance,0,3);
    layout->addWidget(labelDateTitle,0,4);
    layout->addWidget(labelTransNum1,1,1);
    layout->addWidget(labelOldBalance1,1,2);
    layout->addWidget(labelNewBalance1,1,3);
    layout->addWidget(labelDate1,1,4);
    layout->addWidget(labelTransNum2,2,1);
    layout->addWidget(labelOldBalance2,2,2);
    layout->addWidget(labelNewBalance2,2,3);
    layout->addWidget(labelDate2,2,4);
    gridGroupBox->setLayout(layout);
}

void history::createHorizontalGroupBox()
{
    horizontalGroupBox = new QGroupBox(tr("Navigation"));
    QHBoxLayout *layout = new QHBoxLayout;

//    for (int i = 0; i < NumButtons; ++i) {
//        buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
//        layout->addWidget(buttons[i]);
//    }
    QPushButton *buttons1 = new QPushButton(tr("Transfer"),this);
    QPushButton *buttons2 = new QPushButton(tr("History"),this);
    QPushButton *buttons3 = new QPushButton(tr("Summary"),this);
    layout->addWidget(buttons1);
    layout->addWidget(buttons2);
    layout->addWidget(buttons3);

    horizontalGroupBox->setLayout(layout);
}
