#include "stdafx.h"
#include "QtAutomotiveClusterDemo.h"

#include <QKeyEvent>
#include <QSlider>
//#include <QObject>

#include "lib/control.h"
#include "lib/image.h"

QtAutomotiveClusterDemo::QtAutomotiveClusterDemo(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
}

void QtAutomotiveClusterDemo::buttonSlot(int signal)
{
    if(signal == 1)
	{
        if (sumo == 0) qDebug() << "Connected! " << signal;
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

QtAutomotiveClusterDemo::~QtAutomotiveClusterDemo()
{

}

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

void QtAutomotiveClusterDemo::timerEvent(QTimerEvent *)
{
    int mod = 0;

#define ACCELERATION_CONSTANT 6

    if (!keys[Qt::Key_Down] && !keys[Qt::Key_Up]) {
        mod = -(accel/ACCELERATION_CONSTANT);
        if (mod == 0 && accel)
            mod = 1 * (accel < 0 ? 1 : -1);
    }

    if (keys[Qt::Key_Up]) {
        if (accel >= 0)
            mod = ACCELERATION_CONSTANT;

            mod = ACCELERATION_CONSTANT * 2;
            qDebug() << "apas sus";
    }

    if (keys[Qt::Key_Down]) {
        if (accel <= 0)
            mod = -ACCELERATION_CONSTANT;

            mod = -ACCELERATION_CONSTANT * 2;
            qDebug() << "apas jos";
    }

    accel += mod;

    if (accel > 127)
        accel = 127;
    if (accel < -127)
        accel = -127;

    /* turning */
#define TURN_CONSTANT 5
    mod = 0;
    if (!keys[Qt::Key_Left] && !keys[Qt::Key_Right]) {
        mod = -turn/TURN_CONSTANT * 3;


        if (abs(turn) < TURN_CONSTANT && turn)
            mod = -turn;
    }

    if (keys[Qt::Key_Left])
        mod = -TURN_CONSTANT;

    if (keys[Qt::Key_Right])
        mod = TURN_CONSTANT;

    turn += mod;
    if (turn > 32)
        turn = 32;
    if (turn < -32)
        turn = -32;

    //_speed->setValue(accel);
    //_turning->setValue(turn);

    sumo->move(accel, turn);
    //_batteryLevel->setValue(sumo->batteryLevel());

    if (sumo && keys[Qt::Key_L])
        sumo->longJump();

    if (sumo && keys[Qt::Key_H])
        sumo->highJump();

    if (sumo && keys[Qt::Key_T])
        sumo->tap();

    if (sumo && keys[Qt::Key_S])
        sumo->swing();


}
/*
void QtAutomotiveClusterDemo::on__open_close_clicked(bool)
{
    if (sumo) {
        killTimer(timer_id);
        sumo->close();
        delete sumo; sumo = 0;
        //_open_close->setText("Open");
    } else {
        sumo = new sumo::Control(new sumo::ImageMplayerPopen());
        if (!sumo->open()) {
            delete sumo;
            sumo = 0;
            return;
        }

        timer_id = startTimer(75);
        //_open_close->setText("Close");
    }
}
*/
