#include <QtGui>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argv, char *args[])
{
    Q_INIT_RESOURCE(res);

    QApplication app(argv, args);
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForCStrings(codec);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}


