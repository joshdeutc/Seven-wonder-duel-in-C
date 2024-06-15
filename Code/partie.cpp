#include "partie.h"

void Partie::afficherSoldeMilitaire() {
cout<<" \n\n*********** PLATEAU MILITAIRE ***********"<<endl;
    std::string axe(20, '-'); // 19 caractères, représentant -9 à 9
    std::string labels = "-9    -5     0     5     9"; // Les étiquettes pour l'axe

    int position = solde_militaire + 10; // Déplace le solde de -9 à 9 pour être entre 0 et 19{

    // Vérifiez que la position est dans les limites de l'axe
    if (position >= 0 && position < axe.length()) {
        axe[position] = 'X'; // Marque la position actuelle du solde militaire avec un 'X'
    }

    std::cout << labels << std::endl;
    std::cout << axe << std::endl;
}

Partie::Partie(){
    platAge = new PlateauAge(1);
    platMerveille = new PlateauMerveille();
    platProgres = new PlateauJetonProgres();
    platMilitaire = new PlateauJetonMilit();
    for (int i = 0; i < NB_RESSOURCES; ++i) {
        free_res_cartes[i] = 0;
        free_res_jetons[i] = 0;
    }
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
    if (tour==1) tour = 0;
    else tour = 1;
}

// Dans la methode jouer(), tour_suivant va etre appele apres cette methode.
// Donc pour garder le meme joueur on fait tour_suivant() ici, pour changer on ne fait rien
void Partie::changement_joueur() {
    int choix=2;
    Joueur* j_choix;
    
    // Cas 1 : Un des joueurs est mene militairement
    if(solde_militaire>0) j_choix = joueurs[1]; // le joueur 1 est mene militairement si solde positif
    else if(solde_militaire<0) j_choix = joueurs[0]; // le joueur 0 est mene militairement si solde negatif
    
    // Cas 2 : Aucun des joueurs est mene militairement
    else j_choix = joueurs[tour];
    
    
    if( j_choix->getType()==humain ){
        while(choix!=0 && choix!=1) {
            cout << "Choissisez qui commence l'age suivant'" << endl;
            cout << "0. Vous" << endl;
            cout << "1. L'autre joueur" << endl;
            cout << "Votre choix: ";
            cin>>choix;
        }
    }
    else{
        choix = j_choix->choixEntierIA(nullptr,2);
    }
    if(choix==0) {
        tour_suivant();
    }
}


bool Partie::fin_age(){
    if(platAge->verif_plus_de_cartes()){//Si il ne reste plus de carte sur le plateau
        if (age == 1){
            age = 2;
            delete platAge;
            platAge = new PlateauAge(2);
            changement_joueur();
            cout << " ##################################################################################" << endl;
            cout << "                 PASSAGE A L'AGE 2     " << endl;
            cout << "                            -  -     " << endl;
            cout << " ##################################################################################" << endl << endl;
            
            cout << endl;
            pressAnyKeyToContinue();
            cout << endl;
            
            cout << " Voici les jetons mis en jeu (rappel) : " << endl;
            platProgres->afficherJetons();
            cout << endl << endl;
            
            return true;
        }
        else if(age == 2){
            age = 3;
            delete platAge;
            platAge = new PlateauAge(3);
            changement_joueur();
            cout << " ##################################################################################" << endl;
            cout << "                 PASSAGE A L'AGE 3     " << endl;
            cout << "                            -  -     " << endl;
            cout << " ##################################################################################" << endl << endl;
            
            cout << endl;
            pressAnyKeyToContinue();
            cout << endl;
            
            cout << " Voici les jetons mis en jeu (rappel) : " << endl;
            platProgres->afficherJetons();
            cout << endl << endl;
            
            return true;
        }
        else {
            victoire_civile();
            return true;
        }//age 3 finit, vict civile
    }
    else return false;
}

