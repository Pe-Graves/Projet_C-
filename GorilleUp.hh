#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Singes.hh"

class GorilleUp : public Singes
{
public:
  GorilleUp();
  ~GorilleUp();

  int combat(GorilleUp& adversaire);
  int soin();

  friend std :: ostream& operator<<(std :: ostream& os, const GorilleUp& a);
};
