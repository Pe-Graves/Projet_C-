#include <iostream>
#include <string>
#include <cmath>

#include "Aucun.hh"

using namespace std;

Aucun :: Aucun() : Singe("Aucun", "Aucun", 1000, 20, 5, 10, 6){}	

Aucun :: Aucun(string nomSinge) : Singe("Aucun", "Aucun", 100, 20, 5, 10, 6){}

Aucun :: ~Aucun(){}

void Aucun :: combat(Singe& adversaire, int i){}

bool Aucun :: vie(){return true;}

void Aucun :: soin(Singe& a){}

void Aucun :: soin(int luckSinge){}

void Aucun :: resetPA(){}

void Aucun :: special(Singe& adversaire){}