void Partie::change_solde_militaire(bool current,int nb_boucliers){
    int j;
    if(current) {
        j = tour;
    }else j = 1-tour;

    if (j==0) solde_militaire += nb_boucliers;
    if(j ==1) solde_militaire -= nb_boucliers;

    if(!platMilitaire->getJetonMilit1_j1()) {
        if (solde_militaire >= 3 && solde_militaire <= 5) {
            joueurs[1]->setSolde(max(0,joueurs[1]->getSolde()-2));
            platMilitaire->setJetonMilit1_j1(true);
        }
    }
    if(!platMilitaire->getJetonMilit1_j2()) {
        if (solde_militaire <= -3 && solde_militaire >= -5) {
            joueurs[0]->setSolde(max(0,joueurs[0]->getSolde()-2));
            platMilitaire->setJetonMilit1_j2(true);
        }
    }
    if(!platMilitaire->getJetonMilit2_j1()) {
        if (solde_militaire >= 6 && solde_militaire <= 8) {
            joueurs[1]->setSolde(max(0,joueurs[1]->getSolde()-5));
            platMilitaire->setJetonMilit2_j1(true);
        }
    }
    if(!platMilitaire->getJetonMilit2_j2()) {
        if (solde_militaire <= -6 && solde_militaire >= -8) {
            joueurs[0]->setSolde(max(0,joueurs[0]->getSolde()-5));
            platMilitaire->setJetonMilit2_j2(true);
        }
    }

    // on regarde si le joueur a gagné
    if(solde_militaire >=9) victoire_militaire();
    if(solde_militaire <=-9) victoire_militaire();
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
    string nom;
    switch (j.getType()) {
        case TypeJoueur::humain:
            cout << endl << endl << " Vous pouvez choisir un jeton progres ! " << endl;
            pressAnyKeyToContinue();
            cout << endl << "Voici les jetons qui sont en jeu : " << endl << endl;
            platProgres->afficherJetons();
            cout << endl;
            do{
                cout<<"Choisissez un jeton (par son numero) : ";
                cin>>choix;
            }while(choix<1||choix>platProgres->getTaille());
            nom = platProgres->getJetonProgres()[choix-1]->getNom();
            j.ajouterJeton(platProgres->getJetonProgres()[choix-1]);
            platProgres->supprimerJeton(choix-1);
            break;
        case TypeJoueur::IA_aleatoire:
            choix = j.choixEntierIA(nullptr,platProgres->getTaille());
            nom = platProgres->getJetonProgres()[choix-1]->getNom();
            j.ajouterJeton(platProgres->getJetonProgres()[choix]);
            platProgres->supprimerJeton(choix);
            break;
    }
    cout << endl << "Le joueur " << j.getId() << " a choisi le jeton progres " << nom << endl << endl;
}

void Partie::pioche_jeton_hors_jeu(Joueur &j) {
    int choix;
    switch (j.getType()) {
        case TypeJoueur::humain:
            do{
                cout<<"Choisissez un jeton (par son numero) : "<<endl;
                cin>>choix;
            }while(choix<1||choix>platProgres->getTailleHorsJeu());
            j.ajouterJeton(platProgres->getJetonProgresHorsJeu()[choix-1]);
            break;
        case TypeJoueur::IA_aleatoire:
            choix = j.choixEntierIA(nullptr,platProgres->getTailleHorsJeu());
            j.ajouterJeton(platProgres->getJetonProgresHorsJeu()[choix]);
            platProgres->supprimerJeton(choix);
            break;
    }
}

void Partie::addDefausse(Carte* carte) {
    defausses.push_back(carte);
}

Joueur* Partie::autre_joueur(){
    if(tour == 1) return joueurs[0];
    else return joueurs[1];
}

