#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "GibonUp.hh"

using namespace std;

GibonUp :: GibonUp()
{
  nom = "Gibon Up";
  pdv = 95;
  pdc = 5;
  pds = 10;
  pa = 4;
  armure = 10;
  sigle = "Distance";
}

GibonUp :: ~GibonUp()
{
  cout << "~GibonUp()" << endl;
}

ostream& operator<<(std :: ostream& os, const GibonUp& a)
{
  os << "Stats GibonUp" << endl;
  os << "PDV : " << a.pdv << endl;
  os << "PDC : " << a.pdc << endl;
  os << "PDS : " << a.pds << endl;
  os << "Armure : " << a.armure << endl;
  os << "Point d'action : " << a.pa << endl;
  os << "Type : " << a.sigle;
  os << endl;
  return os;
}
