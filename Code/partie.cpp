#include "partie.h"


Partie::Partie(const TypeJoueur &typJ1,const TypeJoueur &typJ2,string id1,string id2) {
    platAge = PlateauAge(1);
     // Initialiser le plateau de l'âge
    platMilitaire = PlateauJetonMilit(); // Initialiser le plateau militaire
    platMerveille = PlateauMerveille(); // Initialiser le plateau des merveilles
    platJeton = PlateauJetonMilit(); // Initialiser le plateau des jetons
    joueurs[0] = new Joueur(typJ1,id1); // Créer le joueur 1
    joueurs[1] = new Joueur(typJ2,id2); // Créer le joueur 2
}

Partie::~Partie() {
    // Libérer la mémoire allouée pour les plateaux
    ~PlateauAge();
    ~PlateauJetonMilit();
    ~PlateauMerveille();
    // Libérer la mémoire allouée pour les joueurs
    for (int i = 0; i < 2; ++i) {
        delete joueurs[i];
    }
}

void Partie::tour_suivant(){
    if(tour == 1) tour = 2;
    else tour = 1;
}

bool Partie::fin_age(){
    if(platAge.getCartes() == nullptr){//Si il ne reste plus de carte sur le plateau
        if (age == 1){ age = 2; platAge = PlateauAge(2);}
        else if(age == 2) {age = 3; platAge = PlateauAge(3);}
        else {victoire_civile(); return false;} //age 3 finit, vict civile
        return true;
    }
    else return false;
}

void Partie::change_solde_militaire( PlateauJetonMilit &platmilit ){
    solde_militaire = joueurs[0].get_solde_militaire() - joueurs[1].get_solde_militaire();
    if(platmilit.getJetonMilit1_j1()==false) {
        if (solde_militaire >= 3 && solde_militaire <= 5) {
            joueurs[1].set_solde(-2);
            platmilit.setJetonMilit1_j1(true);
        }
    }
    if(platmilit.getJetonMilit1_j2()==false) {
        if (solde_militaire <= -3 && solde_militaire >= -5) {
            joueurs[0].set_solde(-2);
            platmilit.setJetonMilit1_j2(true);
        }
    }
    if(platmilit.getJetonMilit2_j1()==false) {
        if (solde_militaire >= 6 && solde_militaire <= 8) {
            joueurs[1].set_solde(-5);
            platmilit.setJetonMilit2_j1(true);
        }
    }
    if(platmilit.getJetonMilit2_j2()==false) {
        if (solde_militaire <= -6 && solde_militaire >= -8) {
            joueurs[0].set_solde(-5);
            platmilit.setJetonMilit2_j2(true);
        }
    }
}

void Partie::victoire_militaire(){
    if (solde_militaire >= 9) vainqueur = joueurs[0];
    else if(solde_militaire <= -9) vainqueur = joueurs[1];
}

void Partie::victoire_civile(){
    //Parcourir toutes les cartes ainsi que les merveilles construites du joueur, et conversion des pieces en points de pouvoir pour chaque joueur
    //declare un gagnant et un perdant
    unsigned int PtV1 = 0, PtV2 = 0;
    PtV1 += joueurs[0]->getSolde()/3;
    PtV1 += joueurs[1]->getSolde()/3;

    vainqueur =  (PtV1 > PtV2) joueurs[0] : joueurs[1];
}

void Partie::victoire_scientifique(Joueur j){
}

// ********************  Partie selection action ********************

void Partie::choix_jeton(Joueur *j) {
    cout<<"choisissez un jeton"<<endl;
    int choix;cin>>choix;
    j->ajouter_jeton(platJeton.getJetonProgres()[choix]);
}

void Partie::addDefausse(Carte*carte) {
    defausses.push_back(carte);
}

void Partie::selection_action(Joueur &j,PlateauAge &platage){
    cout<<"Choisissez une action :"<<endl;
    cout<<"1. Construire un batiment"<<endl;
    cout<<"2. Construire une merveille"<<endl;
    cout<<"3. Defausser une carte"<<endl;
    int choix;cin>>choix;
    int nb_carte_courante = 0;
    platage.accessibilite();
    // ici l'utilisateur voit la liste des batiments avec leur numéro respectif
    switch (choix)
    {
        case 1:
            //construire un batiment
            if(age==1){
                cout<<"choisissser un batiment a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire

                // construction de la carte
                j.construire_carte(*platage.getCartes()[choix1]);
                //verification que la carte scientifique n'implique pas un jeton
                if(platage.getCartes()[choix1]->getType()==batimentScientifique){
                    if(j.doubleSymbole(platage.getCartes()[choix1]->getSymbole())){
                        choix_jeton(&j);
                    }
                }
                //mettre a jour le plateau
               platage.destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                cout<<"choisissser un batiment a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire

                // construction de la carte
                j.construire_carte(*platage.getCartes()[choix1]);
                //verification que la carte scientifique n'implique pas un jeton
                if(platage.getCartes()[choix1]->getType()==batimentScientifique){
                    if(j.doubleSymbole(platage.getCartes()[choix1]->getSymbole())){
                        choix_jeton(&j);
                    }
                }
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                cout<<"choisissser un batiment a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire

                // construction de la carte
                j.construire_carte(*platage.getCartes()[choix1]);
                //verification que la carte scientifique n'implique pas un jeton
                if(platage.getCartes()[choix1]->getType()==batimentScientifique){
                    if(j.doubleSymbole(platage.getCartes()[choix1]->getSymbole())){
                        choix_jeton(&j);
                    }
                }
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age3(choix1);
            }
            break;

        case 2:
            //construire une merveille
            if(age==1){
                cout<<"choisissser une merveille a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire
                // ( je ne sais pas si construire batiment le fais ** voir chloe**)
                j.construire_carte(*platage.getCartes()[choix1]);
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                cout<<"choisissser une merveille a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire
                // ( il faut une méthode construire une merveille ** voir chloe**)
                j.construire_carte(*platage.getCartes()[choix1]);
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                cout<<"choisissser une merveille a construire"<<endl;
                int choix1;cin>>choix1;
                // il faut vérifier avant si l'on a les ressources nécessaire
                // ( il faut une méthode construire une merveille ** voir chloe**)
                j.construire_carte(*platage.getCartes()[choix1]);
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age3(choix1);
            }
            break;
        case 3 :
            //defausser une carte
            cout<<"choisissser une carte a defausser"<<endl;
            int choix1;cin>>choix1;
            if(age==1){
                // defausser
                addDefausse(platage.getCartes()[choix1]);
                // augmenter le solde du joueur
                j.defausser();
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                // defausser
                addDefausse(platage.getCartes()[choix1]);
                // augmenter le solde du joueur
                j.defausser();
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                // defausser
                addDefausse(platage.getCartes()[choix1]);
                // augmenter le solde du joueur
                j.defausser();
                //mettre a jour le plateau
                platage.destruction_carte_plateau_age3(choix1);
            }
            break;
    }
}