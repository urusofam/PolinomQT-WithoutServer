#include "interface.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tinterface w;
    w.show();
    return a.exec();
}
