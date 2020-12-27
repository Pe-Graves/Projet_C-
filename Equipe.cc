#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "Equipe.hh"

using namespace std;

Equipe :: Equipe()
{}

Equipe :: ~Equipe()
{
  cout << "~Equipe()" << endl;
}
/*
ostream& operator<<(ostream& os, vector<Singes> vecteur)
{
  for(size_t i = 0; i < vecteur.size(); i++)
  {
    os << vecteur[i] << ' ';

  }
  return os;
}
*/
