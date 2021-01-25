#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Chimpanze : public Singe
{
public:
	Chimpanze();
	Chimpanze(std :: string nomSinge);
	~Chimpanze();

	void combat(Singe& adversaire, int i);
	void soin(Singe& a);
	void soin(int luckSinge);
	bool vie();
	void resetPA();
};