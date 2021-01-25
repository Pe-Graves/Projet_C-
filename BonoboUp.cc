#include <iostream>
#include <string>
#include <cmath>

#include "BonoboUp.hh"

using namespace std;

BonoboUp :: BonoboUp() : Bonobo("BonoboUp")
{
	setSigle("Super Assassin");
	setPDV(120);
	setPDC(90);
	setPDS(20);
	setArmure(30);
}	

BonoboUp :: BonoboUp(string nomSinge) : Bonobo(nomSinge)
{
	setSigle("Super Assassin");
	setPDV(120);
	setPDC(90);
	setPDS(20);
	setArmure(30);
}

BonoboUp :: ~BonoboUp(){}

