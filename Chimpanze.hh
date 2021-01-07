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

	void combat(Singe& adversaire);
	void soin(Singe& a);
	void soin();
	bool vie();
	void resetPA();
};