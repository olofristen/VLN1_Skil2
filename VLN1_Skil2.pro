QT += core
QT -= gui
QT += sql

TARGET = VLN1_Skil2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    computer.cpp \
    data.cpp \
    domain.cpp \
    person.cpp \
    ui.cpp

HEADERS += \
    computer.h \
    data.h \
    domain.h \
    person.h \
    ui.h

