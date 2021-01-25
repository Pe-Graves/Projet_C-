#include <iostream>
#include <string>
#include <cmath>

#include "MacaqueUp.hh"

using namespace std;

MacaqueUp :: MacaqueUp() : Macaque("MacaqueUp")
{
	setPDV(200);
	setSigle("Super Tank");
	setPDC(40);
	setPDS(20);
	setArmure(50);
}	

MacaqueUp :: MacaqueUp(string nomSinge) : Macaque(nomSinge)
{
	setPDV(200);
	setSigle("Super Tank");
	setPDC(40);
	setPDS(20);
	setArmure(50);
}

MacaqueUp :: ~MacaqueUp(){}

