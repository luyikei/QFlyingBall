#ifndef CANNON_H
#define CANNON_H

#include <QGraphicsItem>
#include <QtGui>
#include <QList>
#include <QImage>
class Cannon : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Cannon(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
public slots:

private:
    QImage cannonIcon;

};

#endif // CANNON_H
