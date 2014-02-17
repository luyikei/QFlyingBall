#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

class Ball : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    explicit Ball(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    QPointF calculateNewPos(int x);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    bool isHit;

    void move();

signals:
    void increasePoint(int point);
public slots:

private:

    int mx;
    int my;
    int randHeight;

    QColor currentColor();

};

#endif // BALL_H
