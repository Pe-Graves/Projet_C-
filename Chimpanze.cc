#include <iostream>
#include <string>
#include <cmath>

#include "Chimpanze.hh"

using namespace std;

Chimpanze :: Chimpanze() : Singe("Chimpanze", "Healer", 150, 5, 15, 25, 6){}	

Chimpanze :: Chimpanze(string nomSinge) : Singe(nomSinge, "Healer", 150, 5, 15, 25, 6){}

Chimpanze :: ~Chimpanze(){}

void Chimpanze :: combat(Singe& adversaire)
{
	while(getPA() >= 2)
	{
		if(adversaire.vie() == true)
		{
			int valeur = abs(int(adversaire.getArmure() - getPDC()));
			adversaire.setPDV(adversaire.getPDV() - valeur);
			setPA(getPA() - 2);
		}

		else
		{
			//cout << "Vous essayez d'attaquer un singe mort !" << endl;
		}
	}
	resetPA();
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

void Chimpanze :: soin()
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

void Chimpanze :: resetPA()
{
	setPA(6);
}
