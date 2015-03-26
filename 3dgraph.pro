TEMPLATE = app
TARGET = ./graph3d
CONFIG += qt warn_on
DESTDIR = .

QT += opengl

CONFIG += qt3d_deploy_pkg
include(../../../pkg.pri)

# Input
HEADERS += GLView.h
SOURCES += GLView.cpp main.cpp
