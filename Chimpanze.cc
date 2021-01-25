#include <iostream>
#include <string>
#include <cmath>

#include "Chimpanze.hh"

using namespace std;

Chimpanze :: Chimpanze() : Singe("Chimpanze", "Healer", 50, 15, 25, 20, 6){}	

Chimpanze :: Chimpanze(string nomSinge) : Singe(nomSinge, "Healer", 50, 15, 25, 20, 6){}

Chimpanze :: ~Chimpanze(){}

void Chimpanze :: combat(Singe& adversaire, int i)
{
	int valeur = abs(int(adversaire.getArmure() - getPDC()));
	for(int j = 1; j <= i; j++)
	{
		if(adversaire.vie() == true)
		{
			adversaire.setPDS(adversaire.getPDS() - 1);
			adversaire.setPDV(adversaire.getPDV() - valeur);
			setPA(getPA() - 2);
		}
		else
		{
			adversaire.setPDV(0);
		}
	}
}

bool Chimpanze :: vie()
{
	return getPDV() > 0;
}

void Chimpanze :: soin(Singe& a)
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

void Chimpanze :: soin(int luckSinge)
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

void Chimpanze :: resetPA()
{
	setPA(6);
}