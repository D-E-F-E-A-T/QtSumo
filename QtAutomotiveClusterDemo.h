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

    QMap<int, bool> keys;

    int accel;
    int turn;

    sumo::Control *sumo;

    int timer_id;

public:
    QtAutomotiveClusterDemo(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~QtAutomotiveClusterDemo();
    Q_INVOKABLE void keyPressEvent(QKeyEvent *e);
    Q_INVOKABLE void keyReleaseEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *);
    //bool eventFilter(QObject *target, QEvent *event);

public slots:
	void buttonSlot(int signal);
    void updateAcceleration(int acc);
    void updateTurn(int trn);

private:
	Ui::QtAutomotiveClusterDemoClass ui;
};

#endif // QtAutomotiveClusterDemo_H
