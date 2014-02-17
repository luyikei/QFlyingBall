#include "qflyingball.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFlyingBall w;
    w.show();

    return a.exec();
}
