#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#include "Gibon.hh"
#include "Macaque.hh"
#include "Gorille.hh"
#include "Chimpanze.hh"
#include "Bonobo.hh"
#include "Singe.hh"
#include "Aucun.hh"



class Joueur  
{
public:
	Joueur();
	Joueur(std :: string nomJoueur);
	~Joueur();

	std :: string getName() const;
	std :: size_t getMise() const;
	Singe& getChoix() const;
	int getSomme() const;

	void setMise(const std :: size_t valeur);
	void setName(const std :: string mot);

	void gagner();
	void perdre();
	void parier(std :: string mot);
	void pasParier(std :: string mot);
	void miser(const int valeur);
	void gain();
	bool etatJoueur();


	friend std :: ostream& operator<<(std :: ostream& os, Joueur& a);

protected:	
	int somme;
	std :: size_t mise;
	std :: string name;
	Singe* choix;
};