#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "MacaqueUp.hh"

using namespace std;

MacaqueUp :: MacaqueUp()
{
  nom = "MacaqueUp ";
  pdv = 60;
  pdc = 30;
  pds = 0;
  pa = 4;
  armure = 25;
  sigle = "Distance";
}

MacaqueUp :: ~MacaqueUp()
{
  cout << "~MacaqueUp()" << endl;
}

ostream& operator<<(ostream& os, MacaqueUp& a)
{
  os << "Stats MacaqueUp" << endl;
  os << "PDV : " << a.pdv << endl;
  os << "PDC : " << a.pdc << endl;
  os << "PDS : " << a.pds << endl;
  os << "Armure : " << a.armure << endl;
  os << "Point d'action : " << a.pa << endl;
  os << "Type : " << a.sigle;
  os << endl;
  return os;
}
