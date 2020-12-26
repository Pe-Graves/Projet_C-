#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Gorille.hh"

using namespace std;

Gorille :: Gorille()
{
  nom = "Gorille";
  pdv = 150;
  pdc = 15;
  pds = 5;
  pa = 3;
  armure = 10;
  sigle = "CAC";
}

Gorille :: ~Gorille()
{
  cout << "~Gorille()" << endl;
}

int Gorille :: combat(Gorille& adversaire)
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

int Gorille :: soin()
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

ostream& operator<<(ostream& os, const Gorille& a)
{
  os << "Stats Gorille" << endl;
  os << "PDV : " << a.pdv << endl;
  os << "PDC : " << a.pdc << endl;
  os << "PDS : " << a.pds << endl;
  os << "Armure : " << a.armure << endl;
  os << "Point d'action : " << a.pa << endl;
  os << "Type : " << a.sigle;
  os << endl;
  return os;
}
