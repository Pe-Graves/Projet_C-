// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Aucun.hh"
#include "Bonobo.hh"
#include "BonoboUp.hh"
#include "Chimpanze.hh"
#include "ChimpanzeUp.hh"
#include "Gibon.hh"
#include "GibonUp.hh"
#include "Gorille.hh"
#include "GorilleUp.hh"
#include "Jeu.hh"
#include "Joueur.hh"
#include "Macaque.hh"
#include "MacaqueUp.hh"
#include "Singe.hh"
#include <iostream>
#include <string>


TEST_CASE("1:Tests de combats simples entre singes"){
  //Test de combat simple
  Gorille gorille;
  REQUIRE(gorille.getPDV() == 90);
  GorilleUp gorilleUp;
  REQUIRE(gorilleUp.getPDV() == 180);
  std::cout << "gorille combat gorilleUp "<< std::endl;
  gorille.combat(gorilleUp, 3);
  std::cout << "gorille combat gorilleUp "<< std::endl;
  gorilleUp.combat(gorille, 3);
  REQUIRE_FALSE(gorille.vie());
  REQUIRE(gorilleUp.vie());
  std::cout << "gorille a " << gorille.getPDV() << " pdv" << std::endl;
  std::cout << "gorilleUp a " << gorilleUp.getPDV() << " pdv" << std::endl;

  //Un singe ne peut soigner qu'un singe en vie
  ChimpanzeUp chimpanzeUp; 
  chimpanzeUp.soin(gorille);
  chimpanzeUp.soin(gorilleUp);
  REQUIRE(gorille.getPDV() == 0);
  REQUIRE(gorilleUp.getPDV() == 140);
}

TEST_CASE("2:Tests sur des Joueurs"){
  //Alice ne peut pas miser plus que ce qu'elle a
  Joueur alice = Joueur("Alice"); 
  int somme_alice = alice.getSomme();
  alice.setMise(100);
  REQUIRE(alice.getSomme() == somme_alice); 

  //Test de la formule de gain
  int gains_theoriques = somme_alice + (100*13);
  alice.gain();
  REQUIRE(alice.getSomme() == gains_theoriques); 
}