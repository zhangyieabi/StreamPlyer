#include "playermainwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayerMainWin w;
    w.show();

    return a.exec();
}
