#-------------------------------------------------
#
# Project created by QtCreator 2014-02-15T14:06:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFlyingBall
TEMPLATE = app


SOURCES += main.cpp\
        qflyingball.cpp \
    ball.cpp \
    gameview.cpp \
    cannon.cpp

HEADERS  += qflyingball.h \
    ball.h \
    common.h \
    gameview.h \
    cannon.h

FORMS    += qflyingball.ui

RESOURCES += \
    resources.qrc
