#pragma once

#include <iostream>
#include <string>

#include "Singe.hh"

class Macaque : public virtual Singe
{
public:
	Macaque();
	Macaque(std :: string nomSinge);
	~Macaque();
};