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
    explicit SpekSpectrogram(QWidget *parent = nullptr);
    ~SpekSpectrogram();

    void open(const QString& path);
    void start();
    void stop();

    inline QImage *getPaintImage() { return &image; }
    inline int getURange() const { return urange; }
    inline int getLRange() const { return lrange; }
    Palette getPalette() const { return palette; }

private:
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;

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
    Palette palette;
    QImage palette_image;
    QImage image;
    int prev_width;
    int fft_bits;
    int urange;
    int lrange;

};

#endif
