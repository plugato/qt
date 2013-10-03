#-------------------------------------------------
#
# Project created by QtCreator 2013-09-27T16:52:50
#
#-------------------------------------------------

QT       += core network

QT       -= gui


TARGET = ChatLibrary
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    socket.cpp \
    PackageBuilder.cpp \
    package.cpp \
    packagemensagem.cpp

HEADERS += \
    socket.h \
    PackageBuilder.h \
    package.h \
    packagemensagem.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
