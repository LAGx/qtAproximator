#-------------------------------------------------
#
# Project created by QtCreator 2018-03-28T17:26:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = qtAproximator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    aplication_manager.cpp \
    state_bar.cpp \
    plotter.cpp \
    least_square_method.cpp \
    langrange.cpp

HEADERS += \
        mainwindow.h \
    langrange.h \
    least_square_method.h \
    plotter.h \
    state_bar.h \
    qcustomplot.h \
    graph_interface.h \
    aplication_manager.h \
    aplication_interface.h \
    aproximator_style.h

FORMS += \
        mainwindow.ui

CONFIG += mobility
MOBILITY = 


OTHER_FILES += \
    android-sources/AndroidManifest.xml
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
