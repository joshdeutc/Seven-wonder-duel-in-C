#include "partie.h"



Partie::Partie(const TypeJoueur &typJ1,const TypeJoueur &typJ2,string id1,string id2){
    platAge = new PlateauAge(1);
    platMerveille = new PlateauMerveille();
    platProgres = new PlateauJetonProgres();
    platMilitaire = new PlateauJetonMilit();
    joueurs[0] = new Joueur(typJ1,id1);
    joueurs[1] = new Joueur(typJ2,id2);
}

Partie::~Partie() {
    // Libérer la mémoire allouée pour les joueurs
    for (int i = 0; i < 2; ++i) {
        delete joueurs[i];
    }
    delete platAge;
    delete platMerveille;
    delete platProgres;
    delete platMilitaire;
}

void Partie::tour_suivant(){
    tour = (tour == 1) ? 2 : 1;
}

bool Partie::fin_age(){
    if(platAge->getCartes() == nullptr){//Si il ne reste plus de carte sur le plateau
        if (age == 1){
            age = 2;
            delete platAge;
            platAge = new PlateauAge(2);
            return true;
        }
        else if(age == 2){
            age = 3; 
            delete platAge;
            platAge = new PlateauAge(3);
            return true;
        }
        else {
            victoire_civile();
            return true;
        }//age 3 finit, vict civile
    }
    else return false;
}

void Partie::change_solde_militaire(bool current,const int &choix){
    int j;
    if(current) {
        j = tour;
    }else j = 1-tour;

    if (j==0) solde_militaire += platAge->getCartes()[choix]->getBoucliers();
    if(j ==1) solde_militaire -= platAge->getCartes()[choix]->getBoucliers();

    if(!platMilitaire->getJetonMilit1_j1()) {
        if (solde_militaire >= 3 && solde_militaire <= 5) {
            joueurs[1]->setSolde(-2);
            platMilitaire->setJetonMilit1_j1(true);
        }
    }
    if(!platMilitaire->getJetonMilit1_j2()) {
        if (solde_militaire <= -3 && solde_militaire >= -5) {
            joueurs[0]->setSolde(-2);
            platMilitaire->setJetonMilit1_j2(true);
        }
    }
    if(!platMilitaire->getJetonMilit2_j1()) {
        if (solde_militaire >= 6 && solde_militaire <= 8) {
            joueurs[1]->setSolde(-5);
            platMilitaire->setJetonMilit2_j1(true);
        }
    }
    if(!platMilitaire->getJetonMilit2_j2()) {
        if (solde_militaire <= -6 && solde_militaire >= -8) {
            joueurs[0]->setSolde(-5);
            platMilitaire->setJetonMilit2_j2(true);
        }
    }
}


