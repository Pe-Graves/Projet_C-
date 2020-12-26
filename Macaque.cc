#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Macaque.hh"

using namespace std;

Macaque :: Macaque()
{
  nom = "Macaque ";
  pdv = 50;
  pdc = 30;
  pds = 0;
  pa = 4;
  armure = 25;
  sigle = "Distance";
}

Macaque :: ~Macaque()
{
  cout << "~Macaque()" << endl;
}

ostream& operator<<(ostream& os, Macaque& a)
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
