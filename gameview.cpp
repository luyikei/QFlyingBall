#include "gameview.h"
#include "common.h"
GameView::GameView(QWidget *parent) :
    QGraphicsView(parent),
    mx(1),
    my(1)
{
    setMouseTracking(true);
    scene = new QGraphicsScene(this);
    setScene(scene);
    QPixmap backgroundImage = QPixmap::fromImage(QImage(":/images/sunset.jpg").scaled(viewWidth,viewHeight));
    scene->addPixmap(backgroundImage);
    ball = new Ball();
    ball->setPos(20,400);
    scene->addItem(ball);
    cannon = new Cannon();
    scene->addItem(cannon);

    cannon->setPos(viewWidth/2,viewHeight-100);

}

void GameView::mousePressEvent(QMouseEvent *e)
{
    mx = qCos(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()))*2;
    my = qSin(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()))*2;
    launchMissile();
}

void GameView::mouseMoveEvent(QMouseEvent *e)
{
    cannon->setRotation(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()) * 180 / 3.1415 + 15);
}

void GameView::launchMissile()
{
    QGraphicsEllipseItem *missile;
    missile=scene->addEllipse(-(ballWidth/2),-(ballHeight/2),ballWidth,ballHeight,QPen(Qt::black),QBrush(Qt::black));
    missile->setPos(cannon->pos());
    missiles << missile;
}

void GameView::moveMissiles()
{
    int i=0;
    foreach(QGraphicsEllipseItem *missile,missiles){
        missile->moveBy(mx,my);
        if(missile->x() > viewWidth || missile->x() < 0 || missile->y() > viewHeight || missile->y() < 0){
            scene->removeItem(missile);
            missiles.removeAt(i);
            emit decreasePoint(-100);
            continue;
        }

        if(qPow(qAbs(ball->x()-missile->x()),2.0)+qPow(qAbs(ball->y()-missile->y()),2.0) <=
                qPow(ballWidth*2,2.0l)){
            ball->isHit=true;
            ball->update(ball->boundingRect());
        }
        i++;

    }
}
