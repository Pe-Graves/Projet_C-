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

	void combat(Singe& adversaire);
	void soin(Singe& a);
	void soin();
	bool vie();
	void resetPA();
};