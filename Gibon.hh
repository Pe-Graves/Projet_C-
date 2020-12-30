#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Gibon : public virtual Singe
{
public:
	Gibon();
	Gibon(std :: string nomSinge);
	~Gibon();
};