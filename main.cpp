#include <QApplication>
#include "spek-spectrogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SpekSpectrogram w;
    w.show();

    w.open("filePath");

    return a.exec();
}
