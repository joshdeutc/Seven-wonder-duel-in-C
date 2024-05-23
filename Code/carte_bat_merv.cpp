#include "carte_bat_merv.h"

/****************** **************** ****************
 FONCTIONS D'AFFICHAGE DES ENUMERATIONS
 ****************** **************** ****************/

ostream& operator<<(ostream& f, Ressource ressource) {
    switch (ressource) {
        case aucuneRessource: f << "aucune"; break;
        case bois: f << "bois"; break;
        case argile: f << "argile"; break;
        case pierre: f << "pierre"; break;
        case verre: f << "verre"; break;
        case papyrus: f << "papyrus"; break;
        default: f << "unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& f, SymboleScientifique symbole) {
    switch (symbole) {
        case aucunSymbole: f << "aucun symbole"; break;
        case roue: f << "roue"; break;
        case plume: f << "plume"; break;
        case globe: f << "globe"; break;
        case bol: f << "bol"; break;
        case horloge: f << "horloge"; break;
        case A: f << "A"; break;
        case balance: f << "balance"; break;
        default: f << "unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& f, TypeCarte type) {
    switch (type) {
        case merveille: f << "merveille"; break;
        case matierePremiere: f << "matière première"; break;
        case produitManufacture: f << "produit manufacture"; break;
        case batimentCivil: f << "bâtiment civil"; break;
        case batimentScientifique: f << "bâtiment scientifique"; break;
        case batimentCommerce: f << "bâtiment de commerce"; break;
        case batimentMilitaire: f << "bâtiment militaire"; break;
        case guilde: f << "guilde"; break;
        case jetonProgres: f << "jeton de progrès"; break;
        default: f << "unknown"; break;
    }
    return f;
}

ostream& operator<<(ostream& os, Chainage chainage) {
    switch (chainage) {
        case aucun: os << "aucun"; break;
        case fer: os << "fer"; break;
        case epee: os << "épée"; break;
        case tour: os << "tour"; break;
        case cible: os << "cible"; break;
        case casque: os << "casque"; break;
        case livre: os << "livre"; break;
        case engrenage: os << "engrenage"; break;
        case harpe: os << "harpe"; break;
        case lampe: os << "lampe"; break;
        case masque: os << "masque"; break;
        case poutre: os << "poutre"; break;
        case lune: os << "lune"; break;
        case soleil: os << "soleil"; break;
        case goutte: os << "goutte"; break;
        case temple: os << "temple"; break;
        case vase: os << "vase"; break;
        case tonneau: os << "tonneau"; break;
        default: os << "unknown"; break;
    }
    return os;
}




void Carte::afficher(ostream& f) const{
    f << "________________________\n";
    f << "|   " << nom << endl;
    f << "| " << type_carte << endl;
    f << "|   __________________   \n";
    f << "| " << "      COUT : \n";
    if(cout_piece>0) f << "| " << "Pieces : " << cout_piece << endl;
    if(cout_bois>0) f << "| " << "Bois : " << cout_bois << endl;
    if(cout_argile>0) f << "| " << "Argile : " << cout_argile << endl;
    if(cout_pierre>0) f << "| " << "Pierre : " << cout_pierre << endl;
    if(cout_verre>0) f << "| " << "Verre : " << cout_verre << endl;
    if(cout_papyrus >0) f << "| " << "Papyrus: " << cout_papyrus << endl;
    f << "|  __________________   \n";
    if(estChainee()) f << "| Chainage : " << getChainage() << endl;
    if(getRessource()!=aucuneRessource) f << "| Produit  : " << getNb() << " "<< getRessource() << endl;
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
    if(getPiece()) f << "| Rapporte une piece par carte " << getTypeCarteAffectee() << " en fin de partie." << endl;
    if(getBoucliers()!=0) f << "| Boucliers : " << getBoucliers() << endl;
    if(getSoldeRetireAdversaire()!=0) f << "| L'adversaire perd " << getSoldeRetireAdversaire()
        << " pieces qui sont remises a la banque" << endl;
    if (getTirage()) f << "| Le joueur choisi un jeton parmi ceux laisses de cote " << endl;
    if (getRejouer()) f << "| Le joueur rejoue " << endl;
    if (getPiocheDefausse()) f<< "| Le joueur construit gratuitement une carte dans la defausse" << endl;
    if (getDefausseAdversaire()) f << "| Le joueur defausse une carte " << getCarteDefausseAdversaire()
        << " de son adversaire" << endl;
    f << "________________________\n";
}