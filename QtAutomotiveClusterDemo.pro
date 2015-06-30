# Check Qt >= 4.4
#contains(QT_VERSION, ^4\.[0-3]\..*) {
#    message("Cannot build Fotowall with Qt version $$QT_VERSION .")
#    error("Use at least Qt 4.4.")
#}
#contains(QT_VERSION, ^4\.4\..*): message("Lots of features will be disabled with Qt $$QT_VERSION . Use Qt 4.6 or later.")
#contains(QT_VERSION, ^4\.5\..*): message("Some features are not available with Qt $$QT_VERSION . Use Qt 4.6 or later.")

# Project Options
TEMPLATE = app
TARGET = QtAutomotiveClusterDemo

CONFIG += console
CONFIG += c++11
CONFIG += thread

INCLUDEPATH += ./GeneratedFiles \
    .build \
    . \
    ./GeneratedFiles/Release
PRECOMPILED_HEADER = StdAfx.h

DEPENDPATH += .
MOC_DIR = .build
OBJECTS_DIR = .build
RCC_DIR = .build
UI_DIR = .build
QT = core \
    gui \
    svg \
    network \
    xml \
    sql \
    declarative

QT += widgets
LIBS += -L/lib

# use OpenGL where available
contains(QT_CONFIG, opengl)|contains(QT_CONFIG, opengles1)|contains(QT_CONFIG, opengles2) {
    QT += opengl
}

# disable the Wordcloud appliance (for 0.9 release)
DEFINES += NO_WORDCLOUD_APPLIANCE

# Fotowall input files
include(QtAutomotiveClusterDemo.pri)


# Installation path
#target.path = /usr/bin

OTHER_FILES += \
    QtAutomotiveClusterDemoDesign/RpmDial.qml \
    QtAutomotiveClusterDemoDesign/SpeedDial.qml \
    QtAutomotiveClusterDemoDesign/FuelMeter.qml \
    QtAutomotiveClusterDemoDesign/qml.qml

#OTHER_FOLDER += QtAutomotiveClusterDemoDesign

#QMAKE_POST_LINK += $$quote(cp -r $${PWD}/$${OTHER_FOLDER} $${OUT_PWD})

#for(FILE, OTHER_FILES){
# QMAKE_POST_LINK += $$quote(cp $${PWD}/$${FILE} $${OUT_PWD})
#}


# deployment on Linux
unix {
    target.path = /usr/bin/
    qml.path = /usr/bin/QtAutomotiveClusterDemoDesign
    qml.files = QtAutomotiveClusterDemoDesign/*
    INSTALLS += target \
        qml \
}

DISTFILES += \
    QtAutomotiveClusterDemoDesign/qml_800x480.qml

HEADERS += \
    lib/basics.h \
    lib/common.h \
    lib/control.h \
    lib/decode.h \
    lib/image.h \
    lib/protocol.h \
    lib/realtime.h

SOURCES += \
    lib/common.cpp \
    lib/control.cpp \
    lib/decode.cpp \
    lib/image.cpp \
    lib/realtime.cpp