void Partie::defausse_adversaire(TypeCarte type){
    string nom;
    bool valide = true;
    Carte* c = nullptr;
    int n, choix, i=0, k=0;

    if (type == aucuneCarte) throw WondersException("Erreur: defausse adversaire sans type de carte a defausser");

    switch(joueurs[tour]->getType()){
        case humain:
            if (autre_joueur()->nombreCartesDeCategorie(type)==0){
                cout << "Votre adversaire ne possede pas de cartes de type " << type << " vous ne pouvez donc pas en defausser. \n";
                return;
            }
            cout << "Vous pouvez choisir une carte " << type << " de votre adversaire et la defausser. \n";

            cout << endl << "Cite de votre adversaire : " << endl << endl;
            autre_joueur()->afficher();

            cout << "Entrez le nom exact de la carte que vous souhaitez defausser : ";
            getline(cin,nom);
            if (autre_joueur()->recherche_carte(nom)==nullptr)
                valide = false;
            else if (autre_joueur()->recherche_carte(nom)->getType()!=type)
                valide = false;
            while(!valide){
                valide = true;
                cout << "Cette carte n'est pas dans la cite de votre adversaire \n";
                cout << "Entrez le nom exact de la carte que vous souhaitez defausser : ";
                getline(cin,nom);
                if (autre_joueur()->recherche_carte(nom)==nullptr)
                    valide = false;
                else if (autre_joueur()->recherche_carte(nom)->getType()!=type)
                    valide = false;
            }

            c = const_cast<Carte*>(autre_joueur()->recherche_carte(nom));
            autre_joueur()->supprimerCarte(*c);
            addDefausse(c);

            break;
        default: // IA
            n = autre_joueur()->nombreCartesDeCategorie(type);
            if (n==0){
                cout << "L'adversaire ne possede pas de cartes de type " << type << " le joueur ne peut donc pas en defausser. \n";
                return;
            }
            choix = joueurs[tour]->choixEntierIA(nullptr,n);

            // Parcours des cartes
            while(i!=choix && k<autre_joueur()->getNbCartes()){
                if (autre_joueur()->getCartes()[k]->getType() == type)
                    i++;
                if(i!=choix) k++;
            }

            c = const_cast<Carte*>(autre_joueur()->getCartes()[k]);
            autre_joueur()->supprimerCarte(*c);
            addDefausse(c);

            break;
    }
}



void Partie::selection_action(){
    // initialisationd des variables locales
    int choix,choix_max;
    bool done = false;
    string nom_merveille;

    cout << endl << endl;
    cout << "#################################################################\n";
    cout << "                   AFFICHAGE DE L'ETAT DU JEU \n";
    cout << "#################################################################\n";
    cout << endl << endl;

    autre_joueur()->afficher();

    cout << endl;

    joueurs[tour]->afficher();

    cout << endl;

    platAge->accessibilite();

    cout << endl<< "C'est le tour du joueur " << joueurs[tour]->getId() << endl << endl;

    while (!done){
        switch (joueurs[tour]->getType()){
            case humain:
                do{
                    cout<<"Choisissez une action :"<<endl;
                    cout<<"1. Construire un batiment"<<endl;
                    cout<<"2. Defausser une carte"<<endl;
                    if(joueurs[tour]->getNbMerveillesConstruites()+
                       autre_joueur()->getNbMerveillesConstruites()<7 &&
                       joueurs[tour]->getNbMerveillesNonConstruites()>0){
                        cout << "3. Construire une merveille" << endl;
                        choix_max = 3;
                    }else choix_max = 2;
                    cout << "Choix : " ;
                    cin>>choix;
                }while (choix<0||choix>choix_max);
                break;
            default: // IA
                // Il faut verifier si il est possible pour le joueur de construire quoi que ce soit (les options 1 et 2 sont
                // peut-etre indisponibles)
                if(joueurs[tour]->getNbMerveillesConstruites()+
                   autre_joueur()->getNbMerveillesConstruites()<7&&
                   joueurs[tour]->getNbMerveillesNonConstruites()>0) {
                    choix = joueurs[tour]->choixEntierIA(nullptr,3) + 1;
                } else choix = joueurs[tour]->choixEntierIA(nullptr,3);
                break;
        }
        switch (choix){
            case 1:
                done = construire_batiment();
                break;
            case 2:
                done = defausser();
                break;
            case 3:
                done = construire_merveille();
                break;

        }
    }
    afficherSoldeMilitaire();
}

