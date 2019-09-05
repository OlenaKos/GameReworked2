//#include "Factory.h"
//#include "LandFactory.h"
//#include "LandUnit.h"
//#include "MilitaryUnit.h"
//#include "Cavalry.h"
//#include "Infantry.h"
//#include "Unit.h"
//#include <string>
//#include <iostream>
//
//LandFactory::LandFactory()
//{
//	std::cout << "LandFactory::LandFactory()" << std::endl;
//}
//
//LandFactory::~LandFactory()
//{
//	std::cout << "LandFactory::~LandFactory()" << std::endl;
//}
//
//Unit* LandFactory::getUnit(const std::string& unitType)
//{
//	LandUnit* unit = nullptr;
//	Cell* myCell = new Cell(Cell::Landscape::Forest);
//	if (unitType == "cavalry")
//	{
//		unit = new Cavalry(40, 5, *myCell);
//	}
//	if (unitType == "infantry")
//	{
//		unit = new Infantry(40, 5, *myCell);
//	}
//	return unit;
//}