#include "mywidget.h"

#include <QApplication> //应用程序
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])    //argc命令行变量的数量，命令行变量的数组
{
    QApplication a(argc, argv);     //a应用程序对象，有且仅有一个，必须有

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "first_pro_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    myWidget w;     //窗口的对象 show方法
    w.show();       //窗口对象默认不会显示，必须要调用show方法显示
    return a.exec();//让程序对象进入消息循环机制
}
