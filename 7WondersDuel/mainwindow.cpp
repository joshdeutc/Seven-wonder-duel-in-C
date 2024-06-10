#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a_propos.h"
#include "ui_a_propos.h"
#include "jeu.h"
#include "batimentwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , jeu(Jeu::getInstance())
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    ui->stackedWidget->setCurrentIndex(0);

    // Initialisation des cartes
    Batiment** tabAge1 = jeu->getTabCartesAge1();
    BatimentWidget* tabWidgetAge1[jeu->getNbCartesAge1()];
    for (int i = 0; i < jeu->getNbCartesAge1(); ++i) {
        tabWidgetAge1[i] = new BatimentWidget(nullptr, tabAge1[i]);
    }

    Batiment** tabAge2 = jeu->getTabCartesAge2();
    BatimentWidget* tabWidgetAge2[jeu->getNbCartesAge2()];
    for (int i = 0; i < jeu->getNbCartesAge2(); ++i) {
        tabWidgetAge2[i] = new BatimentWidget(nullptr, tabAge2[i]);
    }

    Batiment** tabAge3 = jeu->getTabCartesAge3();
    BatimentWidget* tabWidgetAge3[jeu->getNbCartesAge3()];
    for (int i = 0; i < jeu->getNbCartesAge3(); ++i) {
        tabWidgetAge3[i] = new BatimentWidget(nullptr, tabAge3[i]);
    }

    Guilde** tabGuilde = jeu->getTabCartesGuilde();
    BatimentWidget* tabWidgetGuilde[jeu->getNbCartesGuilde()];
    for (int i = 0; i < jeu->getNbCartesGuilde(); ++i) {
        tabWidgetGuilde[i] = new BatimentWidget(nullptr, tabGuilde[i]);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
    Jeu::freeInstance();
}

void MainWindow::on_pushButton_JvsJ_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // Actions à définir pour créer deux instances Joueurs
}

void MainWindow::on_pushButton_JvsIA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // Actions à définir pour créer une instance Joueur et une autre IA
}

void MainWindow::on_pushButton_IAvsIA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    // Actions à définir pour créer deux instances IA
}

void MainWindow::on_actionAller_au_menu_principal_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
    // Actions à définir pour mettre fin à la partie
}


void MainWindow::on_action_propos_triggered()
{
    A_propos a_propos;
    a_propos.setModal(true);
    a_propos.exec();
}

