#pragma once
#include "Unit.h"
#include <string>
#include <vector>

template <UnitType>
class Factory
{
   public:
	  Factory();
	  virtual ~Factory();

	  virtual Unit<UnitType, LandingType > * getUnit(const std::string&);
      
	  void addDepartment(Factory*);
   private:
      std::vector<Factory*> departments;
};


template<UnitType>
Factory<UnitType>::Factory()
{
   std::cout << "Factory::Factory()" << std::endl;
}

template<UnitType>
Factory<UnitType>::~Factory()
{
   std::cout << "Factory::~Factory()" << std::endl;
   std::for_each(departments.begin(), departments.end(), [](Factory* factory){ delete factory;} );
}

template<UnitType>
Unit<UnitType, LandingType>* Factory<UnitType>::getUnit(const std::string & unitType)
{
   Unit<UnitType::Civil, LandingType>* unit = nullptr;
   std::vector<Factory*>::iterator iter = departments.begin();
   while( unit == nullptr && iter != departments.end()  )
   {
      unit = (*iter)->getUnit(unitType);
      ++iter;
   }
   return unit;
}

template<UnitType>
void Factory<UnitType>::addDepartment(Factory* factory)
{
   departments.push_back(factory);
   return;
}


