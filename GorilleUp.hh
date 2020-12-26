#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Gorille.hh"

class GorilleUp : public Gorille
{
public:
  GorilleUp();
  ~GorilleUp();

  int combat(GorilleUp& adversaire);
  int soin();

  friend std :: ostream& operator<<(std :: ostream& os, const GorilleUp& a);
};
