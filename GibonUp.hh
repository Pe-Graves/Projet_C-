#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "Singes.hh"


class GibonUp : public Singes
{
public:
  GibonUp();
  ~GibonUp();

  friend std :: ostream& operator<<(std :: ostream& os, const GibonUp& a);

};
