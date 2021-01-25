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

	void combat(Singe& adversaire, int i);
	void soin(Singe& a);
	void soin(int luckSinge);
	bool vie();
	void resetPA();
};