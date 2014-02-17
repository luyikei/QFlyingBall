#include "ball.h"
#include "common.h"

#include <QtGui>
Ball::Ball(QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent),isHit(false),mx(2),my(2),randHeight(300)
{
}

QRectF Ball::boundingRect() const
{
    return QRectF(-(ballWidth/2),-(ballHeight/2),ballWidth,ballHeight);
}

QPointF Ball::calculateNewPos(int x)
{
    double nx=x+mx,ny;
    double midw=viewWidth/2;
    ny=(nx-midw)*(nx-midw)/randHeight;
    if(nx > viewWidth || nx < 0 || ny > viewHeight || ny < 0){
        randHeight=(qrand()%500)+100;
        setBrush(Qt::blue);
        if(isHit){
            emit increasePoint(300);
            isHit=false;
        }
        return QPointF(20,ny);

    }
    return QPointF(nx,ny);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
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
    return (isHit)?Qt::blue:Qt::blue;


}
