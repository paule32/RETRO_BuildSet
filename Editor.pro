QT       += core gui help widgets

TARGET = Editor
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++1z debug

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    codeeditor.cpp \
    helpbrowser.cpp \
    flowdesigner.cpp \
    systeminfo.cpp \
    scene.cpp \
    designeritem.cc \
    cornergrabber.cpp \
    flowitem.cpp \
    c64screen.cpp \
    c64scene.cpp

HEADERS += \
        mainwindow.h \
    codeeditor.h \
    helpbrowser.h \
    flowdesigner.h \
    systeminfo.h \
    scene.h \
    designeritem.h \
    flowitem.h \
    c64screen.h \
    c64scene.h

FORMS += \
        mainwindow.ui

target.path = /opt/$${TARGET}/bin
INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    help/help.qhcp \
    help/help.qhp
