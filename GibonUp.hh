#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Gibon.hh"


class GibonUp : public virtual Gibon
{
public:
  GibonUp();
  ~GibonUp();

  friend std :: ostream& operator<<(std :: ostream& os, const GibonUp& a);

};
