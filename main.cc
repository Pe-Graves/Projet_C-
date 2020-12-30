#include <iostream>
#include <string>
#include <vector>

#include "Joueur.hh"
#include "Singe.hh"

using namespace std;

int main()
{
/*	
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Singe" << endl;
	cout << endl;
	Singe a;
	Singe b;
	cout << b << endl;
	a.combat(b);
	cout << b << endl;
	b.soin(b);
	cout << b << endl;
	cout << "Fin Test pour la classe Singe" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Gorille" << endl;
	cout << endl;
	Gorille c;
	Gorille d;
	cout << d << endl;
	c.combat(d);
	cout << c << endl;
	d.soin(d);
	cout << d << endl;
	cout << "Fin Test pour la classe Gorille" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test pour la classe Macaque" << endl;
	cout << endl;
	Macaque e;
	Macaque f;
	cout << f << endl;
	e.combat(f);
	cout << f << endl;
	f.soin(f);
	cout << f << endl;
	cout << "Fin Test pour la classe Macaque" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test Macaque attaque Gorille" << endl;
	cout << endl;
	Gorille g;
	Macaque h;
	cout << g << endl;
	cout << h << endl;
	h.combat(g);
	cout << g << endl;
	g.soin();
	cout << g << endl;
	cout << "Fin Test Macaque attaque Gorille" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;

	cout << endl;

	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Test class Joueur" << endl;
	cout << endl;
	Joueur i;
	cout << i << endl;
	cout << "Fin Test class Joueur" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;





	cout << endl;
	cout << "---------------------------------------------" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "Déconstructeurs" << endl;*/

	static int numero = 1;
	int nbJoueur;
	int valeur;
	int flag = 0;
	bool etat;
	string nomJoueur;
	string nomSinge;
    string mot;
    vector<Joueur> tab;
    vector<Singe> singe;
    

    cout << "  ~~~~~~~~~~ ! BIENVENUE DANS LE SINGE GAME ! ~~~~~~~~~~" << endl;
    cout << endl;
    cout << "Les règles sont les suivantes :" << endl;
    cout << "- On vous attribue une somme de départ de manière aléatoire" << endl;
    cout << "- Vous pouvez parier sur un singe et augmenter votre somme à chaque tour" << endl;
    cout << "- Plus vous misez, plus vous gagnez (c'est logique)" << endl;
    cout << "- Le but : Avoir le plus d'argent à la fin de la partie" << endl;
    cout << "           Ou bien que vos adversaires n'aient plus d'argent" << endl;
    cout << endl;
    cout << "Vous êtes prêts ? .......... Ça commence !!!!" << endl;

    cout << endl;
    
    cout << "Tout d'abord veuillez choisir le nombre de participants : ";    

    cin >> nbJoueur;

    for(int i = 0; i < nbJoueur; i++)
    {
        nomJoueur = "Joueur_" + to_string(numero);
        tab.push_back(Joueur(nomJoueur));
        numero ++;
    }	

    while(1)
    {
    	if(tab.size() == 0)
    	{
    		cout << "La partie est finie" << endl;
    		return 0;
    	}
    	for(size_t i = 0; i < tab.size(); i++)
    	{
    		etat = tab[i].etatJoueur();
    		if(etat == false)
    		{
    			tab.erase(tab.begin() + i);
    		}
    		cout << "C'est au tour du joueur : " << tab[i].getName() << endl;
    		cout << "Voulez-vous parier ? (oui/non) : ";
    		cin >> mot;
    		if(mot != "oui" && mot != "non")
    		{
    			cout << "Vous vous êtes trompé de commande" << endl;
    			cout << "Vous pouvez encore choisir !" << endl;
    			mot = "non";
    		}
    		if(mot == "non")
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
	    				mot = "oui";
	    				break;
	    			}
	    			else
	    			{
	    				flag = 0;
	    			}
	    		}
    		}
    		if(mot == "oui")
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
    	}
    	for(size_t i = 0; i < tab.size(); i++)
    	{
    		nomSinge = tab[i].getChoix().getNom();

    		if(nomSinge== "Macaque")
    		{
	    		singe.push_back(Macaque(nomSinge));
    		}

    		if(nomSinge== "Gibon")
    		{
	    		singe.push_back(Gibon(nomSinge));
    		}

    		if(nomSinge== "Gorille")
    		{
	    		singe.push_back(Gorille(nomSinge));
    		}
    	}
    	for(size_t i = 0; i < singe.size(); i++)
    	{
    		singe[i].combat(singe[i-1]);
    		cout << singe[i];
    	}
    	/*for(size_t i = 1; i < singe.size(); i++)
    	{
    		cout << singe[i];
    	}*/
    }

    return 0;
}