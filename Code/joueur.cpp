#include "joueur.h"
//#define NB_SYMB 6

//Dans cette partie on considère que le Joueur a un seul tableau de pointeurs Batiment**
//Il a un tableau spécifique pour les merveilles non construites afin de différencier les merveilles
//construites des merveilles seulement possédées mais non construites.

Joueur::Joueur(TypeJoueur type_joueur, string identifiant){
    type = type_joueur;
    id = identifiant;
    cartes = new const Carte*[nb_cartesMax];
    //points, solde et ressources sont deja initialisees
    for(int i=0;i<nb_cartesMax;i++) cartes[i]=nullptr;
    for(int i=0;i<NB_JETONS;i++) jetons[i] = nullptr;
    for (int i=0; i<7; i++){
        merveillesNonConstruites[i] = nullptr;
    }
}

Joueur::~Joueur(){
    delete[] cartes;
}

int Joueur::nbSymboles() const{
    int nb=0;
    for(int i=1; i<(NB_SYMB) ; i++){
        if (symboles[i]>1) nb++;
    }
    return nb;
}

// A appeler dans partie avant d'appeler la construction de la carte (sinon ça retournera
// forcément vrai)
bool Joueur::doubleSymbole(SymboleScientifique s){
    if (s == aucunSymbole) return false;
    int nb = 0;
    for (int i=0;i<nb_cartes;i++)
        if (cartes[i]->getType() == batimentScientifique)
            if (cartes[i]->getSymbole()== s)
                nb++;
    return nb>1;
}

//Cette méthode se charge d'effectuer les effets immédiats d'un jeton progrès.
//Les autres effets seront gérés par d'autres classes au moment pertinent
void Joueur::ajouterJeton(JetonProgres* jeton){
    points+=jeton->getPoints();
    solde+=jeton->getSoldeImmediat();
    if(jeton->getSymbole()!=aucunSymbole) symboles[jeton->getSymbole()]=1;
    
    //ajout du jeton aux attributs du joueur
    jetons[nb_jetons++] = jeton;
}

// Cette fonction renvoie vrai si la ressource r est au prix fixe de 1 piece pour le joueur
bool Joueur::prixFixe(Ressource r) const{
    for(int i=0;i<nb_cartes;i++)
        if(cartes[i]->engendrePrixFixe() && cartes[i]->getRessourcesAffectees()[r])
            return true;
    return false;
}

//Il faudrait ajouter une methode supprimer(carte) a la classe Partie pour l'enlever du plateau

//Cette fonction met seulement a jour les attributs de Joueur lors de la defausse.
//Il faut une methode de Partie qui permet de placer un batiment sur le plateau defausse (avec une methode du plateau defausse ajouter)
//ainsi que le retirer du plateau Age
void Joueur::defausser(){
    //Methode disponible pour toutes les cartes; independamment de la cite du joueur.
    
    int gain=2+nombreCartesDeCategorie(batimentCommerce);
    solde += gain;
}

void Joueur::ajouterCarte(const Carte& c, bool construire){
    //Recopier la maniere de faire du td4 pour le jeu SET! avec old_tab, new_tab et delete
    //modifie donc l'attribut batiments
    if(construire){
        if (c.getType()==merveille){
            nb_merveilles_construites++;
            // Supprimer la merveille du tableau des non construites si elle est dedans
            int i = 0;
            while (i < nb_merveilles_non_construites && merveillesNonConstruites[i]->getNom() != c.getNom()) i++;
            if (i < nb_merveilles_non_construites) {
                // Déplacer les éléments après l'élément supprimé
                for (int j = i; j < nb_merveilles_non_construites - 1; j++) {
                    merveillesNonConstruites[j] = merveillesNonConstruites[j + 1];
                }
                // Décrémenter le compteur et mettre le dernier élément à nullptr
                merveillesNonConstruites[--nb_merveilles_non_construites] = nullptr;
            }
        }
        //Ajouter au tableau de cartes
        if (nb_cartes == nb_cartesMax)
        {
            const Carte** newtab = new const Carte*[(nb_cartesMax + 1) * 2];
            for (size_t i = 0; i < nb_cartes; i++) newtab[i] = cartes[i];
            auto old = cartes;       cartes = newtab;   delete[] old;
            nb_cartesMax = (nb_cartesMax + 1) * 2;
        }
        cartes[nb_cartes++] = &c;
    }
    else
        merveillesNonConstruites[nb_merveilles_non_construites++] = dynamic_cast<const Merveille*>(&c);
}

