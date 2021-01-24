#pragma once 

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#include "Gibon.hh"
#include "Gorille.hh"
#include "Macaque.hh"
#include "Chimpanze.hh"
#include "Bonobo.hh"
#include "Aucun.hh"
#include "Joueur.hh"

class Jeu
{

public:
	
	Jeu();
	~Jeu();

	void jouer();

	void intro();

	void joueur();
	void changeName(const std :: size_t i, std :: string mot);

	void partie();
	void debutTour(int fin);
	void tour(std :: string mot, const std :: size_t i);
	int finPartie();
	void suppJoueur(const std :: size_t i);
	void choixSinge();
	void decision(std :: string mot, std :: size_t i, std :: size_t decision);

	void singe();
	//void singe1();
	void ordinateurSinge();
	int checkSinge();
	std :: string IA();
	//void fight();
	//void fight2();
	//void fight3();
	int unSurDeux();
	int chance();

protected:
	static int numero;
	std :: size_t nbJoueur;
	std :: string nomSinge;
    std :: vector <Joueur> tab;
    Joueur* ordinateur;
};