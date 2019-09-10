#include "CavalryFactory.h"
#include "Cavalry.h"
#include "Unit.h"
#include <string>
#include <iostream>

CavalryFactory::CavalryFactory()
{
  std::cout << "CavalryFactory::CavalryFactory()" << std::endl;
}

CavalryFactory::~CavalryFactory()
{
  std::cout << "CavalryFactory::~CavalryFactory()" << std::endl;
}

Unit<UnitType::Military, LandingType::Land>* CavalryFactory::getUnit(const std::string& unitType)
{
   Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
   Cell* myCavalryCell = new Cell(Cell::Landscape::Forest);
   if (unitType == "cavalry")
   {
      unit = new Cavalry(40, 5, *myCavalryCell);
   }
   return unit;
}