#pragma once

#include "Factory.h"
#include "Unit.h"
#include <string>

class CavalryFactory : public Factory <UnitType::Military, LandingType::Land>
{
   public:
      CavalryFactory();
      ~CavalryFactory();
      Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string &);

};