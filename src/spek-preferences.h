#pragma once

#include <QSettings>

class SpekPreferences
{
public:
    static SpekPreferences& get();

//    bool get_check_update();
//    void set_check_update(bool value);

//    long get_last_update();
//    void set_last_update(long value);

    QString get_language();
    void set_language(const QString& value);

private:
    SpekPreferences();
    SpekPreferences(const SpekPreferences&);
    void operator=(const SpekPreferences&);

    QSettings settings;

};
