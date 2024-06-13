#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a_propos.h"
#include "ui_a_propos.h"
#include "jeu.h"
#include "partie.h"
#include "batimentwidget.h"
#include "jetonprogreswidget.h"
#include "merveillewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , jeu(Jeu::getInstance())
    , nbMerveillesRestantes(8)
    , joueurQuiChoisit(1)
    , nombreDeMerveilleAChosirPourJoueurCourant(1)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
    Jeu::freeInstance();
}

void MainWindow::on_pushButton_JvsJ_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    lancerPartie(humain, humain);
}

void MainWindow::on_pushButton_JvsIA_clicked()
{
    lancerPartie(humain, IA_aleatoire);
}

void MainWindow::on_pushButton_IAvsIA_clicked()
{
    lancerPartie(IA_aleatoire, IA_aleatoire);
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

void MainWindow::lancerPartie(TypeJoueur tj1, TypeJoueur tj2){
    ui->stackedWidget->setCurrentIndex(1);
    Partie p(tj1, tj2, "Joueur1", "Joueur2");
    // joueur[0] = Joueur 1
    // joueur[1] = Joueur 2

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

    ui->stackedWidget_Plateau_Age->setCurrentIndex(0);

    // On place les merveilles dans le plateau des choix
    tabWidgetMerveille[0]->setEmplacementLabel(ui->label_choix_merveille1_1);
    tabWidgetMerveille[1]->setEmplacementLabel(ui->label_choix_merveille1_2);
    tabWidgetMerveille[2]->setEmplacementLabel(ui->label_choix_merveille1_3);
    tabWidgetMerveille[3]->setEmplacementLabel(ui->label_choix_merveille1_4);
    tabWidgetMerveille[4]->setEmplacementLabel(ui->label_choix_merveille2_1);
    tabWidgetMerveille[5]->setEmplacementLabel(ui->label_choix_merveille2_2);
    tabWidgetMerveille[6]->setEmplacementLabel(ui->label_choix_merveille2_3);
    tabWidgetMerveille[7]->setEmplacementLabel(ui->label_choix_merveille2_4);

    // Les joueurs doivent choisir les merveilles

}

void MainWindow::setupMerveilleSelection() {
    nbMerveillesRestantes = 8;
    joueurQuiChoisit = 1; // Le premier joueur commence
    nombreDeMerveilleAChosirPourJoueurCourant = 1; // Le premier joueur choisit une merveille d'abord
}

void MainWindow::handleMerveilleSelection(MerveilleWidget* merveille) {
    if (nbMerveillesRestantes == 0) {
        return;
    }

    // Ajouter la merveille au joueur courant
    if (joueurQuiChoisit == 1) {
        // Ajouter la merveille au joueur 1
    } else {
        // Ajouter la merveille au joueur 2
    }

    // Mettre à jour le nombre de merveilles restantes et la logique du tour
    nbMerveillesRestantes--;
    nombreDeMerveilleAChosirPourJoueurCourant--;

    // Si le joueur courant a fini de choisir, passe à l'autre joueur
    if (nombreDeMerveilleAChosirPourJoueurCourant == 0) {
        joueurQuiChoisit = (joueurQuiChoisit == 1) ? 2 : 1;
        nombreDeMerveilleAChosirPourJoueurCourant = (nbMerveillesRestantes == 4) ? 2 : 1; // On chosit 2 merveilles si le nombre de merveille restante vaut 7 ou 3
    }

    // Masquer ou désactiver la merveille sélectionnée
    merveille->hide();

    // Passer à la page suivante du StackedWidget si toutes les merveilles de la page actuelle sont choisies
    if (nbMerveillesRestantes == 4) {
        ui->stackedWidget_Plateau_Age->setCurrentIndex(1);
    }
}
