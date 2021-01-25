#include <iostream>
#include <string>
#include <cmath>

#include "Gibon.hh"

using namespace std;

Gibon :: Gibon() : Singe("Gibon", "Distance", 80, 25, 10, 10, 6){}	

Gibon :: Gibon(string nomSinge) : Singe(nomSinge, "Distance", 80, 25, 10, 10, 6){}

Gibon :: ~Gibon(){}

void Gibon :: combat(Singe& adversaire, int i)
{
	int valeur = abs(int(adversaire.getArmure() - getPDC()));
	for(int j = 1; j <= i; j++)
	{
		if(adversaire.vie() == true)
		{
			adversaire.setPDV(adversaire.getPDV() - valeur);
			setPA(getPA() - 2);
		}
		else
		{
			adversaire.setPDV(0);
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

void Gibon :: soin(int luckSinge)
{
	for(int i = 0; i < 3 - luckSinge; i++)
	{
		if(vie() == true)
		{
			setPDV(getPDV() + getPDS());
			setPA(getPA() - 2);

		}
		else
		{
			cout << "Ce singe est déjà mort !" << endl;
			setPDV(0);
		}
	}
}

void Gibon :: resetPA()
{
	setPA(6);
}
