#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#include "Jeu.hh"

using namespace std;

int Jeu::numero = 1;

Jeu :: Jeu(){}

Jeu :: ~Jeu(){}

void Jeu :: jouer() // fonction pour jouer au jeu
{
    intro();
    joueur();
    partie();
}

void Jeu :: intro() // On affiche l'intro, les règles du jeu
{
    cout << "  ~~~~~~~~~~ ! BIENVENUE DANS LE SINGE GAME ! ~~~~~~~~~~" << endl << endl;
    cout << "Les règles sont les suivantes :" << endl;
    cout << "- On vous attribue une somme de départ de manière aléatoire" << endl;
    cout << "- Vous pouvez parier sur un singe et augmenter votre somme à chaque tour" << endl;
    cout << "- Plus vous misez, plus vous gagnez (c'est logique)" << endl;
    cout << "- Le but : Avoir le plus d'argent à la fin de la partie" << endl;
    cout << "           Ou bien que vos adversaires n'aient plus d'argent" << endl << endl;
    cout << "Vous êtes prêts ? .......... Ç'est parti !!!!" << endl << endl;
}


void Jeu :: joueur() // Fonction pour créer les joueurs de la partie avec leur nom
{
    string nomJoueur;
    string mot;
    cout << "Tout d'abord veuillez choisir le nombre de participants : ";    
    cin >> nbJoueur;
    for(size_t i = 0; i < nbJoueur; i++)
    {
        nomJoueur = "Joueur_" + to_string(numero);
        tab.push_back(Joueur(nomJoueur));
        cout << "Vous vous appellez " << tab[i].getName() << endl << "Voulez-vous changer de nom ? (oui/non) : ";
        cin >> mot;
        changeName(i,mot);
        cout << "Vous commencez avec : " << tab[i].getSomme() << endl << endl;
        numero ++;
    }
    if(tab.size() == 1) // IA dans le cas où on joue tous seul
    {
        ordinateur = new Joueur("IA");
    }
}

void Jeu :: changeName(const size_t i, string mot) // Fonction pour changer le nom d'un joueur s'il le souhaite
{
    if(mot == "oui") // on change le nom
    {
        cout << "Veuillez choisir votre nom de joueur : ";
        cin >> mot;
        tab[i].setName(mot);
        cout << endl << "Vous vous appelez : " << tab[i].getName() << endl << endl;
    }
    else if(mot == "non"){} // Dans ce cas on ne fait rien
    else // Erreur de frappe
    {
        cout << "Voulez-vous changer de nom ? (oui/non) : ";
        cin >> mot;
        changeName(i,mot);
    }

}


void Jeu :: partie() // fonction partie
{
    int fin = 0;
    while(true)
    {
        fin = finPartie(); // on vértifie si la partie n'est pas finie
        if(fin == 1)
        {
            break;
        }
        debutTour(fin);
    }
}


