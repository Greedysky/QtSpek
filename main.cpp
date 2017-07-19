#include <QApplication>
#include "spek-spectrogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SpekSpectrogram w;
    w.show();

    w.open("F:\\KuGou\\J.Fla - Shape Of You.mp3");

    return a.exec();
}
