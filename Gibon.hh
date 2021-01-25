#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Gibon : public Singe
{
public:
	Gibon();
	Gibon(std :: string nomSinge);
	~Gibon();

	void combat(Singe& adversaire, int i);
	void soin(Singe& a);
	void soin(int luckSinge);
	bool vie();
	void resetPA();
};