bool Partie::defausser(){
    int choix;

    cout << "DEFAUSSE" << endl;

    switch(joueurs[tour]->getType()){
        case humain:
            cout << "Choisisssez le numero d'un des batiments accessibles a defausser : " ;
            cin >> choix;
            platAge->choix_correct(choix);
            break;
        case IA_aleatoire:
            choix = joueurs[tour]->choixEntierIA(platAge->getTabPossibilites(),platAge->getNbPossibilites());
    }

    platAge->choix_correct(choix);

    // defausser
    addDefausse(platAge->getCartes()[choix]);
    // augmenter le solde du joueur
    joueurs[tour]->defausser();
    if(age==1){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age1(choix);
    }
    if(age==2){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age2(choix);
    }
    if(age==3){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age3(choix);
    }
    return true;
}

// Renvoie vrai si l'utilisateur a bien choisi de construire la carte, faux s'il veut revenir au menu
bool Partie::construire_batiment(){
    int bat, prix, bcl;
    string confirmation;

    cout << "CONSTRUIRE BATIMENT" << endl;

    switch(joueurs[tour]->getType()){
        case humain:
            cout << "Choisisssez le numero d'un des batiments accessibles : " ;
            cin >> bat;
            platAge->choix_correct(bat);
            break;
        case IA_aleatoire:
            bat = joueurs[tour]->choixEntierIA(platAge->getTabPossibilites(),platAge->getNbPossibilites());
    }

    for(int i=0; i<NB_RESSOURCES;i++){
        free_res_jetons[i] = 0;
        free_res_cartes[i] = 0;
    }

    joueurs[tour]->choixRessourcesGratuitesJeton(free_res_jetons,platAge->getCartes()[bat]->getType());
    joueurs[tour]->choixRessourcesGratuitesCartes(free_res_cartes);

    prix = joueurs[tour]->prixFinal(*(platAge->getCartes()[bat]),*autre_joueur(),free_res_jetons,free_res_cartes);

    if(prix > joueurs[tour]->getSolde()){
        if(joueurs[tour]->getType()==humain)
            cout<< "Vous n'avez pas assez de ressources pour construire cette carte." <<endl;
        return false;
    } else {
        if(joueurs[tour]->getType()==humain){
            cout << "Prix du batiment : " << prix << endl;
            do{
                cout << "Souhaitez vous construire le batiment ? O/N : ";
                cin>>confirmation;
            }while (confirmation!="O" && confirmation!="N");
            if (confirmation=="N") return false;
        }
    }

    Carte* c = platAge->getCartes()[bat];

    // Verifications a faire avant de construire la carte
    if(joueurs[tour]->doubleSymbole(c->getSymbole())){
        choix_jeton(*joueurs[tour]);
    }

    // Construction de la carte
    joueurs[tour]->construireCarte(*c,*autre_joueur(),prix);

    cout<<"LA CARTE "<<platAge->getCartes()[bat]->getNom()<<" A ETE CONSTRUITE"<<endl;
    // mis a jour du plateau militaire si besoin
    if(c->getBoucliers()!=0){
        bcl = c->getBoucliers();
        for(int i=0;i<joueurs[tour]->getNbJetons();i++){
            if (joueurs[tour]->getJetons()[i]->getBoucliersSupp()>0) c+= joueurs[tour]->getJetons()[i]->getBoucliersSupp();
        }
        change_solde_militaire(true,c->getBoucliers());
    }
    // test victoire scientifique
    if (joueurs[tour]->nbSymboles()>=6){
        victoire_scientifique(*joueurs[tour]);
        return true;
    }
    if (c->getSoldeRetireAdversaire()>0){
        autre_joueur()->setSolde(max(0,autre_joueur()->getSolde()-c->getSoldeRetireAdversaire()));
    }
    if(c->getPiocheDefausse()){
        pioche_defausse();
    }
    if(c->getDefausseAdversaire()){
        defausse_adversaire(c->getTypeCarteAffectee());
    }

    if(age==1){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age1(bat);
    }
    if(age==2){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age2(bat);
    }
    if(age==3){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age3(bat);
    }
    return true;
}

