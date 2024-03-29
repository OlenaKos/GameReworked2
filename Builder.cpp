#include "Builder.h"
#include "Cell.h"
#include "Unit.h"
#include <iostream>
#include <map>

std::map < Cell::Landscape, int> Builder::DefenceBonusMap = {
		{ Cell::Landscape::Water, 2 },
		{ Cell::Landscape::Grass, 1 },
		{ Cell::Landscape::Sand, 3 },
		{ Cell::Landscape::Soil, 3 },
		{ Cell::Landscape::Marsh, 1 },
		{ Cell::Landscape::Forest, 5}
};

Builder::Builder(int h, int d, Cell& c) : Unit <UnitType::Civil, LandingType::Land> ( h, d, c)
{
	std::cout << "Builder(int h, damage d, Cell& c) : health (h), damage(d), cell(c)" << std::endl;
}

std::map<Cell::Landscape, int> Builder::getDefenceBonusMap()
{
	return this->DefenceBonusMap;
}

Builder::~Builder()
{
	std::cout << "Builder::~Builder()" << std::endl;
}