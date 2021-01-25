#pragma once 

#include "Joueur.hh"

class Jeu
{

public:
	
	Jeu();
	~Jeu();

	Joueur& getOrdinateur() const;

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
	void ordinateurSinge();
	int checkSinge();
	std :: string IA();
	int joueurVsIA();
	int joueurVsJoueur();
	void infini();

protected:
	static int numero;
	std :: size_t nbJoueur;
	std :: string nomSinge;
    std :: vector <Joueur> tab;
    Joueur* ordinateur;
};