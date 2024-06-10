#include "mainwindow.h"
#include "jeu.h"
#include "batimentwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Jeu* jeu = Jeu::getInstance();

    // Initialisation des cartes
    Batiment** tabAge1 = jeu->getTabCartesAge1();
    BatimentWidget* tabWidgetAge1[jeu->getNbCartesAge1()];
    for (int i = 0; i < jeu->getNbCartesAge1(); ++i) {
        tabWidgetAge1[i] = BatimentWidget(nullptr, tabAge1[i]);
    }

    w.show();
    return a.exec();
}
