#include <iostream>
#include <string>
#include <cmath>

#include "Macaque.hh"

using namespace std;

Macaque :: Macaque() : Singe("Macaque", "Tank", 150, 5, 15, 25, 6){}	

Macaque :: Macaque(string nomSinge) : Singe(nomSinge, "Tank", 150, 5, 15, 25, 6){}

Macaque :: ~Macaque(){}

void Macaque :: combat(Singe& adversaire)
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

bool Macaque :: vie()
{
	return getPDV() > 0;
}

void Macaque :: soin(Singe& a)
{
	
	if(a.vie() == true)
	{
		a.setPDV(a.getPDV() + getPDS());
		setPA(getPA() - 2);
	}
	else
	{
		cout << "Vous essayez de soigner un singe mort !" << endl;
	}
}

void Macaque :: soin()
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

void Macaque :: resetPA()
{
	setPA(6);
}
