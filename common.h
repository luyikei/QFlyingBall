#ifndef COMMON_H
#define COMMON_H
#include <QRectF>
#include <QtCore/qmath.h>
static const int viewHeight=500;
static const int viewWidth=500;
static const int ballWidth=10;
static const int ballHeight=10;

inline QRectF centerPosition(qreal w, qreal h){
    return QRectF(-(w/2),-(h/2),w,h);
}

inline bool isNotPositionIn(qreal x, qreal y, qreal w, qreal h){
    return (x > w || x < 0 || y > h || y < 0);
}

// Pythagorean theorem
inline bool isCollided(qreal lx, qreal ly, qreal rx, qreal ry, int diameter){
    return (qPow(qAbs(lx-rx),2.0) + qPow(qAbs(ly-ry),2.0) <= qPow(diameter*2,2.0));
}

#endif // COMMON_H

