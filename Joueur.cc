#include <iostream>
#include <string>

#include "Joueur.hh"

using namespace std;

Joueur :: Joueur()
{
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
	mise = 200;
	cout << "Veuillez choisir votre nom de joueur: ";
	cin >> name;
	cout << endl;
	cout << "Vous vous appelez : " << name << endl;
	cout << endl;
	cout << "Vous commencez avec : " << somme << endl;
	cout << endl;
	while(mise > somme)
	{
		cout << "Combien voulez-vous miser ? : ";
		cin >> mise;
		if(mise <= somme)
		{
			somme -= mise;
			cout << endl;
			cout << "Vous avez misé : " << mise << endl;
			cout << endl;
			break;
		}
		else
		{
			cout << "Vous n'avez pas assez pour miser !" << endl;
		}
		
	}
	while(1)
	{
		cout << "Sur quel singe voulez-vous miser ? (ou aucun)" << endl;
		cin >> mot;
		if(mot == "Gorille")
		{
			choix = Gorille();
			break;
		}
		if(mot == "Gibon")
		{
			choix = Gibon();
			break;
		}
		if(mot == "Macaque")
		{
			choix = Macaque();
			break;
		}
		if(mot == "aucun")
		{
			break;
		}
		else
		{
			cout << "Vous n'avez pas bien choisi votre singe" << endl;
		}	
	}
}

Joueur :: ~Joueur()
{
	cout << "~Joueur()" << endl;
}

void Joueur :: gain()
{
	if(this -> mise <= 10)
	{
		this -> somme += (this -> mise) * 2; 	
	}
	if(this -> mise <= 30)
	{
		this -> somme += (this -> mise) * 3;
	}
	if(this -> mise <= 50)
	{
		this -> somme += (this -> mise) * 5;
	}
	if(this -> mise <= 70)
	{
		this -> somme += (this -> mise) * 7;
	}
	if(this -> mise <= 90)
	{
		this -> somme += (this -> mise) * 9;
	}
	if(this -> mise < 150)
	{
		this -> somme += (this -> mise) * 13;
	}
	else
	{
		this -> somme += (this -> mise) * 20;
	}


}

void Joueur :: resultat()
{
	if(this -> choix.vie() == false)
	{
		cout << "Vous avez perdu votre pari" << endl;
	}

	else
	{
		cout << "Vous avez gagné votre pari" << endl;
		gain();
	}
}

ostream& operator<<(ostream& os, Joueur& a)
{
	os << "Joueur : " << a.name << endl;
	os << "Vous avez : " << a.somme << endl;
	os << a.choix << endl;
	return os;
}