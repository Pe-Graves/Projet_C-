#include <iostream>
#include <string>
#include <cmath>

#include "GorilleUp.hh"

using namespace std;

GorilleUp :: GorilleUp() : Gorille("GorilleUp")
{
	setPDV(180);
	setSigle("Super CAC");
	setPDC(70);
	setPDS(20);
	setArmure(25);
}	

GorilleUp :: GorilleUp(string nomSinge) : Gorille(nomSinge)
{
	setPDV(180);
	setSigle("Super CAC");
	setPDC(70);
	setPDS(20);
	setArmure(25);
}

GorilleUp :: ~GorilleUp(){}