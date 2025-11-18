#ifndef SPEKWINDOW_H
#define SPEKWINDOW_H

#include <QMainWindow>

class SpekSpectrogram;

class SpekWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SpekWindow(QWidget *parent = nullptr);
    ~SpekWindow();

    void open(const QString& path);

private Q_SLOTS:
    void openClicked();
    void saveClicked();
    void editClicked();
    void helpClicked();
    void aboutClicked();

private:
    SpekSpectrogram *spectrogram;

    QString path;

};

#endif
