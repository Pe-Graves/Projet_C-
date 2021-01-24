#include <iostream>
#include <string>
#include <cmath>

#include "Gorille.hh"

using namespace std;

Gorille :: Gorille() : Singe("Gorille", "CAC", 100, 20, 5, 10, 6){}	

Gorille :: Gorille(string nomSinge) : Singe(nomSinge, "CAC", 100, 20, 5, 10, 6){}

Gorille :: ~Gorille(){}

void Gorille :: combat(Singe& adversaire)
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

void Gorille :: soin()
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

void Gorille :: resetPA()
{
	setPA(6);
}
