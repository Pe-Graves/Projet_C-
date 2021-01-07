#pragma once 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

#include "Singe.hh"
#include "Gibon.hh"
#include "Gorille.hh"
#include "Macaque.hh"
#include "Chimpanze.hh"
#include "Bonobo.hh"
#include "Joueur.hh"

class Jeu
{

public:
	Jeu();
	~Jeu();

	void intro();
	void joueur();
	void partie();
	void changeName(const std :: size_t i, std :: string mot);

	int finPartie();
	void suppJoueur(const std :: size_t i);
	void tour(std :: string mot, int flag, const std :: size_t i);
	void choixSinge();
	void debutTour(int fin, int flag);
	//void checkPari(std :: string mot);
	void listeSinge(std :: size_t i, std :: string mot);
	void decision(std :: string mot, std :: size_t i, int flag, std :: size_t decision);

	void jouer();

protected:
	static int numero;
	std :: size_t nbJoueur;
	std :: string nomSinge;
    std :: vector <Joueur> tab;
    //std :: vector <Singe> singe;
};