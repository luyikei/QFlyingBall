#include "gameview.h"
#include "common.h"
GameView::GameView(QWidget *parent) :
    QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    ball(new Ball()),
    cannon(new Cannon()),
    moveByX(1),
    moveByY(1)
{
    setMouseTracking(true);

    QPixmap backgroundImage = QPixmap::fromImage(QImage(":/images/sunset.jpg").scaled(viewWidth,viewHeight));
    scene->addPixmap(backgroundImage);
    setScene(scene);

    ball->setPos(20,400);
    scene->addItem(ball);

    cannon->setPos(viewWidth/2,viewHeight-100);
    scene->addItem(cannon);

}

void GameView::mousePressEvent(QMouseEvent *e)
{
    moveByX = qCos(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()))*2;
    moveByY = qSin(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()))*2;
    launchMissile();
}

void GameView::mouseMoveEvent(QMouseEvent *e)
{
    cannon->setRotation(qAtan2(e->y() - cannon->y(),e->x() - cannon->x()) * 180 / 3.1415 + 15);
}

void GameView::launchMissile()
{
    QGraphicsEllipseItem *missile=scene->addEllipse(centerPosition(ballWidth, ballHeight),QPen(Qt::black),QBrush(Qt::black));;
    missile->setPos(cannon->pos());
    missiles << missile;
}

void GameView::moveMissiles()
{
    int i=0;
    foreach (QGraphicsEllipseItem *missile,missiles) {
        missile->moveBy(moveByX,moveByY);
        if (isNotPositionIn(missile->x(), missile->y(), viewWidth, viewHeight)) {
            // remove missile
            scene->removeItem(missile);
            missiles.removeAt(i);

            // emit
            emit decreasePoint(-100);
            continue;
        }

        // Check that ball is Hit by Pythagorean theorem
        if (isCollided(ball->x(), ball->y(), missile->x(), missile->y(), ballWidth)) {
            ball->setHit(true);
            ball->update(ball->boundingRect());
        }
        i++;

    }
}
