#include "joueur.h"

int Joueur::nb_symboles() const{
    int nb=0;
    for(int i=0; i<NB_SYMB; i++)
        if (symboles[i]>1) nb++;
    return nb;
}

// Voir avec la personne qui a fait les classes Batiment comment fonctionne l'héritage
// Par exemple; dans la fonction ci dessous est ce que je peux parler de l'attribut symbole sur batiment
// sachant que tous les batiments n'ont pas vraiment l'attribut symbole?
// Il faut ajouter un attribut string type pour pouvoir vérifier le type d'un batiment

// À REGARDER QUAND MÊME

bool Joueur::double_symbole(string s){
    for (int i=0;i<nb_bat;i++)
        if (batiments[i]->type == "Scientifique")
            if (batiments[i]->getSymbole() == s)
                return true;
    return false;
}

bool Joueur::tirage_jetons(bool en_jeu){
    if (en_jeu)
        //Menu d'interface graphique Qt, concernant uniquement les jetons en jeu
        cout << "pass";
    else
        //Menu d'interface graphique Qt, concernant les jetons hors jeu. Appelé seulement par
        cout << "pass";
    //appelle la méthode de la classe Jeton_progres correspondante au jeton choisi
}

void Joueur::action(){
    /*Menu d'interface graphique.
     Seuls les batiments accessibles sont disponibles pour le choix.
    Change le statut de la carte choisie et appelle la méthode accessibilite() de la classe Partie
    Appelle la methode prix final() de la classe Carte afin de seulement autoriser la construction du batiment et/ou de la merveille si le solde du joueur est assez eleve.
     Selon le choix, appelle la methode defausser; construire_batiment ou construire_merveille en leur
     donnant en argument la carte choisie par le joueur */
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

void Joueur::defausser(const Batiment& bat){
    //Methode disponible pour toutes les cartes; independamment de la cite du joueur.
    
    //Appelle la méthode supprimer(bat) de la classe Partie
    //Est ce qu'il y a besoin de l'instance de l'objet Partie pour ça
    
    bat.setStatut("defausse");
    
    int gain=2;
    for(int i=0;i<nb_bat;i++)
        if (bat[i]->getType() == "Commerce")
            gain+=2;
    solde += gain;
}

//Ce serait peut etre plus pratique de faire une enumeration Symbole pour les symboles scientifiques?
/*On cree un attribut de Joueur de type enum Symbole qui comptabilise les symboles de la meme maniere que
 les batiments comptabilisent les ressources, que l'on met a jour quand on construit un bat scientifique*/

void ajouter_batiment(const Batiment& bat){
    //Recopier la maniere de faire du td4 pour le jeu SET! avec old_tab, new_tab et delete
    //modifie donc l'attribut batiments
}

void construire_batiment(const Batiment& bat){
    //Si cette methode est appelee, les conditions pour que le joueur construise ce batiment sont reunies,
    // verification faite par la méthode action()
    
    //Actions générales, communes à tous les bâtiments
    
    ajouter_batiment(bat);
    
    string type = bat.getType();
    //L'instruction switch permet de faire toutes les actions spécifiques aux différents types de cartes
    switch (type) {
        case "Scientifique":
            symboles[bat.getSymbole()]+=1;
            if (nb_symboles()>6) cout << "jsp";/*appeler victoire scientifique. Encore une fois, je ne sais pas comment faire sans l'instance de Partie.*/
            break;
        case "Commerce":
            //Actions sur les ressources
            cout << "pass";
            break;
        case "Civil":
            points += bat.getPoints();
            break;
        case "Ressource"
    }
    else if bat.getType()
}
