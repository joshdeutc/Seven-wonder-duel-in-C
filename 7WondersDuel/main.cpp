#include "mainwindow.h"
#include "jeu.h"
#include "batimentwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Jeu::getInstance();

    w.show();
    return a.exec();
}