void Partie::victoire_civile(){
    // Mise a jour des points de victoire des deux joueurs

    int nb1,nb2,nbMax;
    int indice_other;
    int pts0 = 0, pts1 = 0;

    for(int j=0;j<2;j++){

        indice_other = 1-j; // autre joueur

        // Jetons Progres
        for(int i=0;i<joueurs[j]->getNbJetons();i++){
            if (joueurs[j]->getJetons()[i]->getPointsCondition()){
                if (joueurs[j]->getJetons()[i]->getConditionJeton()){
                    joueurs[j]->addPoints(joueurs[j]->getNbJetons()*joueurs[j]->getJetons()[i]->getPointsCondition());
                }
            }
        }

        // Cartes Guilde
        for (int i=0; i<joueurs[j]->getNbCartes(); i++){
            if (joueurs[j]->getCartes()[i]->getPointsParCarte()>0){
                if(joueurs[j]->getCartes()[i]->getTypeCarteAffectee()!=aucuneCarte){
                    if(joueurs[j]->getCartes()[i]->getDeuxiemeTypeCarteAffectee()!=aucuneCarte){
                        nb1 = (joueurs[j]->nombreCartesDeCategorie(joueurs[j]->getCartes()[i]->getTypeCarteAffectee())
                               +joueurs[j]->nombreCartesDeCategorie(joueurs[j]->getCartes()[i]->getDeuxiemeTypeCarteAffectee()));
                        nb2 = (joueurs[indice_other]->nombreCartesDeCategorie(joueurs[indice_other]->getCartes()[i]->getTypeCarteAffectee())
                               +joueurs[indice_other]->nombreCartesDeCategorie(joueurs[indice_other]->getCartes()[i]->getDeuxiemeTypeCarteAffectee()));
                    }else{ // un seul type de carte est affecte
                        nb1 = (joueurs[j]->nombreCartesDeCategorie(joueurs[j]->getCartes()[i]->getTypeCarteAffectee()));
                        nb2 = (joueurs[indice_other]->nombreCartesDeCategorie(joueurs[indice_other]->getCartes()[i]->getTypeCarteAffectee()));
                    }
                }else{ // si aucune carte n'est affectee on compte les pieces
                    nb1 = joueurs[j]->getSolde()/3;
                    nb2 = joueurs[indice_other]->getSolde()/3;
                }
                joueurs[j]->addPoints(joueurs[j]->getCartes()[i]->getPointsParCarte()*max(nb1,nb2));
            }
        }

        // Tresors de la cite
        joueurs[j]->addPoints(joueurs[j]->getSolde()/3);

    } // Fin de la mise a jour des points de victoire des joueurs

    //Points de victoire militaire
    if(solde_militaire<-5) joueurs[1]->addPoints(10);
    else if (solde_militaire<-2) joueurs[1]->addPoints(5);
    else if (solde_militaire<0) joueurs[1]->addPoints(2);
    else if (solde_militaire>5) joueurs[0]->addPoints(10);
    else if (solde_militaire>2) joueurs[0]->addPoints(5);
    else if (solde_militaire>0) joueurs[0]->addPoints(2);

    cout << " ##################################################################################" << endl;
    cout << "                               FIN DE PARTIE     " << endl;
    cout << "                            - victoire civile -     " << endl;
    cout << " ##################################################################################" << endl << endl;

    joueurs[0]->afficher();
    cout << endl << endl;
    joueurs[1]->afficher();
    cout << endl << endl;

    if(joueurs[0]->getPoints()>joueurs[1]->getPoints()){
        vainqueur = joueurs[0];
    }else if(joueurs[1]->getPoints()>joueurs[0]->getPoints()){
        vainqueur = joueurs[1];
    }else{ // Égalité
        // Il faut compter les points de victoire des batiments civils
        for(int i=0;i<joueurs[0]->getNbCartes(); i++){
            if (joueurs[0]->getCartes()[i]->getType()==batimentCivil)
                pts0+=joueurs[0]->getCartes()[i]->getPoints();
        }
        for(int i=0;i<joueurs[1]->getNbCartes(); i++){
            if (joueurs[1]->getCartes()[i]->getType()==batimentCivil)
                pts1+=joueurs[1]->getCartes()[i]->getPoints();
        }
        if(pts0>pts1){
            vainqueur = joueurs[0];
        }else if(pts1>pts0){
            vainqueur = joueurs[0];
        }
    }
    if(vainqueur!=nullptr){
        cout << " Le vainqueur est " << vainqueur->getId() << " ! " << endl;
    }else{
        cout << " Egalite ! Les deux joueurs se partagent la victoire. \n";
        match_nul = true;
    }
}



void Partie::victoire_scientifique(Joueur& j){
    unsigned int compteur = 0;

    cout << " ##################################################################################" << endl;
    cout << "                               FIN DE PARTIE     " << endl;
    cout << "                         - victoire scientifique -     " << endl;
    cout << " ##################################################################################" << endl << endl;

    if(j.nbSymboles()>=6) vainqueur = &j;
    if (vainqueur!=nullptr){
        cout << endl << endl;
        cout << " Le vainqueur est " << vainqueur->getId() << " ! " << endl << endl;
    }
}

void Partie::victoire_militaire(){

    cout << " ##################################################################################" << endl;
    cout << "                               FIN DE PARTIE     " << endl;
    cout << "                           - victoire militaire -     " << endl;
    cout << " ##################################################################################" << endl << endl;
    if(solde_militaire >=9) vainqueur = joueurs[0];
    else if (solde_militaire <=-9) vainqueur = joueurs[1];
    cout << endl << endl;
    cout << " Le vainqueur est " << vainqueur->getId() << " ! " << endl << endl;
}

// ********************  Partie selection action ********************

void Partie::choix_jeton(Joueur &j) {
    int choix;
    switch (j.getType()) {
        case TypeJoueur::humain:
            cout<<"choisissez un jeton"<<endl;
            cin>>choix;
            j.ajouterJeton(platProgres->getJetonProgres()[choix]);
            break;
        case TypeJoueur::IA_aleatoire:
            cout<<"choisissez un jeton"<<endl;
            cin>>choix;
            j.ajouterJeton(platProgres->getJetonProgres()[choix]);
            break;
    }
}

void Partie::addDefausse(Carte*carte) {
    defausses.push_back(carte);
}

Joueur* Partie::autre_joueur(){
    if(tour == 1) return joueurs[1];
    else return joueurs[0];
}



