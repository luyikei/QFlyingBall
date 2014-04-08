#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>

class Ball : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(bool isHit READ isHit WRITE setHit)
public:
    explicit Ball(QGraphicsItem *parent = 0);

    virtual QRectF boundingRect() const;
    QPointF calculateNewPos(int x);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void move();

    bool isHit() const
    {
        return m_isHit;
    }

signals:

    void increasePoint(int point);

public slots:

    void setHit(bool arg)
    {
        m_isHit = arg;
    }

private:

    int mx;
    int my;
    int randHeight;

    QColor currentColor();

    bool m_isHit;
};

#endif // BALL_H
