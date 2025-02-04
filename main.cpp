#include "MainWindow.hpp"
#include "DatabaseService.hpp"
#include "qsqlconnectiondialog.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Создание отчетов АСУ ПРО" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            application.installTranslator(&translator);
            break;
        }
    }

    QSqlConnectionDialog dialog;
    dialog.show();

    MainWindow window;
    window.show();

    return application.exec();
}
