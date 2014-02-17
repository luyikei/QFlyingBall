#include "gameview.h"
#include "common.h"
GameView::GameView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    setScene(scene);
    ball = new Ball();
    ball->setPos(20,400);
    scene->addItem(ball);
    cannon = new Cannon();
    scene->addItem(cannon);

    cannon->setPos(viewWidth/2,viewHeight-400);

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
        missile->moveBy(1,-1);
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

    }
    i++;
}
