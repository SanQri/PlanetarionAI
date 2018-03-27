#-------------------------------------------------
#
# Project created by QtCreator 2017-11-13T19:50:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Planetario
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    mainwindow.cpp \
    person.cpp \
    diamonsquaregenerator.cpp \
    tribe.cpp \
    position.cpp \
    cell.cpp \
    map.cpp \
    camera.cpp \
    renderer.cpp \
    maptilemanager.cpp \
    Specializations/specialization.cpp \
    Specializations/woodcutter.cpp \
    Objectives/bonfire.cpp \
    Objectives/pointobject.cpp \
    Objectives/treeobjective.cpp \
    bounds.cpp \
    mousetrackingwidget.cpp

HEADERS  += \
    mainwindow.h \
    person.h \
    diamonsquaregenerator.h \
    tribe.h \
    position.h \
    cell.h \
    map.h \
    camera.h \
    renderer.h \
    maptilemanager.h \
    Specializations/specialization.h \
    Specializations/woodcutter.h \
    Objectives/bonfire.h \
    Objectives/pointobject.h \
    Objectives/treeobjective.h \
    bounds.h \
    mousetrackingwidget.h

FORMS    += mainwindow.ui

DISTFILES += \
    MapTiles/darkGrass.png \
    MapTiles/deepWater.png \
    MapTiles/grass.png \
    MapTiles/outOfMap.png \
    MapTiles/sand.png \
    MapTiles/stone.png \
    MapTiles/water.png \
    ObjectiveSprites/treeObjective.png
