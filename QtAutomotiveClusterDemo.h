#ifndef QtAutomotiveClusterDemo_H
#define QtAutomotiveClusterDemo_H

#include <QMainWindow>
#include "ui_QtAutomotiveClusterDemo.h"
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QWidget>
#include <QLayout>
#include <QObject>

class QSvgRenderer;
class QtSvgPixmapCache; 

namespace sumo {
    class Control;
}

class QtAutomotiveClusterDemo : public QMainWindow 
{
	Q_OBJECT
    Q_PROPERTY(int batteryLvl READ batteryLvl WRITE setbatteryLvl NOTIFY batteryChanged)

    int accel;
    int turn;
    int battery;

    sumo::Control *sumo;

    int timer_id;

public:
    QtAutomotiveClusterDemo(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~QtAutomotiveClusterDemo();
    //Q_INVOKABLE void keyPressEvent(QKeyEvent *e);
    //Q_INVOKABLE void keyReleaseEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *);
    void setbatteryLvl(int newVal);
    int batteryLvl() const {
        return battery;
    }
    //bool eventFilter(QObject *target, QEvent *event);

public slots:
	void buttonSlot(int signal);
    void updateAcceleration(int acc);
    void updateTurn(int trn);
    void flipUpsideDown();
    void flipDownsideUp();
    void balance();
    void highJump();
    void longJump();
    void swing();
    void growingCircles();
    void slalom();
    void tap();
    void quickTurnRight();
    void quickTurnRightLeft();
    void turnToBalance();
    void lookLeftAndRight();
    void turnAndJump();

signals:
    void batteryChanged();

private:
	Ui::QtAutomotiveClusterDemoClass ui;
};

#endif // QtAutomotiveClusterDemo_H
