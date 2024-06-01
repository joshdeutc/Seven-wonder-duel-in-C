#include "joueur.h"
//#define NB_SYMB 6

//Dans cette partie on considère que le Joueur a un seul tableau de pointeurs Batiment**
//Des modifications devront être faites pour utiliser le polymorphisme pour un bon fonctionnement du code

Joueur::Joueur(TypeJoueur type_joueur, string identifiant){
    type = type_joueur;
    id = identifiant;
    cartes = new const Carte*[nb_cartesMax];
    //points, solde et ressources sont deja initialisees
    for(int i=0;i<nb_cartesMax;i++) cartes[i]=nullptr;
    for(int i=0;i<NB_JETONS;i++) jetons[i] = nullptr;
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
    solde+=jeton->getSoldeApporte();
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
    
    int gain=2;
    for(int i=0;i<nb_cartes;i++)
        if (cartes[i]->getType() == batimentCommerce)
            gain+=2;
    solde += gain;
}

void Joueur::ajouterCarte(const Carte& c){
    //Recopier la maniere de faire du td4 pour le jeu SET! avec old_tab, new_tab et delete
    //modifie donc l'attribut batiments
    if (nb_cartes == nb_cartesMax)
        {
        const Carte** newtab = new const Carte*[(nb_cartesMax + 1) * 2];
        for (size_t i = 0; i < nb_cartes; i++) newtab[i] = cartes[i];
        auto old = cartes;       cartes = newtab;   delete[] old;
        nb_cartesMax = (nb_cartesMax + 1) * 2;
        }
    cartes[nb_cartes++] = &c;
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
    
    ajouterCarte(c);
}

void Joueur::supprimerCarte(const Carte& c){
    int i=0;
    while(cartes[i]->getNom()!=c.getNom()) i++;
    while(i<nb_cartes-1) cartes[i]=cartes[i+1];
    nb_cartes--;
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
    for (int i = 0; i < nb_cartes; ++i) {
        if (cartes[i]->getType() == typeRecherche) {
            cartes[i]->afficher(f);
        }
    }
}

void Joueur::afficherCartes() const{
    for (int i=0;i<NB_TYPES_CARTES;i++){
        if(nombreCartesDeCategorie(static_cast<TypeCarte>(i))){
            cout << "Cartes " << static_cast<TypeCarte>(i) << ": "<< endl;
            afficherCartesDeCategorie(static_cast<TypeCarte>(i));
        }
    }
}

unsigned int Joueur::nombreCartesDeCategorie(TypeCarte typeRecherche) const {
    unsigned int nombre = 0;
    for (int i = 0; i < nb_cartes; ++i) {
        if (cartes[i]->getType() == typeRecherche) {
            nombre++;
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