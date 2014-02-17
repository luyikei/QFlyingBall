#include "cannon.h"
#include "common.h"
Cannon::Cannon(QGraphicsItem *parent) :
    cannonIcon(":/images/cannon.png"),
    QGraphicsItem(parent)
{
    setRotation(-30);
}

QRectF Cannon::boundingRect() const
{
    return QRectF(-cannonIcon.height()/4,-cannonIcon.width()/4,cannonIcon.height()/2,cannonIcon.width()/2);
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect().toRect(),cannonIcon);
}


