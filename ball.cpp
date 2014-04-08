#include "ball.h"
#include "common.h"

#include <QtGui>
Ball::Ball(QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent),
    mx(2),
    my(2),
    randHeight(300),
    m_isHit(false)
{
}

QRectF Ball::boundingRect() const
{
    return centerPosition(ballWidth,ballHeight);
}

QPointF Ball::calculateNewPos(int x)
{
    double newX=x+mx,newY;
    double midw=viewWidth/2;

    newY=(newX-midw)*(newX-midw)/randHeight;

    if(isNotPositionIn(newX, newY, viewWidth, viewHeight, newY)) {
        randHeight=(qrand()%500)+100;
        setBrush(Qt::blue);

        if(isHit()){
            emit increasePoint(300);
            setHit(false);
        }
        //Rest Position
        return QPointF(20,newY);

    }
    return QPointF(newX,newY);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF rect = boundingRect();
    QPen pen(currentColor());
    QBrush brush(currentColor());

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(rect);
}

void Ball::move()
{
    QPropertyAnimation* anim = new QPropertyAnimation(this, "pos");
    anim->setDuration(10);
    anim->setStartValue(pos());
    anim->setEndValue(calculateNewPos(x()));
    anim->start();
}

QColor Ball::currentColor()
{
    return (isHit())?Qt::red:Qt::darkBlue;
}
