#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>

#include "Equipe.hh"

using namespace std;

Equipe :: Equipe() : Joueur()
{
  srand((unsigned int)time(0));
  for(int i = 0; i < this -> nbSingesUp; i++)
  {
    int valeur = rand() % 3 + 1;
    if(valeur == 1)
    {
      equipeUp.push_back("GorilleUp");
    }
    if(valeur == 2)
    {
      equipeUp.push_back("GibonUp");
    }
    if(valeur == 3)
    {
      equipeUp.push_back("MacaqueUp");
    }
  }

  for(int i = 0; i < this -> nbSinges; i++)
  {
    int valeur = rand() % 3 + 1;
    if(valeur == 1)
    {
      equipe.push_back("Gorille");
    }
    if(valeur == 2)
    {
      equipe.push_back("Gibon");
    }
    if(valeur == 3)
    {
      equipe.push_back("Macaque");
    }
  }
}

Equipe :: ~Equipe()
{
  cout << "~Equipe()" << endl;
}


ostream& operator<<(ostream& os, Equipe& a)
{
  os << "Equipe de singes normaux : " << endl;
  os << endl;

  for(size_t i = 0; i < a.equipe.size(); i++)
  {
    os << a.equipe[i] << endl;
  }

  os << endl;
  os << "Equipe de singes UP : " << endl;
  os << endl;

  for(size_t i = 0; i < a.equipeUp.size(); i++)
  {
    os << a.equipeUp[i] << endl;
  }

  return os;
}
