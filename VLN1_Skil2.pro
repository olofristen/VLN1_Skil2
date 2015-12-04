QT += core sql
QT -= gui

TARGET = VLN1_Skil2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    ui.cpp \
    person.cpp \
    domain.cpp \
    data.cpp

HEADERS += \
    ui.h \
    person.h \
    domain.h \
    data.h

