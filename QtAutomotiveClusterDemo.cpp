#include "stdafx.h"
#include "QtAutomotiveClusterDemo.h"

QtAutomotiveClusterDemo::QtAutomotiveClusterDemo(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

void QtAutomotiveClusterDemo::buttonSlot(int signal)
{
    if(signal == 0)
	{
		qDebug() << "Called the C++ slot with" << signal;
	}
	else
	{
		qDebug() << "Called the C++ slot with" << signal;
	}
}

QtAutomotiveClusterDemo::~QtAutomotiveClusterDemo()
{

}
