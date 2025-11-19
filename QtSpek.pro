# ***************************************************************************
# * This file is part of the QtSpek project
# * Copyright (C) 2015 - 2025 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# ***************************************************************************

QT += core gui
equals(QT_MAJOR_VERSION, 4){ #Qt4
    CONFIG += gcc
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$OUT_PWD/bin
TEMPLATE = app
TARGET = QtSpek

##find translation
unix:exists($$[QT_INSTALL_BINS]/lrelease){
    LRELEASE_EXECUTABLE = $$[QT_INSTALL_BINS]/lrelease
}

unix:exists($$[QT_INSTALL_BINS]/lrelease-qt5){
    LRELEASE_EXECUTABLE = $$[QT_INSTALL_BINS]/lrelease-qt5
}

win32:exists($$[QT_INSTALL_BINS]/lrelease.exe){
    LRELEASE_EXECUTABLE = $$[QT_INSTALL_BINS]/lrelease.exe
}

isEmpty(LRELEASE_EXECUTABLE){
    error("Could not find lrelease executable")
}else{
    message("Found lrelease executable: $$LRELEASE_EXECUTABLE")
}

##update translation
unix{
    system($$PWD/utils/resource.sh $$PWD/resource $$OUT_PWD/bin)
    system($$PWD/utils/ts_unix.py $$LRELEASE_EXECUTABLE $$OUT_PWD/bin $$PWD)
}

win32{
    output = $$OUT_PWD/bin/po
    output = $$replace(output, /, \\)
    system($$PWD/utils/ts_win.bat $$LRELEASE_EXECUTABLE $$OUT_PWD/bin $$PWD)
}

win32{
    msvc{
        CONFIG += c++11
        !contains(QT_ARCH, "x86_64"){
             #support on windows XP
             QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
             QMAKE_LFLAGS_CONSOLE = /SUBSYSTEM:CONSOLE,5.01
        }
    }

    gcc{
        equals(QT_MAJOR_VERSION, 6){ #Qt6
            QMAKE_CXXFLAGS += -std=c++17
        }else{
            QMAKE_CXXFLAGS += -std=c++11
        }
    }
}

unix:!mac{
    equals(QT_MAJOR_VERSION, 6){ #Qt6
        QMAKE_CXXFLAGS += -std=c++17
    }else{
        QMAKE_CXXFLAGS += -std=c++11
    }
}

#change to your libav or ffmpeg lib
INCLUDEPATH += $$PWD/contrib/include
LIBS += -L$$PWD/contrib/lib -lavcodec -lavformat -lavutil -lswresample

SOURCES += \
    src/main.cpp \
    src/spek-audio.cc \
    src/spek-fft.cc \
    src/spek-palette.cc \
    src/spek-pipeline.cc \
    src/spek-platform.cc \
    src/spek-preferences.cc \
    src/spek-preferences-dialog.cc \
    src/spek-ruler.cc \
    src/spek-spectrogram.cc \
    src/spek-utils.cc \
    src/spek-window.cc

HEADERS  += \
    src/spek.h \
    src/spek-audio.h \
    src/spek-fft.h \
    src/spek-palette.h \
    src/spek-pipeline.h \
    src/spek-platform.h \
    src/spek-preferences.h \
    src/spek-preferences-dialog.h \
    src/spek-ruler.h \
    src/spek-spectrogram.h \
    src/spek-utils.h \
    src/spek-window.h

RESOURCES += images/images.qrc

win32:RC_FILE = $$PWD/QtSpek.rc

TRANSLATIONS += \
    $$PWD/po/bs.ts \
    $$PWD/po/ca.ts \
    $$PWD/po/cs.ts \
    $$PWD/po/da.ts \
    $$PWD/po/de.ts \
    $$PWD/po/el.ts \
    $$PWD/po/en.ts \
    $$PWD/po/eo.ts \
    $$PWD/po/es.ts \
    $$PWD/po/fi.ts \
    $$PWD/po/fr.ts \
    $$PWD/po/gl.ts \
    $$PWD/po/he.ts \
    $$PWD/po/hr.ts \
    $$PWD/po/hu.ts \
    $$PWD/po/id.ts \
    $$PWD/po/it.ts \
    $$PWD/po/ja.ts \
    $$PWD/po/ko.ts \
    $$PWD/po/lv.ts \
    $$PWD/po/nb.ts \
    $$PWD/po/nl.ts \
    $$PWD/po/nn.ts \
    $$PWD/po/pl.ts \
    $$PWD/po/pt_BR.ts \
    $$PWD/po/ru.ts \
    $$PWD/po/sk.ts \
    $$PWD/po/sr@latin.ts \
    $$PWD/po/sv.ts \
    $$PWD/po/th.ts \
    $$PWD/po/tr.ts \
    $$PWD/po/uk.ts \
    $$PWD/po/vi.ts \
    $$PWD/po/zh_CN.ts \
    $$PWD/po/zh_TW.ts
