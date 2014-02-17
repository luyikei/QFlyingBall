#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "ball.h"
#include "cannon.h"
class GameView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GameView(QWidget *parent = 0);

    QGraphicsScene *scene;
    Ball *ball;
    Cannon *cannon;
    QList<QGraphicsEllipseItem*>missiles;

    void launchMissile();
    void moveMissiles();
signals:
    void decreasePoint(int point);

public slots:

};

#endif // GAMEVIEW_H
