#include <iostream>
#include <string>

#include "Macaque.hh"

using namespace std;

Macaque ::  Macaque() : Singe()
{
	nom = "Macaque";
	sigle = "CAC";
	pdc = 25;
	armure = 15;
	pds = 3;
	pdv = 110;

}

Macaque :: ~Macaque()
{
	cout << "~Macaque()" << endl;
}
