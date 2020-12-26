#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Gibon.hh"

using namespace std;

Gibon :: Gibon()
{
  nom = "Gibon";
  pdv = 80;
  pdc = 5;
  pds = 10;
  pa = 4;
  armure = 5;
  sigle = "Distance";
}

Gibon :: ~Gibon()
{
  cout << "~Gibon()" << endl;
}

ostream& operator<<(std :: ostream& os, const Gibon& a)
{
  os << "Stats " << a.nom << endl;
  os << "PDV : " << a.pdv << endl;
  os << "PDC : " << a.pdc << endl;
  os << "PDS : " << a.pds << endl;
  os << "Armure : " << a.armure << endl;
  os << "Point d'action : " << a.pa << endl;
  os << "Type : " << a.sigle;
  os << endl;
  return os;
}