int Jeu :: finPartie() // fonction pour arrêter la partie dans le cas où il n'y plus de joueur
{
    if(tab.size() == 0)
    {
        cout << "La partie est finie" << endl;
        return 1;
    }
    else if(tab.size() == 1 && ordinateur -> getSomme() <= 0)
    {
        cout << "L'IA a perdu" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}


void Jeu :: suppJoueur(const size_t i) // fonction pour supprimer un joueur dans le vecteur
{
    bool etat = tab[i].etatJoueur();
    if(etat == false)
    {
        tab.erase(tab.begin() + i);
    }
}

void Jeu :: debutTour(int fin) // fonction pour le début du tour 
{
    string mot;
    for(size_t i = 0; i < tab.size(); i++)
    {
        suppJoueur(i); // On supprime un joueur si sa somme vaut 0
        fin = finPartie(); // On vérifie qu'il reste des joueurs dans la partie
        if(fin == 1)
        {
            break;
        }
        cout << "C'est au tour du joueur : " << tab[i].getName() << endl;
        cout << "Voulez-vous parier ? (oui/non) : ";
        cin >> mot;
        tour(mot, i);
    }
    if(tab.size() == 1)
    {
        ordinateurSinge(); // IA joue pour ce tour
    }
    singe();
}


void Jeu :: tour(string mot, const size_t i)
{
    size_t valeur;
    if(mot == "non") // On ne veut pas miser
    {
        decision(mot, i, valeur);
    }
    else if(mot == "oui") // On veut miser
    {
        cout << "Sur quel singe voulez-vous parier ? (Macaque/Gorille/Gibon/Chimpanze/Bonobo) : ";
        cin >> mot;
        cout << endl;
        tab[i].parier(mot);
        cout << "Combien voulez-vous miser ? : ";
        cin >> valeur;
        tab[i].setMise(valeur);
        tab[i].miser(tab[i].getMise());
    }
    else
    {
        cout << endl << "Voulez-vous parier ? (oui/non) : "; // Erreur entrée de l'utilisateur
        cin >> mot;
        tour(mot, i);
    }
}

void Jeu :: decision(string mot, size_t i, size_t valeur)
{
    while(1) // Si on ne veut pas parier pour l'instant
    {
        cout << "Que voulez-vous faire ? (Quitter / Stats / Parier / IA) : ";
        cin >> mot;
        if(mot == "Quitter") // Le joueur quitte la partie
        {
            cout << "Le joueur " << tab[i].getName() << " a quitté la partie" << endl;
            tab.erase(tab.begin() + i);
            break;
        }
        if(mot == "Stats") // On affiche les stats du joueur
        {
            cout << "Vos stats sont les suivantes : " << endl;
            cout << tab[i] << endl;
        }
        if(mot == "Parier") // On décide finalement de parier
        {
            cout << "Sur quel singe voulez-vous parier ? (Macaque/Gorille/Gibon/Chimpanze/Bonobo) : "; cin >> mot; cout << endl;
            tab[i].parier(mot);
            cout << "Combien voulez-vous miser ? : "; cin >> valeur;
            tab[i].setMise(valeur);
            tab[i].miser(tab[i].getMise());
            break;
        }
        if(mot == "IA") // on veut voir les stats de l'IA
        {
            cout << "Les stats de l'IA sont : " << endl;
            cout << *ordinateur << endl;
        }
    }
}
int Jeu :: joueurVsIA()
{
    srand((unsigned int)time(0));
    int luckJoueur;
    int luckSinge;
    while(checkSinge() ==  -2) // tant qu'un singe n'est pas mort
    {
        luckJoueur  = rand() % 2;
        luckSinge = rand() % 3 + 1 ;
        switch(luckJoueur)
        {
            case 0:
                tab[0].getChoix().combat(ordinateur -> getChoix(),luckSinge); // on attaque le singe ennemi
                tab[0].getChoix().soin(luckSinge); // permet de se soigner
                tab[0].getChoix().resetPA(); // on remet les points d'action au max
                break;
            case 1: 
                ordinateur -> getChoix().combat(tab[0].getChoix(),luckSinge);
                ordinateur -> getChoix().soin(luckSinge);
                ordinateur -> getChoix().resetPA();
                break;
        }
    }
    return checkSinge();
}

int Jeu :: joueurVsJoueur() // fonction identique à celle de joueurVsIA mais modifiée pour les joueurs
{
    srand((unsigned int)time(0));
    int luckAttaquant;
    int luckCible;
    int luckSinge;
    while(checkSinge() == -2)
    {
        luckAttaquant = rand() % tab.size();
        luckCible = rand() % tab.size();
        luckSinge = rand() % 3 + 1;
        tab[luckAttaquant].getChoix().combat(tab[luckCible].getChoix(), luckSinge); // on attaque le singe d'un joueur
        tab[luckAttaquant].getChoix().soin(luckSinge); // permet de se soigner
        tab[luckAttaquant].getChoix().resetPA(); // on remet les points d'action au max
    }
    return checkSinge();
}


void Jeu :: singe()
{   
    int mort;
    if(tab.size() == 1) // Dans le cas où on a 1 jour + IA
    {
        mort = joueurVsIA();
        switch(mort)
        {
            case -1: // si le joueur a gagné le pari
                ordinateur -> perdre();
                tab[0].gagner();
                break;
            case 0 :  // si l'IA a gagné le pari
                ordinateur -> gagner();
                tab[0].perdre();
                break;
        }
    }
    else // Dans le cas où on a au moins 2 joueurs dont 1 qui n'est pas l'IA
    {
        mort = joueurVsJoueur();
        tab[mort].perdre();
        for(size_t i = 0; i < tab.size(); i++)
        {
            if(i != (size_t) mort)
            {
                tab[i].gagner();
            }
        }
    }
}

string Jeu :: IA() // fonction qui permet de choisir aléatoirement un singe/aucun à l'IA
{
    srand((unsigned int)time(0));
    int val = rand() % 6;
    string word;
    switch(val)
    {
        case 1:
            word = "Macaque";
            break;
        case 2:
            word = "Bonobo";
            break;
        case 3:
            word = "Chimpanze";
            break;
        case 4:
            word = "Gibon";
            break;
        case 5:
            word = "Gorille";
            break;
        case 6:
            word = "aucun";
            break;
    }
    return word;
}

int Jeu :: checkSinge() // fonction qui permet de voir si un singe est mort
{
    if(tab.size() == 1 && ordinateur -> getChoix().vie() == false)
    {
        return -1; // on retourne -1 dans le cas où c'est le singe de l'IA qui est mort
    }
    for(size_t i = 0; i < tab.size(); i++)
    {
        if(tab[i].getChoix().vie() == false)
        {
            return i; // on retourne l'indice du singe du joueur pour savoir qui a perdu
        }
    }
    return -2; // pas de singe mort
}

void Jeu :: ordinateurSinge()
{
    int valeur;
    int valeur2;
    srand((unsigned int)time(0));
    string word;
    word = IA();
    ordinateur -> parier(word); // L'IA choisit un singe aléatoirement

    valeur2 = ordinateur -> getSomme();
    valeur = rand() % valeur2;
    if(valeur == 0)
    {
        valeur += 1;
    }
    ordinateur -> setMise(valeur);
    ordinateur -> miser(ordinateur -> getMise()); // L'IA mise aléatoirement
}


Joueur& Jeu :: getOrdinateur() const
{
    return *ordinateur;
}