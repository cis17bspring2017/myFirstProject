//reference http://www.ics.com/files/qtdocs/layouts-basiclayouts.html
//CIS17B, Spring 2017 Jon LaRock and Greg Hanna
#include <Qwidget>
#include <QApplication>


#include "banksoftware.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    bankSoftware();

    return app.exec();
}



