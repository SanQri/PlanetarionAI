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
    Objectives/bonfire.cpp \
    Objectives/pointobject.cpp \
    Objectives/treeobjective.cpp \
    bounds.cpp \
    mousetrackingwidget.cpp \
    timemanager.cpp \
    Specializations/foodgatherer.cpp \
    Specializations/woodgatherer.cpp \
    Specializations/mixedgatherer.cpp \
    Resources/resource.cpp \
    Resources/foodresource.cpp \
    Resources/fruit.cpp \
    personstats.cpp \
    persontransportationmanager.cpp \
    timestamp.cpp \
    task.cpp \
    personmovementmanager.cpp \
    Specializations/eater.cpp \
    Resources/waterresource.cpp

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
    Objectives/bonfire.h \
    Objectives/pointobject.h \
    Objectives/treeobjective.h \
    bounds.h \
    mousetrackingwidget.h \
    changeable.h \
    timemanager.h \
    Specializations/foodgatherer.h \
    Specializations/woodgatherer.h \
    Specializations/mixedgatherer.h \
    Resources/resource.h \
    Resources/foodresource.h \
    Resources/fruit.h \
    personstats.h \
    persontransportationmanager.h \
    timestamp.h \
    task.h \
    personmovementmanager.h \
    Specializations/eater.h \
    Resources/waterresource.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    Notes.txt