bool Partie::construire_merveille(){
    int bat, prix;
    const Merveille* merv = nullptr;
    string nom_merv;
    string confirmation;

    cout << "CONSTRUIRE MERVEILLE" << endl;

    // Choix du batiment servant a construire la merveille
    switch(joueurs[tour]->getType()){
        case humain:
            cout << "Choisisssez le numero d'un des batiments accessibles pour le placer sous la merveille : " ;
            cin >> bat;
            platAge->choix_correct(bat);
            break;
        default:
            bat = joueurs[tour]->choixEntierIA(platAge->getTabPossibilites(),platAge->getNbPossibilites());
    }

    for(int i=0; i<NB_RESSOURCES;i++){
        free_res_jetons[i] = 0;
        free_res_cartes[i] = 0;
    }

    // Choix de la merveille a construire
    switch (joueurs[tour]->getType()){
        case humain:
            do{
                cout << "Choisissez une de vos merveilles non construites en tapant au clavier son nom exact: ";
                getline(cin, nom_merv);
                for (int i=0; i<joueurs[tour]->getNbMerveillesNonConstruites(); i++)
                    if (joueurs[tour]->getMerveillesNonConstruites()[i]->getNom()==nom_merv) {
                        merv = joueurs[tour]->getMerveillesNonConstruites()[i];
                    }
                if(merv==nullptr) cout << "Le nom entre n'est pas dans les merveilles non construites." << endl;
            }while(merv==nullptr);
            break;
        default :
            nom_merv = joueurs[tour]->getMerveillesNonConstruites()[joueurs[tour]->choixEntierIA(nullptr,joueurs[tour]->getNbMerveillesNonConstruites())]->getNom();
            merv = dynamic_cast<const Merveille*>(joueurs[tour]->recherche_carte(nom_merv));
    }

    joueurs[tour]->choixRessourcesGratuitesJeton(free_res_jetons, merv->getType());
    joueurs[tour]->choixRessourcesGratuitesCartes(free_res_cartes);

    prix = joueurs[tour]->prixFinal(*merv,*autre_joueur(),free_res_jetons,free_res_cartes);

    if(prix > joueurs[tour]->getSolde()){
        if(joueurs[tour]->getType()==humain)
            cout<< "Vous n'avez pas assez de ressources pour construire cette carte." <<endl;
        return false;
    } else {
        if(joueurs[tour]->getType()==humain){
            cout << "Prix de la merveille : " << prix << endl;
            do{
                cout << "Souhaitez vous construire cette merveille ? O/N : ";
                cin>>confirmation;
            }while (confirmation!="O" && confirmation!="N");
            if (confirmation=="N") return false;
        }
    }
    cout<<"test pour savoir lorsqu'il choisis plusieurs la même merveille"<<endl;
    joueurs[tour]->construireCarte(*merv,*autre_joueur(),prix);
    cout<<"LA CARTE "<<merv->getNom()<<" A ETE CONSTRUITE"<<endl;


    if(joueurs[tour]->doubleSymbole(merv->getSymbole())){
        choix_jeton(*joueurs[tour]);
    }


    // verification que la merveille puisse rejouer ou non
    if(merv->getRejouer()) {
        tour_suivant();
    }
    for(int i=0;i<joueurs[tour]->getNbJetons();i++){
        if(joueurs[tour]->getJetons()[i]->getEffetRejouer() && !merv->getRejouer()){
            tour_suivant();
            break;
        }
    }
    // mis a jour du plateau militaire si besoin
    if(merv->getBoucliers()!=0){
        change_solde_militaire(true,merv->getBoucliers());
    }
    // test victoire scientifique
    if (joueurs[tour]->nbSymboles()>=6){
        victoire_scientifique(*joueurs[tour]);
        return true;
    }
    if (merv->getSoldeRetireAdversaire()>0){
        autre_joueur()->setSolde(max(0,autre_joueur()->getSolde()-merv->getSoldeRetireAdversaire()));
    }
    if(merv->getPiocheDefausse()){
        pioche_defausse();
    }
    if(merv->getDefausseAdversaire()){
        defausse_adversaire(merv->getCarteDefausseAdversaire());
    }
    if(merv->getTirage()){
        pioche_jeton_hors_jeu(*joueurs[tour]);
    }

    if(age==1){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age1(bat);
    }
    if(age==2){
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age2(bat);
    }
    if(age==3) {
        //mettre a jour le plateau
        platAge->destruction_carte_plateau_age3(bat);
    }
    return true;
}


