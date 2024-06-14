#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>

#include "jeu.h"
#include "joueur.h"
#include "merveillewidget.h"
#include "partie.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_JvsJ_clicked();

    void on_pushButton_JvsIA_clicked();

    void on_pushButton_IAvsIA_clicked();

    void on_actionAller_au_menu_principal_triggered();

    void on_action_propos_triggered();

    void lancerPartie(TypeJoueur tj1, TypeJoueur tj2);

    // Choix des merveilles
    void handleMerveilleSelection(MerveilleWidget* merveille);

private:
    Ui::MainWindow *ui;
    Jeu* jeu = nullptr;
    Partie* p = nullptr;

    // Paramètres et méthodes internes pour le choix des merveilles
    size_t nbMerveillesRestantes;
    size_t joueurQuiChoisit;
    size_t nombreDeMerveilleAChosirPourJoueurCourant;
    void setupMerveilleSelection();

    // Paramètres et méthodes internes pour les emplacements de merveilles
    QLabel* emplacementsMerveillesJ1[4];
    QLabel* emplacementsMerveillesJ2[4];
    int indexMerveilleJ1 = 0;
    int indexMerveilleJ2 = 0;

};
#endif // MAINWINDOW_H
