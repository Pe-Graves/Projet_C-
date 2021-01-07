#include <iostream>
#include <string>
#include <cmath>

#include "Gibon.hh"

using namespace std;

Gibon :: Gibon() : Singe("Gibon", "Distance", 80, 25, 10, 10, 6){}	

Gibon :: Gibon(string nomSinge) : Singe(nomSinge, "Distance", 80, 25, 10, 10, 6){}

Gibon :: ~Gibon(){}

void Gibon :: combat(Singe& adversaire)
{
	if(getPA() >= 2)
	{
		if(adversaire.vie() == true)
		{
			int valeur = abs(int(adversaire.getArmure() - getPDC()));
			adversaire.setPDV(adversaire.getPDV() - valeur);
			setPA(getPA() - 2);
		}

		else
		{
			cout << "Vous essayez d'attaquer un singe mort !" << endl;
		}

	}
}

bool Gibon :: vie()
{
	return getPDV() > 0;
}

void Gibon :: soin(Singe& a)
{
	
	if(a.vie() == true)
	{
		a.setPDV(a.getPDV() + getPDS());
		setPA(getPA() - 2);
	}
	else
	{
		cout << "Vous essayez d'soigner un singe mort !" << endl;
	}
}

void Gibon :: soin()
{
	if(vie() == true)
	{
		setPDV(getPDV() + getPDS());
		setPA(getPA() - 2);

	}
	else
	{
		cout << "Ce singe est déjà mort !" << endl;
	}
}

void Gibon :: resetPA()
{
	setPA(6);
}
