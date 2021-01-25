#include <iostream>
#include <string>
#include <cmath>

#include "GibonUp.hh"

using namespace std;

GibonUp :: GibonUp() : Gibon("GibonUp")
{
	setPDV(90);
	setSigle("Super Distance");
	setPDC(90);
	setPDS(20);
	setArmure(50);
}	

GibonUp :: GibonUp(string nomSinge) : Gibon(nomSinge)
{
	setPDV(90);
	setSigle("Super Distance");
	setPDC(90);
	setPDS(20);
	setArmure(50);
}

GibonUp :: ~GibonUp(){}

