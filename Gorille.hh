#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Singes.hh"

class Gorille : public virtual Singes
{
public:
  Gorille();
  ~Gorille();

  int combat(Gorille& adversaire);
  int soin();

  friend std :: ostream& operator<<(std :: ostream& os, const Gorille& a);
};
