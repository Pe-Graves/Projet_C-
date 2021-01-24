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
    //cout<< "PLAYER 1 : " << tab[0].getChoix().getPDV() << endl;
    //cout<< "IA : " << ordinateur -> getChoix().getPDV() << endl;
    //cout << "TUNE IA : " << ordinateur -> getSomme() << endl;
    ordinateurSinge(); // IA joue pour ce tour
    //cout << "TUNE IA : " << ordinateur -> getSomme() << endl;
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
        cout << "Sur quel singe voulez-vous parier ? (ou aucun) : ";
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
        cout << "Que voulez-vous faire ? (Quitter / Stats / Passer / Parier) : ";
        cin >> mot;
        if(mot == "Quitter") // Le joueur quitte la partie
        {
            cout << "Le joueur " << tab[i].getName() << " a quitté la partie" << endl;
            tab.erase(tab.begin() + i);
            break;
        }
        if(mot == "Stats") // ON affiche les stats du joueur
        {
            cout << "Vos stats sont les suivantes : " << endl;
            cout << tab[i] << endl;
        }
        if(mot == "Passer") // ON passe son tour pour cette mise
        {
            tab[i].pasParier(mot);
            break;
        }
        if(mot == "Parier") // ON décide finalement de parier
        {
            cout << "Sur quel singe voulez-vous parier ? (ou aucun) : "; cin >> mot; cout << endl;
            tab[i].parier(mot);
            cout << "Combien voulez-vous miser ? : "; cin >> valeur;
            tab[i].setMise(valeur);
            tab[i].miser(tab[i].getMise());
            break;
        }
    }
}


void Jeu :: singe()
{   
    int flag = 0;
    int luck;
    int singe;
    if(tab.size() == 1)
    {
        while(flag == 0)
        {
            flag = checkSinge();
            cout << "LE FLAG VAUT : " << flag << endl;
            cout << "ORDI PDV : " << ordinateur -> getChoix().getPDV() << endl;
            cout << "PLAYER  : " << tab[0].getChoix().getPDV() << endl;
            singe = unSurDeux();
            cout << "SINGE : " << singe << endl;
            luck  = chance();
            cout << "LUCK : " << luck << endl;
            if(singe)
            {
                if(luck == 0)
                {
                    tab[0].getChoix().combat(ordinateur -> getChoix());
                }
                else
                {
                    cout << "Echec critique" << endl;
                }
            }
            else
            {
                if(luck == 0)
                {
                    ordinateur -> getChoix().combat(tab[0].getChoix());
                }
                else 
                {
                    cout << "Echec critique" << endl;
                }
            }
        }
    }
}

/*
void Jeu :: singe1()
{
    int mort = 0;
    if(tab.size() == 1) // Si l'on a un seul joueur dans la partie on crée un joueur_ordi
    {
        string word;
        tab.push_back(Joueur("IA"));
        word = IA();
        tab[1].parier(word);        
    }
    while(1)
    {
        mort = checkSinge();
        if(mort == 1)
        {
            cout << "BLABLA" << endl;
            break;
        }
        mort = 1;
        //fight();
    }
}
*/

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
    if(ordinateur -> getChoix().vie() == false)
    {
        return 1;
    }
    for(size_t i = 0; i < tab.size(); i++)
    {
        if(tab[i].getChoix().vie() == false)
        {
            return 1;
        }
    }
    return 0;
}

/*
void Jeu :: fight() // fonction de combat entre les singes
{
   if(tab.size() == 2)
   {
    fight2();
   }
   else
   {
    //fight3();
   }
    //cout << "La taille de tab vaut : ";
    //cout << tab.size() << endl;
    for(size_t i = 0; i < tab.size(); i++)
        {
            cout << "JE SUIS LA PD" << endl;
            etat = chance();
            for(size_t j = 0; i < tab.size(); j++)
            {
                cout << "JE SUIS LA ENCULE" << endl;
                if(i != j)
                {
                    switch(etat)
                    {
                        case 0:
                            tab[i].getChoix().combat(tab[j].getChoix());
                            break;
                        case 1:
                            cout << "Echec Critique" << endl;
                            break;
                    }
                }
            }
        }
}*/

int Jeu :: chance()
{
    srand((unsigned int)time(0));
    int val = rand() % 3;
    switch(val)
    {
        case 1:
            val = 0;
            break;
        case 2:
            val = 0;
            break;
        case 3:
            val = 1;
            break;
    }
    return val; 
}

int Jeu :: unSurDeux()
{
    srand((unsigned int)time(0));
    int val = rand() % 2;
    return val;  
}

/*
void Jeu :: fight2()
{
    int etat = chance();
    int joueur_attaque = unSurDeux();
    switch(joueur_attaque)
    {
        case 1:
            if(!etat)
            {
                cout << "SINGE IA" << tab[1].getChoix().getPDV() << endl; 
                tab[0].getChoix().combat(tab[1].getChoix());
                cout << "SINGE IA" << tab[1].getChoix().getPDV() << endl;
                break; 
            }
            else
            {
                cout << "Echec Critique" << endl;
                break;
            }
            //break;
        case 2:
            if(!etat)
            {
                cout << "SINGE JOUEUR" << tab[0].getChoix().getPDV() << endl;
                tab[1].getChoix().combat(tab[0].getChoix());
                cout << "SINGE JOUEUR" << tab[0].getChoix().getPDV() << endl;
                break;
            }
            else
            {
                cout << "Echec Critique" << endl;
                break;
            }
            //break;
    }
}
*/
/*
void Jeu :: fight3()
{}
*/

void Jeu :: ordinateurSinge()
{
    srand((unsigned int)time(0));
    string word;
    word = IA();
    ordinateur -> parier(word);
    int valeur2 = ordinateur -> getSomme();
    int valeur = rand() % valeur2;
    ordinateur -> setMise(valeur);
    cout << "MISE IA : " << valeur << endl;
    ordinateur -> miser(ordinateur -> getMise());
}