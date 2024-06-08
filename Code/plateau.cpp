#include "plateau.h"

// *************** PARTIE CONSTRUCTEUR AGE ****************** //


PlateauAge::PlateauAge(int Age) // Il faut initialiser les attributs face_visible, face_cache etc des Carte
//s en fonction de l'age
{
    switch (Age){
        case 1:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));

            // Tableau pour stocker les indices des cartes sélectionnées
            int indicesSelectionnes[20];

            // Sélection aléatoire de 20 indices distincts
            int nombreCartes = 23;
            for (int i = 0; i < 20; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j = 0; j < i; ++j) {
                        if (indicesSelectionnes[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnes[i] = indice;
            }

            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Carte*[20];

            // Copie des cartes sélectionnées dans le tableau du plateau
            for (int i = 0; i < 20; ++i) {
                cartes[i] = Jeu::getInstance()->tabCartesAge1[indicesSelectionnes[i]];
            }

            // initialisationd des cartes face visible et accessible
            for(int i=0;i<6;i++){
                cartes[i]->set_accessible(true);
            }
            for(int i=6;i<20;i++){
                cartes[i]->set_accessible(false);
            }
            for(int i=0;i<6;i++){
                cartes[i]->set_face_visible(true);
                etage1.push_back(cartes[i]);
            }
            for(int i=6;i<11;i++){
                cartes[i]->set_face_visible(false);
                etage2.push_back(cartes[i]);
            }
            for(int i=11;i<15;i++){
                cartes[i]->set_face_visible(true);
                etage3.push_back(cartes[i]);
            }
            for(int i=15;i<18;i++){
                cartes[i]->set_face_visible(false);
                etage4.push_back(cartes[i]);
            }
            for(int i=18;i<20;i++){
                cartes[i]->set_face_visible(true);
                etage5.push_back(cartes[i]);
            }
            break;}
        case 2:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));

            // Tableau pour stocker les indices des cartes sélectionnées
            int indicesSelectionnes[20];

            // Sélection aléatoire de 20 indices distincts
            int nombreCartes = 23;
            for (int i = 0; i < 20; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j = 0; j < i; ++j) {
                        if (indicesSelectionnes[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnes[i] = indice;
            }

            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Carte*[20];

            // Copie des cartes sélectionnées dans le tableau du plateau
            for (int i = 0; i < 20; ++i) {
                cartes[i] = Jeu::getInstance()->tabCartesAge2[indicesSelectionnes[i]];
            }

            // initialisationd des cartes face visible et accessible
            for(int i=0;i<2;i++){
                cartes[i]->set_accessible(true);
            }
            for(int i=2;i<20;i++){
                cartes[i]->set_accessible(false);
            }
            for(int i=0;i<2;i++){
                cartes[i]->set_face_visible(true);
                etage1.push_back(cartes[i]);
                cout<<"taille de etage1 ="<<etage1.size()<<endl;
            }
            for(int i=2;i<5;i++){
                cartes[i]->set_face_visible(false);
                etage2.push_back(cartes[i]);
            }
            for(int i=5;i<9;i++){
                cartes[i]->set_face_visible(true);
                etage3.push_back(cartes[i]);
            }
            for(int i=9;i<14;i++){
                cartes[i]->set_face_visible(false);
                etage4.push_back(cartes[i]);
            }
            for(int i=14;i<20;i++){
                cartes[i]->set_face_visible(true);
                etage5.push_back(cartes[i]);
            }
            break;}
        case 3:{
            // Initialiser la graine de la fonction rand()
            srand(time(nullptr));

            // Tableau pour stocker les indices des cartes Age sélectionnées
            int indicesSelectionnesAge3[17];

            // Sélection aléatoire de 17 indices distincts
            int nombreCartes = 20;
            for (int i=0; i<17; ++i) {
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j= 0; j<i; ++j) {
                        if (indicesSelectionnesAge3[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnesAge3[i] = indice;
            }

            // Tableau pour stocker les indices des cartes Guilde sélectionnées
            int indicesSelectionnesGuilde[3];

            //Sélection aléatoire de 3 indices distincts
            nombreCartes = 7;
            for(int i = 0;i<3;i++){
                int indice;
                bool dejaSelectionne;
                do {
                    indice = rand() % nombreCartes; // Générer un index aléatoire
                    dejaSelectionne = false;
                    // Vérifier si l'index a déjà été sélectionné
                    for (int j= 0; j<i; ++j) {
                        if (indicesSelectionnesGuilde[j] == indice) {
                            dejaSelectionne = true;
                            break;
                        }
                    }
                } while (dejaSelectionne); // Répéter tant que l'index est déjà sélectionné
                indicesSelectionnesGuilde[i] = indice;
            }


            // Allocation dynamique du tableau de cartes sélectionnées
            cartes = new Carte*[20];

            // Distribution aléatoire des cartes de l'Âge 3 et des cartes Guilde dans le tableau cartes
            int indiceAge3 = 0;
            int indiceGuilde = 0;
            for (int i = 0; i < 20; ++i) {
                // Sélectionner aléatoirement entre une carte de l'Âge 3 et une carte Guilde
                double probaCarteAge3 = (17.0 - indiceAge3) / (20.0 - i); // Probabilité de choisir une carte de l'Âge 3
                double probaCarteGuilde = (3.0 - indiceGuilde) / (20.0 - i); // Probabilité de choisir une carte Guilde
                bool estCarteAge3 = (rand() / (RAND_MAX + 1.0)) < probaCarteAge3; // Comparaison avec une probabilité uniforme entre 0 et 1

                if (estCarteAge3 && indiceAge3 < 17) {
                    // Si c'est une carte de l'Âge 3 et il reste des cartes de l'Âge 3 non sélectionnées
                    cartes[i] = Jeu::getInstance()->tabCartesAge3[indicesSelectionnesAge3[indiceAge3]];
                    ++indiceAge3;
                } else if (indiceGuilde < 3) {
                    // Si c'est une carte Guilde et il reste des cartes Guilde non sélectionnées
                    cartes[i] = Jeu::getInstance()->tabCartesGuilde[indicesSelectionnesGuilde[indiceGuilde]];
                    ++indiceGuilde;
                } else {
                    // Si on a épuisé les cartes Guilde disponibles, distribuer les cartes de l'Âge 3 restantes
                    cartes[i] = Jeu::getInstance()->tabCartesAge3[indicesSelectionnesAge3[indiceAge3]];
                    ++indiceAge3;
                }
            }
            for(int i=0;i<2;i++){
                cartes[i]->set_accessible(true);
            }
            for(int i=2;i<20;i++){
                cartes[i]->set_accessible(false);
            }
            for(int i=0;i<2;i++){
                cartes[i]->set_face_visible(true);
                etage1.push_back(cartes[i]);
            }
            for(int i=2;i<5;i++){
                cartes[i]->set_face_visible(false);
                etage2.push_back(cartes[i]);
            }
            for(int i=5;i<9;i++){
                cartes[i]->set_face_visible(true);
                etage3.push_back(cartes[i]);
            }
            for(int i=9;i<11;i++){
                cartes[i]->set_face_visible(false);
                etage4.push_back(cartes[i]);
            }
            for(int i=11;i<15;i++){
                cartes[i]->set_face_visible(true);
                etage5.push_back(cartes[i]);
            }
            for(int i=15;i<18;i++){
                cartes[i]->set_face_visible(false);
                etage6.push_back(cartes[i]);
            }
            for(int i=18;i<20;i++){
                cartes[i]->set_face_visible(true);
                etage7.push_back(cartes[i]);
            }
            break;
        }

    }
}

PlateauAge::~PlateauAge()
{
    //On ne supprime pas les cartes elles mêmes, elles seront supprimees quand l'instance Jeu sera supprimée.
    delete[] cartes;
}

// ************** PLATEAU MERVEILLE ************* /////

PlateauMerveille::PlateauMerveille()
{
    Merveille** cartesPremierPhase = new Merveille*[4];
    Merveille** cartesDeuxiemePhase = new Merveille*[4];

    // Génération d'un tableau de 8 entiers distincts aléatoires
    std::vector<int> intVect = generateRandomDistinctIntegers(8, 0, 7);
    for (int i = 0; i < 4; ++i) {
        cartesPremierPhase[i] = Jeu::getInstance()->getTabCartesMerveille()[intVect[i]];
        cartesDeuxiemePhase[i] = Jeu::getInstance()->getTabCartesMerveille()[intVect[i + 4]];
    }

}

PlateauMerveille::~PlateauMerveille()
{
    //On ne supprime pas les cartes elles mêmes, elles seront supprimees quand l'instance Jeu sera supprimée.
    delete[] cartesPremierPhase;
    delete[] cartesDeuxiemePhase;
}

// ****************************************************************//

// ***************** PARTIE PLATEAU JETON MILIT *****************//

PlateauJetonProgres::PlateauJetonProgres() {
    jetonprogres = new JetonProgres *[5];
    // Génération d'un tableau de 5 entiers distincts aléatoires
    std::vector<int> intVect = generateRandomDistinctIntegers(5, 0, 4);
    for (int i = 0; i < 5; ++i) {
        jetonprogres[i] = Jeu::getInstance()->getTabJetonProgres()[intVect[i]];
    }
}

PlateauJetonProgres::~PlateauJetonProgres() {
    //On ne supprime pas les jetons eux-mêmes, ils seront supprimés quand l'instance Jeu sera supprimée.
    delete[] jetonprogres;
}

// ******************** PARTIE ACTION JOUEUR ******************//


vector<Carte*>  PlateauAge::trouver_etage_age1(int& choix){
    if(0<=choix && choix<=5){
        return etage1;
    }
    else if(6<=choix && choix<=10){
        return etage2;
    }
    else if(11<=choix && choix<=14){
        return etage3;
    }
    else if(15<=choix && choix<=17){
        return etage4;
    }
    return etage5;
}

vector<Carte*>  PlateauAge::trouver_etage_age2(int &choix){
    if(0<=choix && choix<=1){
        return etage1;
    }
    if(2<=choix && choix<=4){
        return etage2;
    }
    if(5<=choix && choix<=8){
        return etage3;
    }
    if(9<=choix && choix<=13){
        return etage4;
    }
    return etage5;
}

vector<Carte*> PlateauAge::trouver_etage_age3(int &choix){
    if(0<=choix && choix<=1){
        return etage1;
    }
    if(2<=choix && choix<=4){
        return etage2;
    }
    if(5<=choix && choix<=8){
        return etage3;
    }
    if(9<=choix && choix<=10){
        return etage4;
    }
    if(11<=choix && choix<=14){
        return etage5;
    }
    if(15<=choix && choix<=17){
        return etage6;
    }
    return etage7;
}

bool PlateauAge::deviens_accessible_age1(int &choix){
    vector<Carte*> etage = trouver_etage_age1(choix);
    int pere1,pere2;
    if(etage==etage5){
        return false;
    }
    if(getCartes()[choix] == etage[0]){
        cout<<"test\n";
        pere1=choix+etage.size();
        if(getCartes()[choix+1]==nullptr){
            getCartes()[pere1]->set_accessible(true);
            return true;
        }
        else return false;
    }
    if(getCartes()[choix] == etage[etage.size()-1]){
        pere1=choix+etage.size()-1;
        if(getCartes()[choix-1]==nullptr){
            getCartes()[pere1]->set_accessible(true);
            return true;
        }
        else return false;
    }
    else{
        pere1=choix+etage.size();
        pere2=choix+etage.size()-1;
        if(getCartes()[choix+1]==nullptr){
            getCartes()[pere1]->set_accessible(true);
        }
        if(getCartes()[choix-1]==nullptr){
            getCartes()[pere2]->set_accessible(true);
        }
        if(getCartes()[choix+1]==nullptr || getCartes()[choix-1]==nullptr){
            return true;
        }
        else return false;
    }
}

bool PlateauAge::deviens_accessible_age2(int &choix) {
    vector <Carte*> etage = trouver_etage_age2(choix);
    int pere1 = choix + etage.size();// pere de gauche
    int pere2 = choix + etage.size() + 1; // pere de droite
    if(etage==etage5){
        return false;
    }
    if(cartes[choix] == etage[0]){
        getCartes()[pere1]->set_accessible(true);
        if(cartes[choix+1]==nullptr){
            getCartes()[pere2]->set_accessible(true);
        }
        return true;
    }
    if(cartes[choix]==etage[etage.size()-1]) {
        getCartes()[pere2]->set_accessible(true);
        if (cartes[choix - 1] == nullptr) {
            getCartes()[pere1]->set_accessible(true);
        }
        return true;
    }
    else{
        if(cartes[choix+1]==nullptr){
            getCartes()[pere2]->set_accessible(true);
        }
        if(cartes[choix-1]==nullptr){
            getCartes()[pere1]->set_accessible(true);
        }
        if(cartes[choix+1]==nullptr || cartes[choix-1]==nullptr){
            return true;
        }
        else return false;
    }
}

bool PlateauAge::deviens_accessible_age3(int &choix){
    vector<Carte*> etage = trouver_etage_age3(choix);
    int pere1,pere2;
    // cas des étages
    if(etage==etage7){
        return false;
    }
    if(etage==etage1 ||  etage==etage2 ){
        //cas du cas ou l'on est comme dans l'age 2
        pere1 = choix + etage.size();// pere de gauche
        pere2 = choix + etage.size() + 1; // pere de droite
        if(cartes[choix] == etage[0]){
            getCartes()[pere1]->set_accessible(true);
            if(cartes[choix+1]==nullptr){
                getCartes()[pere2]->set_accessible(true);
            }
            return true;
        }
        if(cartes[choix]==etage[etage.size()-1]) {
            getCartes()[pere2]->set_accessible(true);
            if (cartes[choix - 1] == nullptr) {
                getCartes()[pere1]->set_accessible(true);
            }
            return true;
        }
        else{
            if(cartes[choix+1]==nullptr){
                getCartes()[pere2]->set_accessible(true);
            }
            if(cartes[choix-1]==nullptr){
                getCartes()[pere1]->set_accessible(true);
            }
            if(cartes[choix+1]==nullptr || cartes[choix-1]==nullptr){
                return true;
            }
            else return false;
        }
    }
    if(etage==etage5 || etage==etage6){
        //cas du cas ou l'on est comme dans l'age 1
        if(getCartes()[choix] == etage[0]){
            pere1=choix+etage.size();
            if(getCartes()[choix+1]==nullptr){
                getCartes()[pere1]->set_accessible(true);
                return true;
            }
            else return false;
        }
        if(getCartes()[choix] == etage[etage.size()-1]){
            pere1=choix+etage.size()-1;
            if(getCartes()[choix-1]==nullptr){
                getCartes()[pere1]->set_accessible(true);
                return true;
            }
            else return false;
        }
        else{
            pere1=choix+etage.size();
            pere2=choix+etage.size()-1;
            if(getCartes()[choix+1]==nullptr){
                getCartes()[pere1]->set_accessible(true);
            }
            if(getCartes()[choix-1]==nullptr){
                getCartes()[pere2]->set_accessible(true);
            }
            if(getCartes()[choix+1]==nullptr || getCartes()[choix-1]==nullptr){
                return true;
            }
            else return false;
        }
    }
    else{
        if(etage==etage3){
            if(choix==5){
                pere1=choix+etage.size();
                if(getCartes()[choix+1]==nullptr){
                    getCartes()[pere1]->set_accessible(true);
                    return true;
                }
                else return false;
            }
            if(choix==6){
                pere1=choix+etage.size()-1;
                if(getCartes()[choix-1]==nullptr){
                    getCartes()[pere1]->set_accessible(true);
                    return true;
                }
                else return false;
            }
            if(choix==7){
                pere1=choix+etage.size()-1;
                if(getCartes()[choix+1]==nullptr){
                    getCartes()[pere1]->set_accessible(true);
                    return true;
                }
                else return false;
            }
            if(choix==8){
                pere1=choix+etage.size()-2;
                if(getCartes()[choix-1]==nullptr){
                    getCartes()[pere1]->set_accessible(true);
                    return true;
                }
                else return false;
            }
        }
        if(etage==etage4){
            if(choix==9){
                pere1=choix+etage.size();//pere de gauche
                pere2=choix+etage.size()+1;// pere de droite
            }
            else{
                pere1=choix+etage.size()+1;//pere de gauche
                pere2=choix+etage.size()+2;// pere de droite
            }
            getCartes()[pere1]->set_accessible(true);
            getCartes()[pere2]->set_accessible(true);
            return true;
        }
    }
    return false;
}
// ***************** PARTIE ACCCESSIBLITE ************** //


void PlateauAge::accessibilite(){
    for(int i=0;i<20;i++){
        if(cartes[i]){
            if(getCartes()[i]->get_accessible() == true){
                cout<<"carte numero : "<<i<<"\n"<<endl;
                getCartes()[i]->afficher(cout);
                tab_possibilite[i]=i;
                cout<<"\n";
            }
        }else tab_possibilite[i]=0;
    }
}

void PlateauAge::choix_correct(int &choix) {
    while(!tab_possibilite[choix]) {
        cout<<"choix incorrect, refaire le choix svp :\n";
        cin>>choix;
    }
}
void PlateauAge::destruction_carte_plateau_age1(int &choix) {
    // on mets a jour le tableau des cartes
    this->deviens_accessible_age1(choix);
    cout<<"on est sortis  de deviens_accessible_age1\n";
    // on détruit la carte
    cartes[choix] = nullptr;
    cout<<"on est sortis  de destruction_carte_plateau_age1\n";
}

void PlateauAge::destruction_carte_plateau_age2(int &choix) {
    // on mets a jour le tableau des cartes
    this->deviens_accessible_age2(choix);
    // on détruit la carte
    cartes[choix] = nullptr;
}

void PlateauAge::destruction_carte_plateau_age3(int &choix){
    // on mets a jour le tableau des cartes
    this->deviens_accessible_age3(choix);
    // on détruit la carte
    cartes[choix] = nullptr;
}