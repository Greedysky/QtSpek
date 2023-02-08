#include "spek-window.h"
#include "spek-spectrogram.h"
#include "spek-preferences-dialog.h"

#include <QUrl>
#include <QMenuBar>
#include <QToolBar>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>

// TODO: s/audio/media/
static const char *audio_extensions[] = {
    "3gp",
    "aac",
    "aif",
    "aifc",
    "aiff",
    "amr",
    "awb",
    "ape",
    "au",
    "dts",
    "flac",
    "flv",
    "gsm",
    "m4a",
    "m4p",
    "mp3",
    "mp4",
    "mp+",
    "mpc",
    "mpp",
    "oga",
    "ogg",
    "opus",
    "ra",
    "ram",
    "snd",
    "wav",
    "wma",
    "wv",
    NULL
};


SpekWindow::SpekWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/logo"));
    setWindowTitle(tr("Spek - Acoustic Spectrum Analyser"));
    resize(640, 480);

    QMenuBar *menuBar = this->menuBar();
    QMenu *menuFile = menuBar->addMenu(tr("&File"));
    menuFile->addAction(tr("Open(O)..."), this, SLOT(openClicked()), QKeySequence("Ctrl+O"));
    menuFile->addAction(tr("Save(S)"), this, SLOT(saveClicked()), QKeySequence("Ctrl+S"));
    menuFile->addSeparator();
    menuFile->addAction(tr("Quit(Q)"), this, SLOT(close()));

    QMenu *menuEdit = menuBar->addMenu(tr("&Edit"));
    menuEdit->addAction(tr("Preferences"), this, SLOT(editClicked()), QKeySequence("Ctrl+E"));

    QMenu *menuHelp = menuBar->addMenu(tr("&Help"));
    menuHelp->addAction(tr("Help"), this, SLOT(helpClicked()), QKeySequence("F1"));
    menuHelp->addAction(tr("About"), this, SLOT(aboutClicked()), QKeySequence("Shift+F1"));

    QToolBar *toolbar = new QToolBar(this);
    toolbar->setMovable(false);
    toolbar->addAction(QIcon(":/open.ico"), tr("Open(O)..."), this, SLOT(openClicked()));
    toolbar->addAction(QIcon(":/save.ico"), tr("Save(S)"), this, SLOT(saveClicked()));
    QWidget* empty = new QWidget(toolbar);
    empty->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolbar->addWidget(empty);
    toolbar->addAction(QIcon(":/help.ico"), tr("Help"), this, SLOT(helpClicked()));
    addToolBar(toolbar);

    this->spectrogram = new SpekSpectrogram;
    setCentralWidget(this->spectrogram);
}

SpekWindow::~SpekWindow()
{
    delete this->spectrogram;
}

void SpekWindow::open(const QString& path)
{
    QFileInfo file(path);
    if(file.exists()) {
        setWindowTitle("Spek - " + file.fileName());
        this->path = path;
        this->spectrogram->open(path);
    }
}

void SpekWindow::openClicked()
{
    static QString filters;
    filters += tr("All files");
    filters += " (*.*)";
    filters += ";;";
    filters += tr("Audio files");
    filters += " (";
    for(int i = 0; audio_extensions[i]; ++i) {
        if(i) {
            filters += ";";
        }

        filters += "*.";
        filters += audio_extensions[i];
    }
    filters += ")";

    const QString &path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", filters);
    if(!path.isEmpty()) {
        open(path);
    }
}

void SpekWindow::saveClicked()
{
    static QString filters;
    filters += tr("PNG images");
    filters += " (*.png)";

    QString name = ".";
    QFileInfo file(this->path);
    name = file.exists() ? file.baseName() : tr("Untitled");
    name += ".png";

    const QString &path = QFileDialog::getSaveFileName(this, tr("Save Spectrogram"), name, filters);
    if(!path.isEmpty()) {
        this->spectrogram->save(path);
    }
}

void SpekWindow::editClicked()
{
    SpekPreferencesDialog dlg(this);
    dlg.exec();
}

void SpekWindow::helpClicked()
{
    QDesktopServices::openUrl(QString("http://help.spek.cc/man-%1.html").arg(PACKAGE_VERSION));
}

void SpekWindow::aboutClicked()
{
    QString text;
    text += "Spek";
    text += "\n";
    text += "Version " PACKAGE_VERSION;
    text += "\n\n";
    text += tr("Copyright (c) 2010-2013 Alexander Kojevnikov and contributors");
    text += "\n";
    text += "Spek - Acoustic Spectrum Analyser";
    text += "\n\n";
    text += "Developer ";
    text += "Alexander Kojevnikov,";
    text += "Andreas Cadhalpun,";
    text += "Colin Watson,";
    text += "Daniel Hams,";
    text += "Elias Ojala,";
    text += "Fabian Deutsch,";
    text += "Guillaume Fourrier,";
    text += "Jakov Smolic,";
    text += "Jonathan Gonzalez V,";
    text += "Matteo Bini,";
    text += "Mike Wang,";
    text += "Simon Ruderich,";
    text += "Stefan Kost,";
    text += "Thibault North,";
    text += "Wyatt J. Brown";
    text += "\n\n";
    text += "Graphics art by ";
    text += "Olga Vasylevska";
    text += "\n\n";
    text += tr("translator-credits");
    text += "\n";

    QMessageBox message;
    message.setWindowIcon(QIcon(":/logo"));
    message.setWindowTitle("About Spek");
    message.setText(text);
    message.setIcon(QMessageBox::Information);
    message.exec();
}
