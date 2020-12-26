#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "MacaqueUp.hh"

using namespace std;

MacaqueUp :: MacaqueUp() : Macaque()
{
  nom = "Macaque Up";
  pdv = 60;
  pdc = 35;
}

MacaqueUp :: ~MacaqueUp()
{
  cout << "~MacaqueUp()" << endl;
}

ostream& operator<<(ostream& os, MacaqueUp& a)
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
