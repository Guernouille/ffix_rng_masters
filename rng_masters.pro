#-------------------------------------------------
#
# Project created by QtCreator 2015-10-23T06:14:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = rng_masters
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    prng.cpp \
    display_board.cpp \
    display_card.cpp \
    generate_board.cpp \
    generate_card.cpp \
    read_card.cpp \
    initialize_widgets.cpp \
    autoconnect.cpp

HEADERS  += mainwindow.h \
    prng.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
