#include "spek-platform.h"
#include "spek-preferences.h"

SpekPreferences& SpekPreferences::get()
{
    static SpekPreferences instance;
    return instance;
}

SpekPreferences::SpekPreferences()
    : settings(spek_platform_config_path("spek"), QSettings::IniFormat)
{

}

//bool SpekPreferences::get_check_update()
//{
//    return settings.value("update/check", true).toBool();
//}

//void SpekPreferences::set_check_update(bool value)
//{
//    settings.setValue("update/check", value);
//}

//long SpekPreferences::get_last_update()
//{
//    return settings.value("update/last", 0).toLongLong();
//}

//void SpekPreferences::set_last_update(long value)
//{
//    return settings.setValue("update/last", (qlonglong)value);
//}

QString SpekPreferences::get_language()
{
    return settings.value("language", QString()).toString();
}

void SpekPreferences::set_language(const QString& value)
{
    return settings.setValue("language", value);
}
