#include "qflyingball.h"
#include "ui_qflyingball.h"
#include "common.h"
QFlyingBall::QFlyingBall(QWidget *parent) :
    QMainWindow(parent),
    point(0),
    ui(new Ui::QFlyingBall)
{
    ui->setupUi(this);
    connect(ui->gameView,SIGNAL(decreasePoint(int)),this,SLOT(changePoint(int)));
    connect(ui->gameView->ball,SIGNAL(increasePoint(int)),this,SLOT(changePoint(int)));

    startTimer(10);

}

QFlyingBall::~QFlyingBall()
{
    delete ui;
}
void QFlyingBall::keyPressEvent(QKeyEvent *k){
    if(k->key() == Qt::Key_S){
        ui->gameView->launchMissile();

    }
}


void QFlyingBall::timerEvent(QTimerEvent *te)
{
    ui->gameView->ball->move();
    ui->gameView->moveMissiles();

}

void QFlyingBall::changePoint(int point)
{
    ui->point->setNum(ui->point->text().toInt()+point);
}
