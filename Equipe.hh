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

class Equipe : public Joueur
{
public:
  Equipe();
  ~Equipe();

  friend std :: ostream& operator<<(std :: ostream& os, Equipe& a);

protected:
  std :: vector<std :: string> equipeUp;
  std :: vector<std :: string> equipe;
};
