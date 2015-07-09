
#include "stdafx.h"
#include "QtAutomotiveClusterDemo.h"
#include <QApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDeclarativeView view, graphView;

    QString branch = qApp->applicationDirPath() + "/../";
    QtAutomotiveClusterDemo w;
    view.rootContext()->setContextProperty("myObject", &w);				// set the myObject to communicate between qml and c++ ALWAYS before setting the QML file

#ifdef RESOLUTION_1024x600
    QTextStream(stdout) << branch.toLatin1() + "/QtAutomotiveClusterDemoDesign/qml_1024x600.qml" << endl;
    view.setSource(QUrl::fromLocalFile(branch.toLatin1() + "/QtAutomotiveClusterDemoDesign/qml_1024x600.qml"));	// qml.qml is main page
#else
    QTextStream(stdout) << branch.toLatin1() + "QtSumo/QtAutomotiveClusterDemoDesign/qml.qml" << endl;
    view.setSource(QUrl::fromLocalFile(branch.toLatin1() + "QtSumo/QtAutomotiveClusterDemoDesign/qml.qml"));	// qml.qml is main page
#endif

    //view.setWindowFlags(Qt::FramelessWindowHint | Qt::Window);    	// this statement can make the window frameless
    //view.isFullScreen();
    //view.showFullScreen();
    view.show();
    //w.showMaximized();

    //a.installEventFilter(&w);
    return a.exec();
}
