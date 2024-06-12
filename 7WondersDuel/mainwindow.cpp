#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a_propos.h"
#include "ui_a_propos.h"
#include "jeu.h"
#include "batimentwidget.h"
#include "jetonprogreswidget.h"
#include "merveillewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , jeu(Jeu::getInstance())
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    ui->stackedWidget->setCurrentIndex(0);

    /*----------------- Initialisation des cartes -------------------*/
    Batiment** tabAge1 = jeu->getTabCartesAge1();
    BatimentWidget* tabWidgetAge1[jeu->getNbCartesAge1()];
    for (int i = 0; i < jeu->getNbCartesAge1(); ++i) {
        tabWidgetAge1[i] = new BatimentWidget(tabAge1[i]);
        tabWidgetAge1[i]->getImageLabel();
    }

    Batiment** tabAge2 = jeu->getTabCartesAge2();
    BatimentWidget* tabWidgetAge2[jeu->getNbCartesAge2()];
    for (int i = 0; i < jeu->getNbCartesAge2(); ++i) {
        tabWidgetAge2[i] = new BatimentWidget(tabAge2[i]);
    }

    Batiment** tabAge3 = jeu->getTabCartesAge3();
    BatimentWidget* tabWidgetAge3[jeu->getNbCartesAge3()];
    for (int i = 0; i < jeu->getNbCartesAge3(); ++i) {
        tabWidgetAge3[i] = new BatimentWidget(tabAge3[i]);
    }

    Guilde** tabGuilde = jeu->getTabCartesGuilde();
    BatimentWidget* tabWidgetGuilde[jeu->getNbCartesGuilde()];
    for (int i = 0; i < jeu->getNbCartesGuilde(); ++i) {
        tabWidgetGuilde[i] = new BatimentWidget(tabGuilde[i]);
    }

    JetonProgres** tabJetonProgres = jeu->getTabJetonProgres();
    JetonProgresWidget* tabWidgetJetonProgres[jeu->getNbJetonsProgres()];
    for (int i = 0; i < jeu->getNbJetonsProgres(); ++i) {
        tabWidgetJetonProgres[i] = new JetonProgresWidget(tabJetonProgres[i]);
    }

    Merveille** tabMerveille = jeu->getTabCartesMerveille();
    MerveilleWidget* tabWidgetMerveille[jeu->getNbCartesMerveille()];
    for (int i = 0; i < jeu->getNbCartesMerveille(); ++i) {
        tabWidgetMerveille[i] = new MerveilleWidget(tabMerveille[i]);
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
    ui->comboBox_Cartes->addItem("Cartes du Plateau");
    ui->comboBox_Cartes->addItem("Cartes accessibles");
    ui->comboBox_Cartes->addItem("Cartes visibles & non accessibles");
    // Actions à définir pour créer deux instances Joueurs
}

void MainWindow::on_pushButton_JvsIA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox_Cartes->addItem("Cartes du Plateau");
    ui->comboBox_Cartes->addItem("Cartes accessibles");
    ui->comboBox_Cartes->addItem("Cartes visibles & non accessibles");
    // Actions à définir pour créer une instance Joueur et une autre IA
}

void MainWindow::on_pushButton_IAvsIA_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->comboBox_Cartes->addItem("Cartes du Plateau");
    ui->comboBox_Cartes->addItem("Cartes accessibles");
    ui->comboBox_Cartes->addItem("Cartes visibles & non accessibles");
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

