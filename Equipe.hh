#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "GibonUp.hh"
#include "MacaqueUp.hh"
#include "GorilleUp.hh"
#include "Joueur.hh"

class Equipe : public GibonUp, GorilleUp, MacaqueUp, Joueur
{
public:
  Equipe();
  ~Equipe();

  //friend std :: ostream& operator<<(std :: ostream& os, std :: vector<Singes>& vecteur);

protected:
  std :: vector<Singes> equipe;
};
