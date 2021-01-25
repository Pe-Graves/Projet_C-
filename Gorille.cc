#include <iostream>
#include <string>
#include <cmath>

#include "Gorille.hh"

using namespace std;

Gorille :: Gorille() : Singe("Gorille", "CAC", 100, 20, 5, 10, 6){}	

Gorille :: Gorille(string nomSinge) : Singe(nomSinge, "CAC", 100, 20, 5, 10, 6){}

Gorille :: ~Gorille(){}

void Gorille :: combat(Singe& adversaire, int i)
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

bool Gorille :: vie()
{
	return getPDV() > 0;
}

void Gorille :: soin(Singe& a)
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

void Gorille :: soin(int luckSinge)
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

void Gorille :: resetPA()
{
	setPA(6);
}
