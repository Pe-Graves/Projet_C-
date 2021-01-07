#include <iostream>
#include <string>
#include <cmath>

#include "Bonobo.hh"

using namespace std;

Bonobo :: Bonobo() : Singe("Bonobo", "Assassin", 150, 5, 15, 25, 6){}	

Bonobo :: Bonobo(string nomSinge) : Singe(nomSinge, "Assassin", 150, 5, 15, 25, 6){}

Bonobo :: ~Bonobo(){}

void Bonobo :: combat(Singe& adversaire)
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

void Bonobo :: soin()
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

void Bonobo :: resetPA()
{
	setPA(6);
}
