#include <QtGui>
#include <QtWidgets>

#include "account.h"

account::account()
{
    createHorizontalGroupBox();
    createGridGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(gridGroupBox);
    mainLayout->addWidget(horizontalGroupBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Account Info Window"));
}

void account::createGridGroupBox()
{
    gridGroupBox = new QGroupBox(tr("Checking Account"));
    QGridLayout *layout = new QGridLayout;

//    for (int i = 0; i < NumGridRows; ++i) {
//        labels[i] = new QLabel(tr("Line %1:").arg(i + 1));
//        lineEdits[i] = new QLineEdit;
//        layout->addWidget(labels[i], i + 1, 0);
//        layout->addWidget(lineEdits[i], i + 1, 1);
//    }
    QLabel *labelAccount = new QLabel(tr("Account"));
    QLabel *labelBalance = new QLabel(tr("Current Balance"));
    QLabel *labelUpdate = new QLabel(tr("Last Update"));
    QLabel *labelAccountName = new QLabel(tr("Checking"));
    QLabel *labelCheckingContent = new QLabel(tr("$500"));
    QLabel *labelUpdateTime = new QLabel(tr("March 16 2017 4:30pm"));

    layout->setColumnStretch(1, 10);
    layout->setColumnStretch(2, 20);
    layout->addWidget(labelAccount,1,0);
    layout->addWidget(labelBalance,2,0);
    layout->addWidget(labelUpdate,3,0);
    layout->addWidget(labelAccountName,1,1);
    layout->addWidget(labelCheckingContent,2,1);
    layout->addWidget(labelUpdateTime,3,1);
    gridGroupBox->setLayout(layout);
}

void account::createHorizontalGroupBox()
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
