#include <iostream>
#include <string>
#include <cmath>

#include "Bonobo.hh"

using namespace std;

Bonobo :: Bonobo() : Singe("Bonobo", "Assassin", 150, 5, 15, 25, 6){}	

Bonobo :: Bonobo(string nomSinge) : Singe(nomSinge, "Assassin", 150, 5, 15, 25, 6){}

Bonobo :: ~Bonobo(){}

void Bonobo :: combat(Singe& adversaire, int i)
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

bool Bonobo :: vie()
{
	return getPDV() > 0;
}

void Bonobo :: soin(Singe& a)
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

void Bonobo :: soin(int luckSinge)
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

void Bonobo :: resetPA()
{
	setPA(6);
}