// Partie s'occupe des boucliers
// Partie s'occupe de savoir s'il y a victoire scientifique (nbSymboles a appeler après cette fonction)
// Partie s'occupe de savoir s'il y a pioche de jeton (doubleSymboles a appeler avant cette fonction)
// Partie s'occupe de retirer un solde a l'adversaire (c.getSoldeRetireAdversaire())
// Partie s'occupe de savoir s'il faut piocher un jeton (c.getTirage())
// Partie s'occupe de savoir si le joueur rejoue (c.getRejouer())
// Partie s'occupe de savoir si le joueur pioche dans la défausse (c.getPiocheDefausse())
// Partie s'occupe de savoir si le joueur défausse une carte de son adversaire (c.getDefausseAdversaire())
// Partie s'occupe également d'ajouter en fin de partie (méthode victoire civile) les choses à condition CiteMax (getPointsParCarte())
void Joueur::construireCarte(const Carte& c, const Joueur& other){
    //Si cette methode est appelee, les conditions pour que le joueur construise ce batiment sont reunies,
    // verification faite par la méthode action() avec prix_final
    //Actions générales, communes à toutes les cartes
    //Faire toutes les actions spécifiques aux différentes spécificités des cartes:
    
    
    solde -= prixFinal(c, other);
    
    if(c.getRessource()!=aucuneRessource){
        ressources_prod[c.getRessource()]+=c.getNb();
    }
    if(c.engendreProduction()){
        for (int i = 0; i < NB_RESSOURCES; ++i) {
            if (c.getRessourcesAffectees()[i]) {
                ressources_non_prod[i] ++;
                }
            }
    }
    points+=c.getPoints();
    solde+=c.getSoldeApporte();
    if(c.getSymbole()!=aucunSymbole){
        symboles[c.getSymbole()]++;
    }
    if(c.getPieceParCarte()>0){
        solde += c.getPieceParCarte()*nombreCartesDeCategorie(c.getTypeCarteAffectee());
    }
    if(c.getPieceParCarteMax()>0){
        if(c.getDeuxiemeTypeCarteAffectee()==aucuneCarte){
            solde += c.getPieceParCarteMax()*(max(nombreCartesDeCategorie(c.getTypeCarteAffectee()),other.nombreCartesDeCategorie(c.getTypeCarteAffectee())));
        }else
            solde += c.getPieceParCarteMax()*(max(nombreCartesDeCategorie(c.getDeuxiemeTypeCarteAffectee())+nombreCartesDeCategorie(c.getTypeCarteAffectee()),other.nombreCartesDeCategorie(c.getDeuxiemeTypeCarteAffectee())+other.nombreCartesDeCategorie(c.getTypeCarteAffectee())));
    }
    
    ajouterCarte(c,true);
}

void Joueur::supprimerCarte(const Carte& c) {
    int i = 0;

    if (!possedeCarte(c)) {
        throw WondersException("Erreur : Tentative de supprimer une carte que le joueur ne possède pas.");
    }

    if (estConstruite(c)) {
        // Trouver l'index de la carte dans le tableau cartes
        while (cartes[i]->getNom() != c.getNom()) i++;
        
        // Suppression des attributs liés à la carte
        if (c.getRessource() != aucuneRessource) {
            ressources_prod[c.getRessource()] -= c.getNb();
        }
        if (c.engendreProduction()) {
            for (int j = 0; j < NB_RESSOURCES; ++j) {
                if (c.getRessourcesAffectees()[j]) {
                    ressources_non_prod[j]--;
                }
            }
        }
        points -= c.getPoints();
        if (c.getSymbole() != aucunSymbole) {
            symboles[c.getSymbole()]--;
        }
        
        // Suppression de la carte du tableau cartes ou merveilles du joueur
        if (c.getType() == merveille) nb_merveilles_construites--;
        // Déplacer les éléments du tableau cartes
        for (int j = i; j < nb_cartes - 1; j++) {
            cartes[j] = cartes[j + 1];
        }
        cartes[--nb_cartes] = nullptr;
    } else {
        // Trouver l'index de la carte dans le tableau merveillesNonConstruites
        while (merveillesNonConstruites[i]->getNom() != c.getNom()) i++;
        
        // Déplacer les éléments du tableau merveillesNonConstruites
        for (int j = i; j < nb_merveilles_non_construites - 1; j++) {
            merveillesNonConstruites[j] = merveillesNonConstruites[j + 1];
        }
        merveillesNonConstruites[--nb_merveilles_non_construites] = nullptr;
    }
}


// Renvoie vrai si le joueur possede la carte, construite ou non
bool Joueur::possedeCarte(const Carte& c) const{
    for (int i=0;i<nb_cartes;i++)
        if (cartes[i]->getNom()==c.getNom()) return true;
    for (int i=0;i<nb_merveilles_non_construites;i++)
        if (merveillesNonConstruites[i]->getNom()==c.getNom()) return true;
    return false;
}

// Utile pour les merveilles
bool Joueur::estConstruite(const Carte& c) const {
    if (!possedeCarte(c)) return false;
    for (int i=0;i<nb_merveilles_non_construites;i++){
        if (merveillesNonConstruites[i]->getNom()==c.getNom()) return false;
    }
    return true;
}

