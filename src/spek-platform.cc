#include "spek-platform.h"

#include <QDir>

QString spek_platform_config_path(const char *app_name)
{
#ifdef Q_OS_WIN
    const QString &path = QString::fromLocal8Bit(getenv("APPDATA")) + "/";
#else
    const QString &path = QDir::homePath() + "/";
#endif
    return path + app_name + "/preferences";
}

bool spek_platform_can_change_language()
{
#ifdef OS_UNIX
    return false;
#else
    return true;
#endif
}

double spek_platform_font_scale()
{
#ifdef OS_OSX
    return 1.3;
#else
    return 1.0;
#endif
}
