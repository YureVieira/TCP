#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T19:11:15
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = server_001
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    ../TcpServer/tcpserver.cpp

HEADERS += \
    ../TcpServer/tcpserver.h
