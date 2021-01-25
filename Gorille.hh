#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Gorille : public Singe
{
public:
	Gorille();
	Gorille(std :: string nomSinge);
	~Gorille();

	void combat(Singe& adversaire, int i);
	void soin(Singe& a);
	void soin(int luckSinge);
	bool vie();
	void resetPA();
};