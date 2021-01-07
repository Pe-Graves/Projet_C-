#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "Jeu.hh"

using namespace std;

int Jeu::numero = 1;

Jeu :: Jeu(){}

Jeu :: ~Jeu(){}

void Jeu :: jouer()
{
    intro();
    joueur();
    partie();
}

void Jeu :: intro()
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


void Jeu :: joueur()
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
}

void Jeu :: changeName(const size_t i, string mot)
{
    if(mot == "oui")
    {
        cout << "Veuillez choisir votre nom de joueur : ";
        cin >> mot;
        tab[i].setName(mot);
        cout << endl << "Vous vous appelez : " << tab[i].getName() << endl << endl;
    }
    else if(mot == "non"){}
    else
    {
        cout << "ERREUR" << endl  << "Voulez-vous changer de nom ? (oui/non) : ";
        cin >> mot;
        changeName(i,mot);
    }

}


void Jeu :: partie()
{
    int fin = 0;
    int flag = 0;
    while(true)
    {
        fin = finPartie();
        if(fin == 1)
        {
            break;
        }
        debutTour(fin, flag);
        //choixSinge();        
    }
}


int Jeu :: finPartie()
{
    if(tab.size() == 0)
    {
        cout << "La partie est finie" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}


void Jeu :: suppJoueur(const size_t i)
{
    bool etat = tab[i].etatJoueur();
    if(etat == false)
    {
        tab.erase(tab.begin() + i);
    }
}

void Jeu :: debutTour(int fin, int flag)
{
    string mot;
    for(size_t i = 0; i < tab.size(); i++)
    {
        suppJoueur(i);
        fin = finPartie();
        if(fin == 1)
        {
            break;
        }
        cout << "C'est au tour du joueur : " << tab[i].getName() << endl;
        cout << "Voulez-vous parier ? (oui/non) : ";
        cin >> mot;
        tour(mot, flag, i);
    }
}


void Jeu :: tour(string mot, int flag, const size_t i)
{
    size_t valeur;
    if(mot == "non")
    {
        decision(mot,i,flag,valeur);
    }
    else if(mot == "oui")
    {
        cout << "Sur quel singe voulez-vous parier ? (ou aucun) : ";
        cin >> mot;
        cout << endl;
        tab[i].parier(mot);
        //listeSinge(i,mot);
        cout << "Combien voulez-vous miser ? : ";
        cin >> valeur;
        tab[i].setMise(valeur);
        tab[i].miser(tab[i].getMise());
    }
    else
    {
        cout << "ERREUR" << endl << "Voulez-vous parier ? (oui/non) : ";
        cin >> mot;
        tour(mot, flag, i);
    }
}
/*
void Jeu :: checkPari(string mot)
{
    if(mot != "oui" && mot != "non")
    {
        cout << "Vous vous êtes trompé de commande" << endl;
        cout << "Vous pouvez encore choisir !" << endl;
        mot = "non";
    }
}
*/
void Jeu :: decision(string mot, size_t i, int flag, size_t valeur)
{
    while(flag == 0)
    {
        cout << "Que voulez-vous faire ? (Quitter / Stats / Passer / Parier) : ";
        cin >> mot;
        if(mot == "Quitter")
        {
            cout << "Le joueur " << tab[i].getName() << " a quitté la partie" << endl;
            tab.erase(tab.begin() + i);
            break;
        }
        if(mot == "Stats")
        {
            cout << "Vos stats sont les suivantes : " << endl;
            cout << tab[i] << endl;
            flag = 0;
        }
        if(mot == "Passer")
        {
            cout << "Vous avez décidé de passer votre tour" << endl;
            tab[i].pasParier(mot);
            break;
        }
        if(mot == "Parier")
        {
            cout << "Sur quel singe voulez-vous parier ? (ou aucun) : ";
            cin >> mot;
            cout << endl;
            tab[i].parier(mot);
            //listeSinge(i,mot);
            cout << "Combien voulez-vous miser ? : ";
            cin >> valeur;
            tab[i].setMise(valeur);
            tab[i].miser(tab[i].getMise());
            break;
        }
    }
}

/*
void Jeu :: listeSinge(size_t i, string mot)
{
        if(mot == "Macaque")
        {
            singe.push_back(Macaque(mot));
        }
        else if(mot == "Gibon")
        {
            singe.push_back(Gibon(mot));
        }
        else if(mot == "Gorille")
        {
            singe.push_back(Gorille(mot));
        }
        else if(mot == "Bonobo")
        {
            singe.push_back(Bonobo(mot));
        }
        else if(mot == "Chimpanze")
        {
            singe.push_back(Chimpanze(mot));
        }   
}
*/

