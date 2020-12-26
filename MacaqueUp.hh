#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Singes.hh"

class MacaqueUp : public Singes
{
public:
  MacaqueUp();
  ~MacaqueUp();

  friend std :: ostream& operator<<(std :: ostream& os, MacaqueUp& a);
};
