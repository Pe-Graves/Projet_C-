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
	Joueur(std :: string nomJoueur);
	~Joueur();

	std :: string getName() const;
	int getMise() const;
	Singe getChoix() const;
	int getSomme() const;

	void setMise(int valeur);

	void gagner();
	void perdre();
	void parier(std :: string mot);
	void pasParier(std :: string mot);
	void miser(int valeur);
	void gain();
	bool etatJoueur();


	friend std :: ostream& operator<<(std :: ostream& os, Joueur& a);

protected:	
	int somme;
	int mise;
	std :: string name;
	Singe choix;
};