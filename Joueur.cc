#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#include "Joueur.hh"

using namespace std;

Joueur :: Joueur() // Constructeur
{
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
	choix = new Aucun();
	cout << "Veuillez choisir votre nom de joueur: ";
	cin >> name;
	cout << endl << "Vous vous appelez : " << name << endl << endl;
	cout << "Vous commencez avec : " << somme << endl << endl;
	player.first = name;
	player.second = choix;
}

Joueur :: Joueur(string nomJoueur) // Constructeur
{
	name = nomJoueur;
	srand((unsigned int)time(0));
	string mot;
	choix = new Aucun();
	somme = rand() % 100;
	player.first = name;
	player.second = choix;
}

Joueur :: ~Joueur() // Deconstructeur
{
	/*cout << "~Joueur()" << endl << endl;*/
}

void Joueur :: gain() // fonction pour attribuer le gain du joueur en cas de victoire
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

void Joueur :: gagner() // fonction pour dire que le joueur a gagner son pari
{
		cout << getName() << " a gagné son pari" << endl;
		gain();
}

void Joueur :: perdre() // fonction pour dire que le joueur a perdu son pari
{
		cout << getName() << " a perdu son pari" << endl;
}

ostream& operator<<(ostream& os, Joueur& a) // operator pour afficher le joueur
{
	os << "Joueur : " << a.name << endl;
	os << "Vous avez : " << a.getSomme() << " points" << endl << endl;
	os << "Votre singe : " << a.getChoix().getNom() << endl;
	return os;
}

void Joueur :: parier(string mot) // Fonction qui permet de donner un singe au joueur ou aucun
{
	srand((unsigned int)time(0));
	int chance = rand()%100;
	if(mot == "Gorille")
	{
		if(chance == 10 || chance == 20 || chance == 30 || chance == 40 || chance == 50 || chance == 60 || chance == 70 || chance == 80 || chance == 90 || chance == 100)
		{
			choix = new GorilleUp();
			player.second = choix;
		}

		else
		{
			choix = new Gorille();
			player.second = choix;
		}
	}
	else if(mot == "Gibon")
	{
		if(chance == 10 || chance == 20 || chance == 30 || chance == 40 || chance == 50 || chance == 60 || chance == 70 || chance == 80 || chance == 90 || chance == 100)
		{
			choix = new GibonUp();
			player.second = choix;
		}

		else
		{
			choix = new Gibon();
			player.second = choix;
		}
	}
	else if(mot == "Macaque")
	{
		if(chance == 10 || chance == 20 || chance == 30 || chance == 40 || chance == 50 || chance == 60 || chance == 70 || chance == 80 || chance == 90 || chance == 100)
		{
			choix = new MacaqueUp();
			player.second = choix;
		}

		else
		{
			choix = new Macaque();
			player.second = choix;
		}
	}
	else if(mot == "Bonobo")
	{
		if(chance == 10 || chance == 20 || chance == 30 || chance == 40 || chance == 50 || chance == 60 || chance == 70 || chance == 80 || chance == 90 || chance == 100)
		{
			choix = new BonoboUp();
			player.second = choix;
		}

		else
		{
			choix = new Bonobo();
			player.second = choix;
		}
	}
	else if(mot == "Chimpanze")
	{
		if(chance == 10 || chance == 20 || chance == 30 || chance == 40 || chance == 50 || chance == 60 || chance == 70 || chance == 80 || chance == 90 || chance == 100)
		{
			choix = new ChimpanzeUp();
			player.second = choix;
		}
		
		else
		{
			choix = new Chimpanze();
			player.second = choix;
		}
	}
}

string Joueur :: getName() const // getter du nom du joueur
{
	return name;
}

size_t Joueur :: getMise() const // getter de la mise du joueur
{
	return mise;
}

void Joueur :: setMise(const size_t valeur) // setter pour la mise du joueur
{
	mise = valeur;
}


void Joueur :: miser(const int valeur) // fonction pour miser la somme que l'on souhaite
{
	if(valeur <= somme) // dans le cas où on peut miser
	{
		somme -= valeur;
		cout << endl << getName() <<  " a misé : " << valeur << endl << endl;
	}
	else // dans le cas où on ne peut pas miser
	{
		size_t valeur2;
		cout << "Combien voulez-vous miser ? : ";
		cin >> valeur2;
		setMise(valeur2);
		miser(mise);
	}
}

void Joueur :: pasParier(string mot) // fonction pour passer son tour
{
	cout << "Passe le tour !" << endl;
}

bool Joueur :: etatJoueur() // fonction qui retourne si le joueur est toujours dans la partie
{
	if(somme <= 0) // s'il a plus d'argent il a perdu
	{
		return false;
	}
	else
	{
		return true;
	}
}


Singe& Joueur :: getChoix() const // getter du singe du joueur
{
	return *choix;
}


int Joueur :: getSomme() const // getter de la somme du joueur
{
	return somme;
}

void Joueur :: setName(const string mot) // stter pour le nom du joueur
{
	name = mot;
}
