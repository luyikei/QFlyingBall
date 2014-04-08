#include "cannon.h"
#include "common.h"
Cannon::Cannon(QGraphicsItem *parent) :
    QGraphicsItem(parent),
    cannonIcon(":/images/cannon.png")
{
    setRotation(-30);
}

QRectF Cannon::boundingRect() const
{
    return QRectF(-cannonIcon.height()/4,-cannonIcon.width()/4,cannonIcon.height()/2,cannonIcon.width()/2);
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawImage(boundingRect().toRect(),cannonIcon);
}


