#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "Singe.hh"

class Aucun : public Singe
{
	public:
		Aucun();
		Aucun(std :: string nomSinge);
		~Aucun();

		void combat(Singe& adversaire);
		void soin(Singe& a);
		void soin();
		bool vie();
		void resetPA();
};
