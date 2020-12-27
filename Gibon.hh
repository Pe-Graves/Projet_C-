#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Singes.hh"


class Gibon : public virtual Singes
{
public:
  Gibon();
  ~Gibon();

  friend std :: ostream& operator<<(std :: ostream& os, const Gibon& a);

};
