#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class Joueur
{
public:
  Joueur();
  ~Joueur();

protected:
  std :: string name1;
  int nbSinges;
  int nbSingesUp;
};
