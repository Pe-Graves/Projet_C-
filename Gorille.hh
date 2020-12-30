#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Gorille : public virtual Singe
{
public:
	Gorille();
	Gorille(std :: string nomSinge);
	~Gorille();
};