bool Joueur::possedeChainage(Chainage ch) const {
    if(ch==aucun) return false;
    for (int i=0;i<nb_cartes;i++){
        if(cartes[i]->getChainage1()==ch || cartes[i]->getChainage2()==ch){
            return true;
        }
    }
    return false;
}

void Joueur::afficherCartesDeCategorie(TypeCarte typeRecherche, ostream& f) const {
    if (typeRecherche==merveille){
        if(nb_merveilles_construites>0){
            f << " MERVEILLES CONSTRUITES : " << endl;
            for (int i = 0; i < nb_cartes ; ++i) {
                if (cartes[i]->getType()==merveille)
                    cartes[i]->afficher(f);
            }
        }
        if(nb_merveilles_non_construites>0){
            f << " MERVEILLES NON CONSTRUITES : " << endl;
            for (int i = 0; i< nb_merveilles_non_construites; i++){
                merveillesNonConstruites[i]->afficher(f);
            }
        }
    }else{
        for (int i = 0; i < nb_cartes; ++i) {
            if (cartes[i]->getType() == typeRecherche) {
                cartes[i]->afficher(f);
            }
        }
    }
}

void Joueur::afficherCartes(ostream& f) const{
    for (int i=0;i<NB_TYPES_CARTES;i++){
        if(nombreCartesDeCategorie(static_cast<TypeCarte>(i))){
            cout << "Cartes " << static_cast<TypeCarte>(i) << ": "<< endl;
            afficherCartesDeCategorie(static_cast<TypeCarte>(i),f);
            cout << endl;
        }
    }
}

unsigned int Joueur::nombreCartesDeCategorie(TypeCarte typeRecherche) const {
    unsigned int nombre = 0;
    if(typeRecherche==merveille){
        nombre = nb_merveilles_construites + nb_merveilles_non_construites;
    }else{
        for (int i = 0; i < nb_cartes; ++i) {
            if (cartes[i]->getType() == typeRecherche) {
                nombre++;
            }
        }
    }
    return nombre;
}

int Joueur::prixFinal(const Carte& c, const Joueur& other) const{
    int prix = c.getCoutPiece();
    
    int choixGris = 0; //Nombre de produits manufacurés choisis en ressource non produite directement
    int choixMarron = 0; //Nombre de matières premières choisies en ressource non produite directement
    bool choix = false;
    
    // Condition de construction gratuite
    if(possedeChainage(c.getChainage1())||possedeChainage(c.getChainage2())) return 0;
    
    for (int i=0;i<NB_RESSOURCES;i++){
        // On vérifie si le joueur ne produit pas déjà les ressources nécessaires
        if(c.getCoutRessources()[i]>ressources_prod[i]){
            // Choix des ressources non produites directement
            choix = false;
            if(ressources_non_prod[i]>0){
                if(i<3 && ressources_non_prod[i]>choixMarron){ // Matière première (marron)
                    choixMarron++;
                    choix = true;
                }
                else if(i<5 && ressources_non_prod[i]>choixGris){ // Produit manufacure (gris)
                    choixGris++;
                    choix = true;
                }
            }if(!choix){
                if(prixFixe(static_cast<Ressource>(i))){
                    prix +=1;
                }else{
                    prix += (c.getCoutRessources()[i]-ressources_prod[i])*(2+other.getRessourcesProduites()[i]);
                }
            }
        }
    }
    
    return prix;
}

void Joueur::afficher(std::ostream& f) const{
    f << "***********************************************\n";
    f << "***********************************************\n";
    f << "       Joueur " << id << endl;
    f << "-----------------------------------------------\n";
    f << " Cartes de la cité : \n\n";
    afficherCartes(f);
    f << "-----------------------------------------------\n";
    f << " Solde: " << solde << "  |  Points: " << points << endl;
    f << " Symboles scientifiques: " << endl;
    for (int i= 0; i<NB_SYMB ; i++)
        if (symboles[i]>0) f << "   " << static_cast<SymboleScientifique>(i) << " : " << symboles[i] << endl;
    f << "-----------------------------------------------\n";
    f << " Jetons Progrès de la cité : \n";
    for (int i=0; i<nb_jetons;i++)
        cout << " - " << jetons[i]->getNom() << endl;
    f << "***********************************************\n";
    f << "***********************************************\n";
}

/*
int Joueur::choixEntier(int* tab) const{
    switch (type){
        case humain:
            throw WondersException("Tentative de choix IA avec un joueur humain");
            break;
        case IA_aleatoire:
            break;
    }
    
    
}
 */

bool Joueur::peutConstruire(const Carte& c) const {
    for (int i = 0; i < NB_RESSOURCES; i++) {
        if (ressources_prod[i] + ressources_non_prod[i] >= c.getCoutRessources()[i]) {
            return true;
        }
    }
    if (solde >= c.getCoutPiece()) {
        return true;
    }
    return false;
}