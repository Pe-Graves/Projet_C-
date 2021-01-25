#include <iostream>
#include <string>
#include <cmath>

#include "Macaque.hh"

using namespace std;

Macaque :: Macaque() : Singe("Macaque", "Tank", 150, 5, 15, 25, 6){}	

Macaque :: Macaque(string nomSinge) : Singe(nomSinge, "Tank", 150, 5, 15, 25, 6){}

Macaque :: ~Macaque(){}

void Macaque :: combat(Singe& adversaire,int i)
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
	//adversaire.setPDV(adversaire.getPDV() - valeur);
	//setPA(getPA() - 2);
	/*while(getPA() >= 2)
	{
		if(adversaire.vie() == true)
		{
			int valeur = abs(int(adversaire.getArmure() - getPDC()));
			adversaire.setPDV(adversaire.getPDV() - valeur);
			setPA(getPA() - 2);
		}

		else
		{
			//cout << "ON TUE LE SINGE ENNEMI" << endl;
			adversaire.setPDV(0);
		}

	}
	//resetPA();*/
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
		a.setPDV(0);
	}
}

void Macaque :: soin(int luckSinge)
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

void Macaque :: resetPA()
{
	setPA(6);
}