void Partie::choix_merveilles(){
    cout << endl << endl;
    cout << "#######################################################\n";
    cout << "           CHOIX DES MERVEILLES : PHASE 1 \n";
    cout << "#######################################################\n";
    // platMerveille->afficher(1);
    platMerveille->afficher(1);
    int choix;

    cout << endl << "Choix du joueur " << joueurs[0]->getId() << endl;

    switch (joueurs[0]->getType()){
        case humain:
            cout << "Choix (entrer numero de la carte voulue) : ";
            cin >> choix;
            while(choix<1||choix>4){
                cout << "Choix non valide. Veuillez entrer le numero de la carte voulue: ";
                cin>> choix;
            }
            break;
        default: // IA
            choix = joueurs[0]->choixEntierIA(nullptr,4) +1 ;
    }

    cout << endl << joueurs[0]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(1)[choix-1]->getNom() << endl;
    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);

    pressAnyKeyToContinue();

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
    cout << endl << "Le joueur " << joueurs[1]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(1)[choix-1]->getNom() << endl;


    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);

    pressAnyKeyToContinue();

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

    cout << endl << "Le joueur " << joueurs[1]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(1)[choix-1]->getNom() << endl;

    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(1)[choix-1]));
    platMerveille->retirerCarte(1,choix-1);

    cout << endl << "Le joueur " << joueurs[0]->getId() << " prend la derniere merveille : " << platMerveille->getMerveilles(1)[0]->getNom() << endl;

    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(1)[0])); //il ne reste plus qu'une carte

    pressAnyKeyToContinue();

    cout << "#######################################################\n";
    cout << "           CHOIX DES MERVEILLES : PHASE 2 \n";
    cout << "#######################################################\n";

    platMerveille->afficher(2);
    
    cout << endl;
    pressAnyKeyToContinue();
    cout << endl;

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

    cout << endl << joueurs[1]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(2)[choix-1]->getNom() << endl;

    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);


    cout << endl;
    pressAnyKeyToContinue();
    cout << endl;

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

    cout << endl << joueurs[0]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(2)[choix-1]->getNom() << endl;

    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);


    cout << endl;
    pressAnyKeyToContinue();
    cout << endl;

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

    cout << endl << joueurs[0]->getId() << " a choisi la merveille " << platMerveille->getMerveilles(2)[choix-1]->getNom() << endl;

    joueurs[0]->ajouterCarte(*(platMerveille->getMerveilles(2)[choix-1]));
    platMerveille->retirerCarte(2,choix-1);

    cout << endl << "Le joueur " << joueurs[1]->getId() << " prend la derniere merveille : " << platMerveille->getMerveilles(2)[0]->getNom() << endl;

    joueurs[1]->ajouterCarte(*(platMerveille->getMerveilles(2)[0])); //il ne reste plus qu'une carte

    cout << endl;
    pressAnyKeyToContinue();
    cout << endl;

}


