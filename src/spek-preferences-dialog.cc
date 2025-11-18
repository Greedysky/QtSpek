#include "spek-preferences-dialog.h"
#include "spek-preferences.h"

#include <QLabel>
#include <QComboBox>
#include <QBoxLayout>
#include <QPushButton>

// List all languages with a decent (e.g. 80%) number of translated
// strings. Don't translate language names. Keep the first line intact.
static const char *available_languages[] =
{
    "", "",
    "bs", "Bosanski",
    "ca", "Català",
    "cs", "Čeština",
    "da", "Dansk",
    "de", "Deutsch",
    "el", "Ελληνικά",
    "en", "English",
    "eo", "Esperanto",
    "es", "Español",
    "fi", "Suomi",
    "fr", "Français",
    "gl", "Galego",
    "he", "עברית",
    "hr", "Hrvatski",
    "hu", "Magyar",
    "id", "Bahasa Indonesia",
    "it", "Italiano",
    "ja", "日本語",
    "ko", "한국어",
    "lv", "Latviešu",
    "nb", "Norsk (bokmål)",
    "nl", "Nederlands",
    "nn", "Norsk (nynorsk)",
    "pl", "Polski",
    "pt_BR", "Português brasileiro",
    "ru", "Русский",
    "sk", "Slovenčina",
    "sr@latin", "Srpski",
    "sv", "Svenska",
    "th", "ไทย",
    "tr", "Türkçe",
    "uk", "Українська",
    "vi", "Tiếng Việt",
    "zh_CN", "中文(简体)",
    "zh_TW", "中文(台灣)",
    NULL
};

SpekPreferencesDialog::SpekPreferencesDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle(tr("Preferences"));
    setFixedSize(300, 140);

    QLabel *generalLabel = new QLabel(tr("General"), this);
    QFont font = generalLabel->font();
    font.setBold(true);
    generalLabel->setFont(font);
    generalLabel->move(15, 15);

    QWidget *languageGroup = new QWidget(this);
    languageGroup->move(27, 30);

    QHBoxLayout *layout = new QHBoxLayout(languageGroup);
    languageGroup->setLayout(layout);

    QLabel *languageLabel = new QLabel(tr("Language:"), this);
    layout->addWidget(languageLabel);

    QComboBox *languageBox = new QComboBox(this);
    layout->addWidget(languageBox);

    const QString &active = SpekPreferences::get().get_language();
    for (int i = 0; i < 1000; ++i) {
        const char *key = available_languages[i];
        const char *value = available_languages[i + 1];
        if (key == NULL || value == NULL) {
            break;
        }

        if (i == 0) {
            languageBox->addItem(tr("(system default)"), key);
        } else if (i % 2 == 0) {
            languageBox->addItem(value, key);
        }
    }

    for (int i = 0; i < languageBox->count(); ++i) {
        if (languageBox->itemData(i).toString() == active) {
            languageBox->setCurrentIndex(i);
            break;
        }
    }

    QPushButton *button = new QPushButton(tr("OK"), this);
    button->setGeometry(165, 100, 70, 25);

    connect(button, SIGNAL(clicked()), this, SLOT(close()));
    connect(languageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(languageChanged(int)));
}

void SpekPreferencesDialog::languageChanged(int index)
{
    SpekPreferences::get().set_language(available_languages[index * 2]);
}
