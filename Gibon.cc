#include <iostream>
#include <string>

#include "Gibon.hh"

using namespace std;

Gibon :: Gibon()
{
	nom = "Gibon";
	sigle = "Distance";
	armure = 5;
	pdv = 80;
	pdc = 12;
	pds = 7;
}

Gibon :: ~Gibon()
{
	cout << "~Gibon()" << endl;
}