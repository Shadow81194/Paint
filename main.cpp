#include "principal.h"
#include <QTranslator>
#include <QApplication>
#include<QLocale>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;
    traduccion.load(QLocale(), QLatin1String("Paint"), QLatin1String("_"), QLatin1String(":/i18n"));
    a.installTranslator(&traduccion);

    Principal w;
    w.show();
    return a.exec();
}
