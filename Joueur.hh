#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "Gibon.hh"
#include "Macaque.hh"
#include "Gorille.hh"



class Joueur : public Gibon, Macaque, Gorille
{
public:
	Joueur();
	~Joueur();

	void gain();
	void resultat();

	friend std :: ostream& operator<<(std :: ostream& os, Joueur& a);

protected:	
	int somme;
	int mise;
	std :: string name;
	Singe choix;
};