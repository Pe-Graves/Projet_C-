#include <iostream>
#include <string>
#include <cmath>

#include "Singe.hh"

using namespace std;

Singe :: Singe()
{
	nom = "Singe";
	sigle = "Inconnu";

	pdv = 100;
	pdc = 10;
	pds = 10;
	armure = 10;
	pa = 6;
}

Singe :: ~Singe()
{
	cout << "~Singe()" << endl;
}

void Singe :: combat(Singe& adversaire)
{
	if(this -> pa >= 2)
	{
		if(adversaire.vie() == true)
		{
			int valeur = abs(adversaire.armure - this -> pdc);
			adversaire.pdv -= valeur;
			this -> pa -= 2;
		}

		else
		{
			cout << "Vous essayez d'attaquer un singe mort !" << endl;
		}

	}
}

bool Singe :: vie() const
{
	return this -> pdv > 0;
}

void Singe :: soin(Singe& a)
{
	
	if(a.vie() == true)
	{
		a.pdv += this -> pds;
		this -> pa -= 2;
	}
	else
	{
		cout << "Vous essayez d'soigner un singe mort !" << endl;
	}
}

void Singe :: soin()
{
	if(this -> vie() == true)
	{
		this -> pdv += this -> pds;
		this -> pa -= 2;

	}
	else
	{
		cout << "Ce singe est déjà mort !" << endl;
	}
}

ostream& operator<<(ostream& os, Singe& a)
{
	os << "Stats " << a.nom << endl;
 	os << "PDV : " << a.pdv << endl;
 	os << "PDC : " << a.pdc << endl;
	os << "PDS : " << a.pds << endl;
 	os << "Armure : " << a.armure << endl;
 	os << "Point d'action : " << a.pa << endl;
 	os << "Type : " << a.sigle;
 	os << endl;

 	return os;
}

void Singe :: resetPA()
{
	this -> pa = 6;
}

