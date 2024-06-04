#include "carte_bat_merv.h"

/****************** **************** ****************
 FONCTIONS D'AFFICHAGE DES ENUMERATIONS
 ****************** **************** ****************/

ostream& operator<<(ostream& f, Ressource ressource) {
    switch (ressource) {
        case aucuneRessource: f << "Aucune"; break;
        case bois: f << "Bois"; break;
        case argile: f << "Argile"; break;
        case pierre: f << "Pierre"; break;
        case verre: f << "Verre"; break;
        case papyrus: f << "Papyrus"; break;
        default: f << "Unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& f, SymboleScientifique symbole) {
    switch (symbole) {
        case aucunSymbole: f << "aucun symbole"; break;
        case roue: f << "Roue"; break;
        case plume: f << "Plume"; break;
        case globe: f << "Globe"; break;
        case bol: f << "Bol"; break;
        case horloge: f << "Horloge"; break;
        case A: f << "A"; break;
        case balance: f << "Balance"; break;
        default: f << "unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& f, TypeCarte type) {
    switch (type) {
        case merveille: f << "Merveille"; break;
        case matierePremiere: f << "Matière Première"; break;
        case produitManufacture: f << "Produit Manufacture"; break;
        case batimentCivil: f << "Bâtiment Civil"; break;
        case batimentScientifique: f << "Bâtiment Scientifique"; break;
        case batimentCommerce: f << "Bâtiment Commercial"; break;
        case batimentMilitaire: f << "Bâtiment Militaire"; break;
        case guilde: f << "Guilde"; break;
        case jetonProgres: f << "Jeton de Progrès"; break;
        default: f << "unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& os, Chainage chainage) {
    switch (chainage) {
        case aucun: os << "aucun"; break;
        case fer: os << "Fer"; break;
        case epee: os << "Épée"; break;
        case tour: os << "Tour"; break;
        case cible: os << "Cible"; break;
        case casque: os << "Casque"; break;
        case livre: os << "Livre"; break;
        case engrenage: os << "Engrenage"; break;
        case harpe: os << "Harpe"; break;
        case lampe: os << "Lampe"; break;
        case masque: os << "Masque"; break;
        case poutre: os << "Poutre"; break;
        case lune: os << "Lune"; break;
        case soleil: os << "Soleil"; break;
        case goutte: os << "Goutte"; break;
        case temple: os << "Temple"; break;
        case vase: os << "Vase"; break;
        case tonneau: os << "Tonneau"; break;
        default: os << "unknown"; break;
    }
    return os;
}




void Carte::afficher(ostream& f) const{
    f << "________________________\n";
    f << "|      " << nom << endl;
    f << "| " << type_carte ;
    if(getAge()!=0)
        f << " (Age " << getAge() << ")";
    f << endl;
    f << "|   __________________   \n";
    f << "| " << "      COUT : \n";
    if(cout_piece>0) f << "| " << "Pieces : " << cout_piece << endl;
    for (int i = 0; i < NB_RESSOURCES; ++i) {
        if (cout_ressources[i]>0) {
            f << "| " << static_cast<Ressource>(i) << ": " << cout_ressources[i] << endl;
        }
    }
    f << "|   __________________   \n";
    if(estChainee()){
        f << "| Chainage : " << getChainage1() << endl;
        if(getChainage2()!=aucun) f << "| Chainage : " << getChainage2() << endl;
    }
    if(getRessource()!=aucuneRessource) f << "| Produit  : " << getNb() << " " << getRessource() << endl;
    if(engendreProduction()) f << "| Produit une unite de ";
    if(engendrePrixFixe()) f <<"| Fixe a 1 piece le prix de ";
    if(engendrePrixFixe()||engendreProduction()){ // Pour merveille et commerce
        for (int i = 0; i < NB_RESSOURCES; ++i) {
                    if (getRessourcesAffectees()[i]) {
                        f << static_cast<Ressource>(i) << " ";
                    }
                }
        f << endl;
    }
    if(getPoints()!=0) f << "| Points victoire : " << getPoints() << endl;
    if(getSoldeApporte()!=0) f << "| Rapporte " << getSoldeApporte() << " pieces\n";
    if(getSymbole()!=aucunSymbole) f << "| Symbole Scientifique : " << getSymbole() << endl;
    if(getBoucliers()!=0) f << "| Boucliers : " << getBoucliers() << endl;
    if(getSoldeRetireAdversaire()!=0) f << "| L'adversaire perd " << getSoldeRetireAdversaire()
        << " pieces \n| qui sont remises a la banque" << endl;
    if (getTirage()) f << "| Le joueur choisi un jeton parmi \n| ceux laisses de cote " << endl;
    if (getRejouer()) f << "| Le joueur rejoue " << endl;
    if (getPiocheDefausse()) f<< "| Le joueur construit gratuitement \n| une carte dans la defausse" << endl;
    if (getDefausseAdversaire()) f << "| Le joueur defausse une carte \n| " << getCarteDefausseAdversaire()
        << " de son adversaire" << endl;
    if(getPieceParCarte()!=0){
        f << "| " << getPieceParCarte() << " piece(s) par carte \n|   " << getTypeCarteAffectee()
        << " du joueur (immediat)" << endl;
    }
    if(getPieceParCarteMax()!=0){
        f << "| " << getPieceParCarteMax() << " piece(s) par carte \n|   " << getTypeCarteAffectee();
        if (getDeuxiemeTypeCarteAffectee()!=aucuneCarte) f << " et " << getDeuxiemeTypeCarteAffectee();
        f << " du \n|   joueur qui en possède \n|   le plus (immédiat)" << endl;
    }
    if(getPointsParCarte()!=0){
        f << "| " << getPointsParCarte() << " point(s) par ";
        if(getTypeCarteAffectee()!=aucuneCarte){
            f << "carte \n|   " << getTypeCarteAffectee() ;
            if (getDeuxiemeTypeCarteAffectee()!=aucuneCarte) f << " et " << getDeuxiemeTypeCarteAffectee();
            f << "\n|   de la cité qui en possède le plus\n";
        }else f << " lot de 3 \n|   pieces de la cite la plus riche\n";
        f << "|   en fin de partie." << endl;
    }
    f << "|________________________\n";
}

void JetonProgres::afficher(ostream& f) const{
    f << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n";
    f << "   |              " << nom << endl;
    f << "   |            Jeton Progres" << endl;
    if (solde_immediat>0) f << "   | " << solde_immediat << " pieces (immediat)" << endl;
    if (points_immediats>0) f << "   | " << points_immediats << " points \n";
    if (solde_condition>0) f << "   | " << solde_condition << " pieces ";
    if (points_condition>0) f << "   | " << points_condition << " points ";
    if (ressources_gratuites>0) f << "   | " << ressources_gratuites << " ressources gratuites ";
    if (boucliers_supplementaires>0) f << "   | " << boucliers_supplementaires << " boucliers supp ";
    if (effet_rejouer) f << "   | Effet rejouer (si non deja present) ";
    if (condition_jeton) f << "pour chaque jeton progres en sa possession a la fin de la partie \n";
    if (carte_condition!=aucuneCarte) f << "pour les prochaines cartes " << carte_condition << " construites par le joueur \n";
    if (condition_chainage) f << "recues pour toutes les prochaines constructions gratuites par chainage \n";
    if (recup_argent_achats_adversaire) f << "   | Recupere argent depense par l'adversaires lorsqu'il achete des ressourves \n";
    if (symbole!=aucunSymbole) f << "   | Rapporte le symbole " << symbole << endl;
    f << "   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n \n";

}
