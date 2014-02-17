#ifndef QFLYINGBALL_H
#define QFLYINGBALL_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsEllipseItem>
#include "ball.h"
namespace Ui {
class QFlyingBall;
}

class QFlyingBall : public QMainWindow
{
    Q_OBJECT

public:
    explicit QFlyingBall(QWidget *parent = 0);
    ~QFlyingBall();
    void keyPressEvent(QKeyEvent *k);
    void timerEvent(QTimerEvent *te);

public slots:
    void changePoint(int point);
private:
    Ui::QFlyingBall *ui;


    QPropertyAnimation *anim;
    int randHeight;
    bool isHit;
    int point;



};

#endif // QFLYINGBALL_H
