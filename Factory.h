#pragma once
#include "Unit.h"
#include <string>
#include <vector>
#include <algorithm>


template  <UnitType, LandingType>
class Factory
{
   public:
	  Factory()
	  {
		  std::cout << "Factory::Factory()" << std::endl;
	  }
      virtual ~Factory()
	  {
		  std::cout << "Factory::~Factory()" << std::endl;
		  std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
	  }

	  virtual Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string& unitType)
	  {
		  Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
		  std::vector<Factory*>::iterator iter = departments.begin();
		  while (unit == nullptr && iter != departments.end())
		  {
			  unit = (*iter)->getUnit(unitType);
			  ++iter;
		  }
		  return unit;
	  }
      
	  void addDepartment(Factory* factory)
	  {
		  departments.push_back(factory);
		  return;
	  }
   private:
      std::vector<Factory*> departments;
};

template <>
class Factory < UnitType::Civil, LandingType::Land > //specialization of template for the Civil - Land units
{
public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}
	virtual ~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
	}

	virtual Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string& unitType)
	{
		Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
		std::vector<Factory*>::iterator iter = departments.begin();
		while (unit == nullptr && iter != departments.end())
		{
			unit = (*iter)->getUnit(unitType);
			++iter;
		}
		return unit;
	}

	void addDepartment(Factory* factory)
	{
		departments.push_back(factory);
		return;
	}
private:
	std::vector<Factory*> departments;


};

template <>
class Factory < UnitType::Military, LandingType::Land > //specialization of template for the Military-land units
{

public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}
	virtual ~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
	}

	virtual Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string& unitType)
	{
		Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
		std::vector<Factory*>::iterator iter = departments.begin();
		while (unit == nullptr && iter != departments.end())
		{
			unit = (*iter)->getUnit(unitType);
			++iter;
		}
		return unit;
	}

	void addDepartment(Factory* factory)
	{
		departments.push_back(factory);
		return;
	}
private:
	std::vector<Factory*> departments;
};

template <>
class Factory < UnitType::Military, LandingType::Air >  //specializion of template for the Military Air units
{
public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}
	virtual ~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
	}

	virtual Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string& unitType)
	{
		Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
		std::vector<Factory*>::iterator iter = departments.begin();
		while (unit == nullptr && iter != departments.end())
		{
			unit = (*iter)->getUnit(unitType);
			++iter;
		}
		return unit;
	}

	void addDepartment(Factory* factory)
	{
		departments.push_back(factory);
		return;
	}
private:
	std::vector<Factory*> departments;
};

template <>
class Factory <UnitType::Military, LandingType::Navy> //specialization of template  for the Military Navy units
{
public:
	Factory()
	{
		std::cout << "Factory::Factory()" << std::endl;
	}
	virtual ~Factory()
	{
		std::cout << "Factory::~Factory()" << std::endl;
		std::for_each(departments.begin(), departments.end(), [](Factory* factory) { delete factory; });
	}

	virtual Unit<UnitType::Military, LandingType::Land>* getUnit(const std::string& unitType)
	{
		Unit<UnitType::Military, LandingType::Land>* unit = nullptr;
		std::vector<Factory*>::iterator iter = departments.begin();
		while (unit == nullptr && iter != departments.end())
		{
			unit = (*iter)->getUnit(unitType);
			++iter;
		}
		return unit;
	}

	void addDepartment(Factory* factory)
	{
		departments.push_back(factory);
		return;
	}
private:
	std::vector<Factory*> departments;

};
