#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

#include "Singes.hh"

class Macaque : public Singes
{
public:
  Macaque();
  ~Macaque();

  friend std :: ostream& operator<<(std :: ostream& os, Macaque& a);
};
