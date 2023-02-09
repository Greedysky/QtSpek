#include <QTranslator>
#include <QApplication>
#include <QLocale>

#include "spek.h"
#include "spek-window.h"
#include "spek-preferences.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString language = SpekPreferences::get().get_language();
    if (language.isEmpty()) {
        language = QLocale().name();
    }

    QTranslator translator;
    if (!translator.load(app.applicationDirPath() + "/po/" + language + ".ln")) {
        app.quit();
        return -1;
    }
    app.installTranslator(&translator);

    SpekWindow w;
    w.show();

    return app.exec();
}
