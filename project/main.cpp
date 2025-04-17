#include <QApplication>
#include "mainwindow.h"
#include <sodium.h>

int main(int argc, char *argv[])
{
    if (sodium_init() < 0) {
        qDebug() << "Initialising libsodium failed, exiting";
        return 1;
    }
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/logo.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
