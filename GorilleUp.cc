#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "GorilleUp.hh"

using namespace std;

GorilleUp :: GorilleUp()
{
  nom = "Gorille Up";
  pdv = 250;
  pdc = 20;
  armure = 15;
}

GorilleUp :: ~GorilleUp()
{
  cout << "~GorilleUp()" << endl;
}

int GorilleUp :: combat(GorilleUp& adversaire)
{

  if(this -> pa <= 0)
  {
    cout << "Vous ne pouvez plus faire d'action !" << endl;
    return -1;
  }
  if(this -> pa >= 2)
  {
    adversaire.pdv -= this -> pdc;
  }
  return adversaire.pdv;
}

int GorilleUp :: soin()
{
  if(this -> pa <= 0)
  {
    cout << "Vous ne pouvez plus faire d'action !" << endl;
    return -1;
  }
  else
  {
    this -> pdv += this -> pds;
  }
  return this -> pdv;
}

ostream& operator<<(ostream& os, const GorilleUp& a)
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
