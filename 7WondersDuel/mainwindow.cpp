#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "a_propos.h"
#include "ui_a_propos.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1280,720);
}

MainWindow::~MainWindow()
{
    delete ui;
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

