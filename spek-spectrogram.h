#ifndef SPEKSPECTROGRAM_H
#define SPEKSPECTROGRAM_H

#include <memory>
#include <QWidget>

#include "spek-palette.h"
#include "spek-pipeline.h"

class Audio;
class FFT;
class SpekHaveSampleEvent;
struct spek_pipeline;

class SpekSpectrogram : public QWidget
{
public:
    SpekSpectrogram(QWidget *parent = 0);
    ~SpekSpectrogram();

    void open(const QString& path);
    void start();
    void stop();

    inline QImage *getPaintImage() { return &image; }
    inline int getURange() const { return urange; }
    inline int getLRange() const { return lrange; }
    enum palette getPalette() const { return palette; }

private:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    void paint(QPainter *dc);
    void create_palette();

    std::unique_ptr<Audio> audio;
    std::unique_ptr<FFT> fft;
    spek_pipeline *pipeline;
    int streams;
    int stream;
    int channels;
    int channel;
    enum window_function window_function;
    QString path;
    QString desc;
    double duration;
    int sample_rate;
    enum palette palette;
    QImage palette_image;
    QImage image;
    int prev_width;
    int fft_bits;
    int urange;
    int lrange;


};

#endif
