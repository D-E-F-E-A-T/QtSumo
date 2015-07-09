#include "stdafx.h"
#include "QtAutomotiveClusterDemo.h"

#include <QKeyEvent>
#include <QSlider>
//#include <QObject>

#include "lib/control.h"
#include "lib/image.h"

QtAutomotiveClusterDemo::QtAutomotiveClusterDemo(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags), accel(0), turn(0), battery(0), sumo(0)
{
	ui.setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    installEventFilter(this);
}

void QtAutomotiveClusterDemo::updateAcceleration(int acc) {
    //qDebug() << "acc: "<< acc << " turn: " << trn;

    if (acc > 127)
        acc = 127;
    if (acc < -127)
        acc = -127;

    if (sumo) {
        accel = acc;
    }
}

void QtAutomotiveClusterDemo::updateTurn(int trn) {
    //qDebug() << "acc: "<< acc << " turn: " << trn;

    if (trn > 32)
        trn = 32;
    if (trn < -32)
        trn = -32;

    if (sumo) {
        turn = trn;
    }
}

void QtAutomotiveClusterDemo::setbatteryLvl(int newVal) {  // <--- do your stuff to update the value
    if (newVal != battery) {
        battery = newVal;
        emit batteryChanged();     // <--- emit signal to notify QML!
    }
}

void QtAutomotiveClusterDemo::buttonSlot(int signal)
{
    if(signal == 1)
	{
        if (sumo == 0) qDebug() << "Connected! " << signal;
        //QObject *rpm_dial = parent()->findChild<QObject*>("rpm_dial");
        //qDebug() << "sunt aici 1 " << rpm_dial->objectName();

        sumo = new sumo::Control(new sumo::ImageMplayerPopen());
        if (!sumo->open()) {
          delete sumo;
          sumo = 0;
          return;
        }

        timer_id = startTimer(10);
	}
    else {
        if (sumo) {
            qDebug() << "Disconnected! " << signal;
            killTimer(timer_id);
            sumo->close();
            delete sumo; sumo = 0;
        }
	}
}

QtAutomotiveClusterDemo::~QtAutomotiveClusterDemo(){}

/*
void QtAutomotiveClusterDemo::keyPressEvent(QKeyEvent *e)
{
    if (!e->isAutoRepeat()) {
        keys[e->key()] = true;
    }
    QWidget::keyPressEvent(e);
}

void QtAutomotiveClusterDemo::keyReleaseEvent(QKeyEvent *e)
{
    if (!e->isAutoRepeat()) {
        keys[e->key()] = false;
    }
    QWidget::keyReleaseEvent(e);
}
*/
void QtAutomotiveClusterDemo::timerEvent(QTimerEvent *)
{
    if (sumo) {
         //qDebug() << "acc: "<< accel << " turn: " << turn;
        sumo->move(accel, turn);

        //qDebug() << "btr: "<< sumo->batteryLevel();
        setbatteryLvl(sumo->batteryLevel());
        //_batteryLevel->setValue(sumo->batteryLevel());
    }
}

void QtAutomotiveClusterDemo::flipUpsideDown(){
    if (sumo)
            sumo->flipUpsideDown();
}

void QtAutomotiveClusterDemo::flipDownsideUp(){
    if (sumo)
            sumo->flipDownsideUp();
}

void QtAutomotiveClusterDemo::balance(){
    if (sumo)
            sumo->handstandBalance();
}

void QtAutomotiveClusterDemo::highJump(){
    if (sumo)
            sumo->highJump();
}

void QtAutomotiveClusterDemo::longJump(){
    if (sumo)
            sumo->longJump();
}

void QtAutomotiveClusterDemo::swing(){
    if (sumo)
            sumo->swing();
}

void QtAutomotiveClusterDemo::growingCircles(){
    if (sumo)
            sumo->growingCircles();
}

void QtAutomotiveClusterDemo::slalom(){
    if (sumo)
            sumo->slalom();
}

void QtAutomotiveClusterDemo::tap(){
    if (sumo)
            sumo->tap();
}

void QtAutomotiveClusterDemo::quickTurnRight(){
    if (sumo)
            sumo->quickTurnRight();
}

void QtAutomotiveClusterDemo::quickTurnRightLeft(){
    if (sumo)
            sumo->quickTurnRightLeft();
}

void QtAutomotiveClusterDemo::turnToBalance(){
    if (sumo)
            sumo->turnToBalance();
}

void QtAutomotiveClusterDemo::lookLeftAndRight(){
    if (sumo)
            sumo->lookLeftAndRight();
}

void QtAutomotiveClusterDemo::turnAndJump(){
    if (sumo)
            sumo->turnAndJump();
}

