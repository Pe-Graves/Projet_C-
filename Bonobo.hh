#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Bonobo : public Singe
{
public:
	Bonobo();
	Bonobo(std :: string nomSinge);
	~Bonobo();

	void combat(Singe& adversaire);
	void soin(Singe& a);
	void soin();
	bool vie();
	void resetPA();
};