void Partie::selection_action(Joueur &j_current){
    platAge->accessibilite();
    cout<<"Choisissez une action :"<<endl;
    cout<<"1. Construire un batiment"<<endl;
    cout<<"2. Construire une merveille"<<endl;
    cout<<"3. Defausser une carte"<<endl;
    int choix;cin>>choix;
    int choix1;
    // ici l'utilisateur voit la liste des batiments avec leur numéro respectif
    switch (choix)
    {
        case 1:
            //construire un batiment
            cout<<"choisissser un batiment a construire"<<endl;
            cin>>choix1;
            platAge->choix_correct(choix1);
            // il faut vérifier avant si l'on a les ressources nécessaire

            // construction de la carte
            j_current.construireCarte(*(platAge->getCartes()[choix1]),*autre_joueur());
            //verification que la carte scientifique n'implique pas un jeton
            if(platAge->getCartes()[choix1]->getType()==batimentScientifique){
                if(j_current.doubleSymbole(platAge->getCartes()[choix1]->getSymbole())){
                    choix_jeton(j_current);
                }
            }
            // mis a jour du plateau militaire si besoin
            if(platAge->getCartes()[choix1]->getBoucliers()!=0){
                change_solde_militaire(true,choix1);
            }
            if(age==1){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age3(choix1);
            }
            break;

        case 2:
            //construire une merveille
            cout<<"choisissser une merveille a construire"<<endl;
            cin>>choix1;
            platAge->choix_correct(choix1);
            // il faut vérifier avant si l'on a les ressources nécessaire

            // ( je ne sais pas si construire batiment le fais ** voir chloe**)
            j_current.construireCarte(*(platAge->getCartes()[choix1]),*autre_joueur());
            // mis a jour du plateau militaire si besoin
            if(platAge->getCartes()[choix1]->getBoucliers()!=0){
                change_solde_militaire(true,choix1);
            }
            if(age==1){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age3(choix1);
            }
            break;
        case 3 :
            //defausser une carte
            cout<<"choisissser une carte a defausser"<<endl;
            cin>>choix1;
            platAge->choix_correct(choix1);
            // defausser
            addDefausse(platAge->getCartes()[choix1]);
            // augmenter le solde du joueur
            j_current.defausser();
            if(age==1){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age1(choix1);
            }
            if(age==2){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age2(choix1);
            }
            if(age==3){
                //mettre a jour le plateau
                platAge->destruction_carte_plateau_age3(choix1);
            }
            break;
    }

}

void Partie::choix_merveilles(){
    cout << "#######################################################\n";
    cout << "           CHOIX DES MERVEILLES : PHASE 1 \n";
    cout << "#######################################################\n";
    platMerveille->afficher(1);
    int choix;
    
    cout << endl << "Choix du joueur " << joueurs[0]->getId() << endl;
    
    switch (joueurs[0]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>4){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[0]->choixEntierIA(nullptr,4) +1 ;
    }
    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);
    
    cout << endl;
    platMerveille->afficher(1);
    cout << endl << "Choix du joueur " << joueurs[1]->getId() << endl;

    

    switch (joueurs[1]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>3){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[1]->choixEntierIA(nullptr,3) +1 ;
    }
    cout << "choix IA : "<<choix << endl;
    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);
    
    cout << endl;
    platMerveille->afficher(1);
    cout << endl << "Choix du joueur " << joueurs[1]->getId() << endl;


    switch (joueurs[1]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>2){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[1]->choixEntierIA(nullptr,2) +1 ;
    }
    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);
    
    cout << "Le joueur " << joueurs[0]->getId() << " prend la derniere merveille. \n" << endl;
    
    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(1)[0])); //il ne reste plus qu'une carte
    
    cout << "#######################################################\n";
    cout << "           CHOIX DES MERVEILLES : PHASE 2 \n";
    cout << "#######################################################\n";
    
    platMerveille->afficher(2);
    
    cout << endl << "Choix du joueur " << joueurs[1]->getId() << endl;
    
    switch (joueurs[1]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>4){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[1]->choixEntierIA(nullptr,4) +1 ;
    }
    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);
    
    cout << endl;
    platMerveille->afficher(2);
    cout << endl << "Choix du joueur " << joueurs[0]->getId() << endl;


    switch (joueurs[0]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>3){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[0]->choixEntierIA(nullptr,3) +1 ;
    }
    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);
    
    cout << endl;
    platMerveille->afficher(2);
    cout << endl << "Choix du joueur " << joueurs[0]->getId() << endl;


    switch (joueurs[0]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1 || choix>2){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[0]->choixEntierIA(nullptr,2) +1 ;
    }
    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);
    
    cout << "Le joueur " << joueurs[1]->getId() << " prend la derniere merveille. \n" << endl;
    
    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(2)[0])); //il ne reste plus qu'une carte
    
}
