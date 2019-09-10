#include <string>
#include "Factory.h"
#include "CavalryFactory.h"

Factory< UnitType::Military, LandingType::Land>* getDepartment(const std::string& unitType)
{
   return unitType == "cavalry" ? new CavalryFactory() : nullptr;
}