#include "joueur.h"
#define NB_SYMB 6

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
void Joueur::ajouter_jeton(JetonProgres* jeton){
    points+=jeton->getPoints();
    solde+=jeton->getSoldeApporte();
    if(jeton->getSymbole()!=aucunSymbole) symboles[jeton->getSymbole()]=1;
    
    //ajout du jeton aux attributs du joueur
    jetons[nb_jetons++] = jeton;
}


// Cette fonction renvoie vrai si la ressource r est au prix fixe de 1 piece pour le joueur
bool Joueur::prix_fixe(Ressource r){
    for(int i=0;i<nb_cartes;i++)
        if(cartes[i]->getType()==batimentCommerce)
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

void Joueur::ajouter_carte(const Carte& c){
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


void Joueur::construire_batiment(const Batiment& bat){
    //Si cette methode est appelee, les conditions pour que le joueur construise ce batiment sont reunies,
    // verification faite par la méthode action() avec prix_final
    
    //Actions générales, communes à tous les bâtiments
    
    //Faire toutes les actions spécifiques aux différents types de cartes:
    
    if (c.getType()==batimentScientifique){
        symboles[c.getSymbole()]+=1;
        ajouter_batiment(c);
        //Il faudra tester dans la classe Partie :
        // if (nb_symboles()>6) victoire_scientifique();
    }else if (bat.getType() == batimentCommerce){
        //Actions sur les ressources
        cout << "pass";
    }else if (bat.type=="Civil"){
        points += bat.points;
    } else if (bat.type=="MatierePremiere" || bat.type=="MatiereManufacture"){
        ressources_prod[bat.ressource] +=1;
    } else if (bat.type == "Militaire"){
        instance_de_partie.change_solde_militaire(this,bat.bouclier);
        //Toujours la même question de comment trouver l'instance de la partie
        //qu'on est en train de jouer.
    } else if (type=="Guilde"){
        //action des cardes Guilde
        //compliqué
        cout << "a faire";
    }
}

