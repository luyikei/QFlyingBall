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
    for(int i=0;i<missiles.size();i++){
        missiles[i]->moveBy(1,-1);
        if(missiles[i]->x() > viewWidth || missiles[i]->x() < 0 || missiles[i]->y() > viewHeight || missiles[i]->y() < 0){
            scene->removeItem(missiles[i]);
            missiles.erase(missiles.begin()+i);
            emit decreasePoint(-100);
            continue;
        }

        if(qPow(qAbs(ball->x()-missiles[i]->x()),2.0)+qPow(qAbs(ball->y()-missiles[i]->y()),2.0) <=
                qPow(ballWidth*2,2.0l)){
            ball->isHit=true;
            ball->update(ball->boundingRect());
        }
    }
}
