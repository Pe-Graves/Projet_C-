#include <iostream>
#include <string>

#include "Joueur.hh"

using namespace std;

Joueur :: Joueur()
{
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
	cout << "Veuillez choisir votre nom de joueur: ";
	cin >> name;
	cout << endl;
	cout << "Vous vous appelez : " << name << endl;
	cout << endl;
	cout << "Vous commencez avec : " << somme << endl;
	cout << endl;
}

Joueur :: Joueur(string nomJoueur)
{
	name = nomJoueur;
	srand((unsigned int)time(0));
	string mot;
	somme = rand() % 100;
	cout << "Vous vous appellez " << name << endl;
	cout << "Voulez-vous changer de nom ? (oui/non) : ";
	cin >> mot;
	if(mot == "oui")
	{
		cout << "Veuillez choisir votre nom de joueur : ";
		cin >> name;
		cout << endl;
		cout << "Vous vous appelez : " << name << endl;
		cout << endl;	
	}
	cout << "Vous commencez avec : " << somme << endl;
	cout << endl;
}

Joueur :: ~Joueur()
{
	/*cout << "~Joueur()" << endl;
	cout << endl;*/
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

void Joueur :: gagner()
{
	if(this -> choix.vie() == false)
	{
		cout << "Vous avez perdu votre pari" << endl;
	}
}

void Joueur :: perdre()
{
	if(this -> choix.vie() == true)
	{
		cout << "Vous avez gagné votre pari" << endl;
	}
}

ostream& operator<<(ostream& os, Joueur& a)
{
	os << "Joueur : " << a.name << endl;
	os << "Vous avez : " << a.somme << " points" << endl;
	os << endl;
	os << a.choix << endl;
	return os;
}

void Joueur :: parier(string mot)
{
	if(mot == "Gorille")
	{
		this -> choix = Gorille();
	}
	if(mot == "Gibon")
	{
		this -> choix = Gibon();
	}
	if(mot == "Macaque")
	{
		this -> choix = Macaque();
	}
}

string Joueur :: getName() const
{
	return this -> name;
}

int Joueur :: getMise() const
{
	return this -> mise;
}

void Joueur :: setMise(int valeur)
{
	this -> mise = valeur;
}


void Joueur :: miser(int valeur)
{
	if(valeur <= somme)
	{
		somme -= valeur;
		cout << endl;
		cout << "Vous avez misé : " << valeur << endl;
		cout << endl;
	}
	else
	{
		cout << "Vous n'avez pas assez pour miser !" << endl;
	}
}

void Joueur :: pasParier(string mot)
{
	if(mot == "Passer")
	{
		this -> choix = Singe();
	}

}

bool Joueur :: etatJoueur()
{
	if(this -> somme <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


Singe Joueur :: getChoix() const
{
	return this -> choix;
}


int Joueur :: getSomme() const
{
	return this -> somme;
}
