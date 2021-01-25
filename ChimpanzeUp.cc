#include <iostream>
#include <string>
#include <cmath>

#include "ChimpanzeUp.hh"

using namespace std;

ChimpanzeUp :: ChimpanzeUp() : Chimpanze("ChimpanzeUp")
{
	setPDV(100);
	setSigle("Super Healer");
	setPDC(30);
	setPDS(50);
	setArmure(40);
}	

ChimpanzeUp :: ChimpanzeUp(string nomSinge) : Chimpanze(nomSinge)
{
	setPDV(100);
	setSigle("Super Healer");
	setPDC(30);
	setPDS(50);
	setArmure(40);
}

ChimpanzeUp :: ~ChimpanzeUp(){}

