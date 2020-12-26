#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Macaque.hh"

class MacaqueUp : public Macaque
{
public:
  MacaqueUp();
  ~MacaqueUp();

  friend std :: ostream& operator<<(std :: ostream& os, MacaqueUp& a);
};
