#include "Factory.h"
#include "Unit.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

Factory::Factory()
{
   std::cout << "Factory::Factory()" << std::endl;
}

Factory::~Factory()
{
   std::cout << "Factory::~Factory()" << std::endl;
   std::for_each(departments.begin(), departments.end(), [](Factory* factory){ delete factory;} );
}

Unit<bool, LandingType>* Factory::getUnit(const std::string & unitType)
{
   Unit<true, LandingType>* unit = nullptr;
   std::vector<Factory*>::iterator iter = departments.begin();
   while( unit == nullptr && iter != departments.end()  )
   {
      unit = (*iter)->getUnit(unitType);
      ++iter;
   }
   return unit;
}

void Factory::addDepartment(Factory* factory)
{
   departments.push_back(factory);
   return;
}

