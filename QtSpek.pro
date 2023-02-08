#-------------------------------------------------
#
# Project created by QtCreator 2017-07-18T21:45:15
#
#-------------------------------------------------

QT += core gui
equals(QT_MAJOR_VERSION, 4){ #Qt4
    CONFIG += gcc
}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DESTDIR = $$OUT_PWD/bin
TEMPLATE = app
TARGET = spek

win32{
    msvc{
        CONFIG += c++11
        !contains(QMAKE_TARGET.arch, x86_64){
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
INCLUDEPATH += $$PWD/../qmmp_all/qmmp/extra/gcc/libffmpeg/include
LIBS += -L$$PWD/../qmmp_all/qmmp/extra/gcc/libffmpeg/lib -lavcodec -lavformat -lavutil -lswresample

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
    error(Could not find lrelease executable)
}else{
    message(Found lrelease executable: $$LRELEASE_EXECUTABLE)
}

##update translation
unix{
    output = $$OUT_PWD/bin/po
    !exists($$output):system(mkdir -p $$output)

    system(find $$PWD/po -name *.ts | xargs $$LRELEASE_EXECUTABLE)
    system(find $$PWD/po -name *.qm | xargs rename -v -f 's/.qm/.ln/' *)
    system(for F in $$PWD/po/*.ln ; do mv $F $$output ;done)
}

win32{
    output = $$OUT_PWD/bin/po
    output = $$replace(output, /, \\)
    !exists($$output):system(md $$output)

    system(for /r $$PWD/po %i in (*.ts) do $$LRELEASE_EXECUTABLE %i)
    system(for /r $$PWD/po %i in (*.qm) do ren %i *.ln)
    system(for /r $$PWD/po %i in (*.ln) do move /y %i $$output)
}
