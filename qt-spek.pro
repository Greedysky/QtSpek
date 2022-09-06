#-------------------------------------------------
#
# Project created by QtCreator 2017-07-18T21:45:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-spek
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

#change to your libav or ffmpeg lib
INCLUDEPATH += $$PWD/libffmpeg/include
LIBS += -L"$$PWD/libffmpeg/lib" -lavcodec -lavformat -lavutil -lswresample

SOURCES += main.cpp\
        spek-ruler.cc \
        spek-spectrogram.cc \
        spek-audio.cc \
        spek-fft.cc \
        spek-palette.cc \
        spek-pipeline.cc \
        spek-utils.cc

HEADERS  += \
        spek-audio.h \
        spek-fft.h \
        spek-palette.h \
        spek-pipeline.h \
        spek-ruler.h \
        spek-spectrogram.h \
        spek-utils.h
