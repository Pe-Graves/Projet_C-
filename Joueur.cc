#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#include "Joueur.hh"

using namespace std;

Joueur :: Joueur()
{
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
	cout << "Veuillez choisir votre nom de joueur: ";
	cin >> name;
	cout << endl << "Vous vous appelez : " << name << endl << endl;
	cout << "Vous commencez avec : " << somme << endl << endl;
}

Joueur :: Joueur(string nomJoueur)
{
	name = nomJoueur;
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
}

Joueur :: ~Joueur()
{
	/*cout << "~Joueur()" << endl;
	cout << endl;*/
}

void Joueur :: gain()
{
	if(mise <= 10)
	{
		somme += mise * 2;	
	}
	else if(mise <= 30 && mise > 10)
	{
		somme += mise * 3;
	}
	else if(mise <= 50 && mise > 30)
	{
		  somme += mise * 5;
	}
	else if(mise <= 70 && mise > 50)
	{
		  somme += mise * 7;
	}
	else if( mise <= 90 && mise > 70)
	{
		 somme += mise * 9;
	}
	else if(mise < 150 && mise > 90)
	{
		  somme += mise * 13;
	}
	else
	{
		  somme += mise * 20;
	}


}

void Joueur :: gagner()
{
	if(choix -> vie() == false)
	{
		cout << "Vous avez gagné votre pari" << endl;
	}
}

void Joueur :: perdre()
{
	if(choix -> vie() == true)
	{
		cout << "Vous avez perdu votre pari" << endl;
	}
}

ostream& operator<<(ostream& os, Joueur& a)
{
	os << "Joueur : " << a.name << endl;
	os << "Vous avez : " << a.somme << " points" << endl << endl;
	//os << a.choix -> getNom() << endl;
	return os;
}

void Joueur :: parier(string mot)
{
	if(mot == "Gorille")
	{
		choix = new Gorille();
	}
	else if(mot == "Gibon")
	{
		choix = new Gibon();
	}
	else if(mot == "Macaque")
	{
		choix = new Macaque();
	}
	else if(mot == "Bonobo")
	{
		choix = new Bonobo();
	}
	else if(mot == "Chimpanze")
	{
		choix = new Chimpanze();
	}
	else if(mot == "aucun")
	{}
	else
	{
		cout << "Erreur" << endl << "Sur quel singe voulez-vous parier ? (ou aucun) : ";
		cin >> mot;
		parier(mot);
	}
}

string Joueur :: getName() const
{
	return name;
}

size_t Joueur :: getMise() const
{
	return mise;
}

void Joueur :: setMise(const size_t valeur)
{
	mise = valeur;
}


void Joueur :: miser(const int valeur)
{
	if(valeur <= somme)
	{
		somme -= valeur;
		cout << endl << "Vous avez misé : " << valeur << endl << endl;
	}
	else
	{
		size_t valeur2;
		cout << "Erreur" << endl << "Combien voulez-vous miser ? : ";
		cin >> valeur2;
		setMise(valeur2);
		miser(mise);
	}
}

void Joueur :: pasParier(string mot)
{
	cout << "Passe le tour !" << endl;
}

bool Joueur :: etatJoueur()
{
	if(somme <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


Singe& Joueur :: getChoix() const
{
	return *choix;
}


int Joueur :: getSomme() const
{
	return somme;
}

void Joueur :: setName(const string mot)
{
	name = mot;
}

