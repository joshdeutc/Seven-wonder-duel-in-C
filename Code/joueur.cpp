#include "joueur.hpp"
#define NB_SYMB 6

//Dans cette partie on considère que le Joueur a un seul tableau de pointeurs Batiment**
//Des modifications devront être faites pour utiliser le polymorphisme pour un bon fonctionnement du code

Joueur::Joueur(TypeJoueur type_joueur, string identifiant){
    type = type_joueur;
    id = identifiant;
    //points, solde et ressources sont deja initialisees
    for(int i=0;i<nb_batMax;i++) batiments[i]=nullptr;
    for(int i=0;i<7;i++) merveilles[i]=nullptr;
    for(int i=0;i<NB_JETONS;i++) jetons[i] = nullptr;
}

Joueur::~Joueur(

int Joueur::nb_symboles() const{
    int nb=0;
    for(int i=0; i<(NB_SYMB) ; i++){
        if (symboles[i]>1) nb++;
    }
    return nb;
}

bool Joueur::double_symbole(string s){
    int nb = 0;
    for (int i=0;i<nb_bat;i++)
        if (batiments[i]->type == "Scientifique")
            if (batiments[i]->getSymbole() == s)
                nb++;
    return nb>1;
}

//Cette méthode se charge d'effectuer les effets immédiats d'un jeton progrès.
//Les autres effets seront gérés par d'autres classes au moment pertinent
void Joueur::ajouter_jeton(JetonProgres* jeton){
    if (jeton->nom=="Mathematiques")
        points+=3;
    else if (jeton->nom=="Philosophie")
        points +=7;
    else if (jeton->nom=="Agriculture"){
        points += 4;
        solde+=6;
    }
    else if (jeton->nom=="Loi")
        symboles[balance] = 1;
    else if (jeton->nom=="Urbanisme")
        solde+=6;
    
    //ajout du jeton
    jetons[nb_jetons++] = jeton;
}


bool Joueur::prix_fixe(Ressource r){
    for(int i=0;i<nb_bat;i++)
        if(batiments[i]->getType()=="Commerce")
            if(batiments[i]->getAffecte()==r) // Il faut un accesseur en lecture dans classe commerce
                                              // Vérifier qu'on peut faire ça avec un type enum
                return true;
    return false;
}

//Il faudrait ajouter une methode supprimer(carte) a la classe Partie pour l'enlever du tableau disposition
/*Il faudrait peut etre aussi creer une classe defausse? Qui aurait un attributs pointeur sur les cartes presentes en defausse? Ce sera surement plus simple pour l'affichage que de faire le tour de toutes les cartes pour vérifier si elles sont en defausse ou non?? */
//Ajouter un accesseur en ecriture setStatut à la classe Batiment

//Vaut il mieux rendre la classe Joueur amie de la classe Batiment, ou ajouter plein d'accesseurs à la classe
//batiment pour que les méthodes de Joueur puissent en modifier les attributs?

void Joueur::defausser(Batiment* bat){
    //Methode disponible pour toutes les cartes; independamment de la cite du joueur.
    
    bat->st = defausse;
    
    int gain=2;
    for(int i=0;i<nb_bat;i++)
        if (bat[i]->getType() == "Commerce")
            gain+=2;
    solde += gain;
}


void Joueur::ajouter_batiment(const Batiment* bat){
    //Recopier la maniere de faire du td4 pour le jeu SET! avec old_tab, new_tab et delete
    //modifie donc l'attribut batiments
    if (bat == nullptr) return;
    if (nb_bat == nb_batMax)
        {
        const Batiment** newtab = new const Batiment*[(nb_batMax + 1) * 2];
        for (size_t i = 0; i < nb_bat; i++) newtab[i] = batiments[i];
        auto old = batiments;       batiments = newtab;   delete[] old;
        nb_batMax = (nb_batMax + 1) * 2;
        }
    batiments[nb_bat++] = bat;
}


void Joueur::construire_batiment(const Batiment& bat){
    //Si cette methode est appelee, les conditions pour que le joueur construise ce batiment sont reunies,
    // verification faite par la méthode action() avec prix_final
    
    //Actions générales, communes à tous les bâtiments
    
    ajouter_batiment(bat);
    
    //Faire toutes les actions spécifiques aux différents types de cartes:
    
    if (bat.type=="Scientifique"){
        symboles[bat.getSymbole()]+=1;
        //Il faudra tester dans la classe Partie :
        // if (nb_symboles()>6) victoire_scientifique();
    }else if (bat.type == "Commerce"){
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

