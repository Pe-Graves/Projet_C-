#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Macaque : public Singe
{
public:
	Macaque();
	Macaque(std :: string nomSinge);
	~Macaque();

	void combat(Singe& adversaire);
	void soin(Singe& a);
	void soin();
	bool vie();
	void resetPA();
};