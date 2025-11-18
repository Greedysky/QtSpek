#pragma once

#include <QDialog>

class SpekPreferencesDialog : public QDialog
{
    Q_OBJECT
public:
    explicit SpekPreferencesDialog(QWidget *parent = nullptr);

private Q_SLOTS:
    void languageChanged(int index);

};