void Partie::initJoueurs(){
    int type, IA;
    string nom1,nom2;

    do{
        cout<<"Choissisez le type de partie : 0 pour humain vs humain, 1 pour IA vs humain, 2 pour IA vs IA : ";
        cin>>type;
    }while (type!=0&&type!=1&&type!=2);

    if(type==0) {
        cout<<"Entrez le nom du premier joueur (sans espaces) : ";
        cin>>nom1;
        joueurs[0] = new Joueur(humain,nom1);
        do{
            cout << "Entrez le nom du deuxieme joueur (sans espaces) : ";
            cin>>nom2;
        }while(nom2==nom1);
        joueurs[1] = new Joueur(humain,nom2);
    }
    else if(type==1) {
        cout<<"Entrez le nom du joueur humain (sans espaces) : ";
        cin>>nom1;
        joueurs[0] = new Joueur(humain,nom1);

        do{
            afficher_types_IA();
            cout << "Choisissez le type d'IA souhaité: ";
            cin >> IA;
        }while(IA<1||IA>NB_IA);
        joueurs[1] = new Joueur(static_cast<TypeJoueur>(IA),"IA");
    }else if (type==2){
        do{
            afficher_types_IA();
            cout << "Choisissez le type d'IA 1 souhaité: ";
            cin >> IA;
        }while(IA<0 || IA>NB_IA);
        joueurs[0] = new Joueur(static_cast<TypeJoueur>(IA),"IA 1");
        do{
            afficher_types_IA();
            cout << "Choisissez le type d'IA 2 souhaité: ";
            cin >> IA;
        }while(IA<0 || IA>NB_IA);
        joueurs[1] = new Joueur(static_cast<TypeJoueur>(IA),"IA 2");
    }

}

void Partie::jouer(){
    // choix des types de joueurs

    initJoueurs();

    choix_merveilles();

    tour = 0;
    
    pressAnyKeyToContinue();
    
    cout << endl << endl;
    cout << "Voici les jetons mis en jeu: " << endl << endl;
    
    platProgres->afficherJetons();
    
    cout << endl;

    // boucle de jeu
    while(vainqueur==nullptr && match_nul==false) {
        selection_action();
        fin_age();
        tour_suivant();
        pressAnyKeyToContinue();
    }
}

void pressAnyKeyToContinue() {
    cout << "Appuyez sur une touche pour continuer...";
    cin.get();
}

void Partie::pioche_defausse() {
    bool ok = false;
    int tab_verif[defausses.size()];
    int nb_verif=0;
    if(defausses.size()==0){
        cout<<"Il n'y a pas de carte a recuperer"<<endl;
        return;
    }else {
        for (int i = 0; i < defausses.size(); i++) {
            cout << "carte numero : " << i << "\n" << endl;
            defausses[i]->afficher();
            tab_verif[nb_verif] = i;
            cout << "\n";
            nb_verif++;
        }
        for (int i = nb_verif; i < defausses.size(); i++) tab_verif[i] = -1;
        if (joueurs[tour]->getType() == humain) {
            while (!ok) {
                cout << "choisissez une carte a recuperer" << endl;
                int choix;
                cin >> choix;
                if (choix >= 0 && choix < nb_verif) {
                    ok = true;
                    joueurs[tour]->construireCarte(*defausses[choix], *autre_joueur(), 0);
                    defausses.erase(defausses.begin() + choix);
                }
            }
        } else {
            int choix = joueurs[tour]->choixEntierIA(tab_verif, nb_verif + 1);
            joueurs[tour]->construireCarte(*defausses[choix], *autre_joueur(), 0);
            defausses.erase(defausses.begin() + choix);
        }
    }
}