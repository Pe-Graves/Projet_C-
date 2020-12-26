#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class Singes
{

protected:
  std :: string nom;
  int pdv;
  int pdc;
  int pds;
  int pa;
  int armure;
  std :: string sigle;

public:
  Singes(){};
  virtual ~Singes(){};

  /*int getPDV() const {return pdv;};
  int getPDC() const {return pdc;};
  int getPDS() const {return pds;};
  int getPointAction() const {return pa;};
  std :: string getNom() const {return nom;};
  std :: string getSigle() const {return sigle;};
*/
  //virtual int combat();
  //virtual int soin();
};
