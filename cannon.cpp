#include "cannon.h"
#include "common.h"
Cannon::Cannon(QGraphicsItem *parent) :
    cannonIcon(":/cannon.png"),
    QGraphicsItem(parent)
{
}

QRectF Cannon::boundingRect() const
{
    return QRectF(0,0,cannonIcon.height(),cannonIcon.width());
}

void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawImage(boundingRect().toRect(),cannonIcon);
}


