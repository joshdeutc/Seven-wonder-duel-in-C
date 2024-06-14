#include "joueur.h"
//#define NB_SYMB 6
#define NB_TYPES_CARTES 8
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
    return nb>=1;
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
void Joueur::construireCarte(const Carte& c, const Joueur& other, const int& prix){
    //Si cette methode est appelee, les conditions pour que le joueur construise ce batiment sont reunies,
    // verification faite par la méthode action() avec prix_final
    //Actions générales, communes à toutes les cartes
    //Faire toutes les actions spécifiques aux différentes spécificités des cartes:
    
    if(prix>solde) throw WondersException("Erreur : tentative de construire une carte dont le prix est superieur au solde");
    
    // Condition de construction gratuite par chainage
    if(possedeChainage(c.getChainage1())||possedeChainage(c.getChainage2())){
        for(int i=0; i<nb_jetons; i++){
            if(jetons[i]->getCondChainage())
                solde+=4;
        }
    }
    
    solde-=prix;
    
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

int Joueur::prixFinal(const Carte& c, const Joueur& other, int ressources_gratuites_jeton[NB_RESSOURCES],
                      int ressources_gratuites_cartes[NB_RESSOURCES]) const{
    int prix = c.getCoutPiece();
    
    // Condition de construction gratuite
    if(possedeChainage(c.getChainage1())||possedeChainage(c.getChainage2())) return 0;
    
    // Copier le cout des ressources dans un autre tableau qu'on peut modifier et retirer les ressources gratuites
    int coutRes[NB_RESSOURCES];
    for (int i = 0; i<NB_RESSOURCES; i++){
        coutRes[i]=c.getCoutRessources()[i];
        coutRes[i] -= (ressources_gratuites_jeton[i] + ressources_gratuites_cartes[i]);
        if (coutRes[i]<0) coutRes[i] = 0;
    }
    
    
    
    for (int i=0;i<NB_RESSOURCES;i++){
        // On vérifie si le joueur ne produit pas déjà les ressources nécessaires
        if(coutRes[i]>ressources_prod[i]){
            if(prixFixe(static_cast<Ressource>(i))){
                prix +=1;
            }else{
                prix += (coutRes[i]-ressources_prod[i])*(2+other.getRessourcesProduites()[i]);
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


int Joueur::choixEntierIA(int* tab, int taille) const {
    if (taille <= 0) {
        throw WondersException("Erreur dans ChoixIA: La taille doit être positive.");
    }

    switch (type) {
        case humain:
            throw WondersException("Tentative de choix IA avec un joueur humain");
            break;
        case IA_aleatoire:
            // Générateur de nombres aléatoires
            std::random_device rd;  // Génère une graine aléatoire
            std::mt19937 gen(rd()); // Générateur Mersenne Twister
            std::uniform_int_distribution<> dis(0, taille - 1); // Distribution uniforme entre 0 et taille-1

            if (tab == nullptr) {
                // tab est nullptr, on retourne un entier aléatoire entre 0 et taille - 1
                return dis(gen);
            } else {
                // tab n'est pas nullptr, on retourne un élément aléatoire du tableau
                int random_index = dis(gen); // Génère un indice aléatoire
                return tab[random_index]; // Retourne l'élément du tableau à cet indice
            }
    }
    
    throw WondersException("Erreur ChoixIA: Type joueur inconnu");
}

// s'applique seulement aux merveilles
void Joueur::choixRessourcesGratuitesJeton(int tab[NB_RESSOURCES], TypeCarte typecarte){
    //initialisation à 0
    for(int i=0 ;i<NB_RESSOURCES;i++) tab[i]=0;
    int choix;
    for (int i=0;i<nb_jetons;i++){
        if (jetons[i]->getRessourcesGratuites() > 0 && jetons[i]->getTypeCarteCondition()==typecarte){
            if(type==humain){
                int n= jetons[i]->getRessourcesGratuites();
                cout << "Vous pouvez choisir " << n << " ressources gratuites. " << endl ;
                int count = 0;
                while(count<n){
                    // afficher les options
                    for (int k=0 ;k<NB_RESSOURCES;k++)
                        cout << k+1 << ": "<< static_cast<Ressource>(k) << "      "  << endl;
                    cout << "Choisir une ressource gratuite : " ;
                    cin >> choix ;
                    if(choix>NB_RESSOURCES || choix<1) cout << "Choix non valide " << endl ;
                    else {
                        tab[choix]++ ;
                        count++ ;
                    }
                }
            }else{
                tab[choixEntierIA(nullptr,NB_RESSOURCES)]++;
            }
        }
    }
}

void Joueur::choixRessourcesGratuitesCartes(int tab[NB_RESSOURCES]){
    int choix ;
    int count;
    int n ;
    //initialisation à 0
    for(int i=0 ;i<NB_RESSOURCES;i++) tab[i]=0;

    // Possibilite de choisir une matiere premiere ou un produit manufacture pour
    // chaque carte
    if (ressources_non_prod[0] > 0){
        n = ressources_non_prod[0];
        if(type==humain){
            count = 0;
            while(count<n){
                cout << "Choisissez une ressources produite par votre cite pour ce tour parmis les suivantes : ";
                cout << " 1. Bois   2. Argile    3. Pierre \n " ;
                cout << " Choix : " << endl;
                cin>> choix ;
                if(choix<1 || choix>3) cout << "Choix non valide. \n" ;
                else{
                    count++ ;
                    tab[choix-1]++ ;
                }
            }
        }else{
            for(int i=0;i<n;i++) tab[choixEntierIA(nullptr,3)]++;
        }
    }if (ressources_non_prod[3] > 0){
        n = ressources_non_prod[3];
        if(type==humain){
            count = 0;
            while(count<n){
                cout << "Choisissez une ressources produite par votre cite pour ce tour parmis les suivantes : \n";
                cout << " 1. Verre   2. Papyrus   \n " ;
                cin>> choix ;
                if(choix<1 || choix>2) cout << "Choix non valide. \n" ;
                else{
                    count++ ;
                    tab[choix+2]++ ;
                }
            }
        }else{
            for(int i=0;i<n;i++) tab[choixEntierIA(nullptr,2)+2]++;
        }
    }
}

const Carte* Joueur::recherche_carte(string &nom) const{
    const Carte *c = nullptr;
    int i=0;
    while(c==nullptr){
        cout<<"entrer le nom de la merveille que vous cherchez : "<<endl;
        while(i<nb_merveilles_non_construites && c==nullptr) {
            if(merveillesNonConstruites[i]->getNom()== nom ) c=merveillesNonConstruites[i];
            i++;
        }
        i = 0;
        while(i<nb_cartes && c ==nullptr){
            if(cartes[i]->getNom()==nom ) c = cartes[i];
            i++;
        }
    }
    cout<<"La carte "<<c->getNom()<<" a ete trouvee."<<endl;
    return c;
}

ostream& operator<<(ostream& f, TypeJoueur j) {
    switch (j) {
        case humain: f << "Joueur"; break;
        case IA_aleatoire: f << "IA aleatoire"; break;
    }
    return f;
}

void afficher_types_IA() {
    std::cout << "Liste des types d'IA :" << std::endl;
    for (int i = 1; i < NB_IA + 1 ; ++i) {
        cout << i << ". " << static_cast<TypeJoueur>(i) << endl;
    }
}