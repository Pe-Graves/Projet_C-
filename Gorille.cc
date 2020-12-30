#include <iostream>
#include <string>

#include "Gorille.hh"

using namespace std;

Gorille :: Gorille() : Singe()
{
	nom = "Gorille";
	sigle = "CAC";
	armure = 20;
	pds = 5;
	pdv = 120;
}	

Gorille :: Gorille(string nomSinge)
{
	nom = nomSinge;
	sigle = "CAC";
	armure = 20;
	pds = 5;
	pdv = 120;
}

Gorille :: ~Gorille()
{
	/*cout << "~Gorille()" << endl;
	cout << endl;*/
}
