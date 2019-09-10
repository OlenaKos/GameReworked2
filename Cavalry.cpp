#include "Cavalry.h"
#include "Cell.h"
#include <iostream>
#include <map>

std::map <Cell::Landscape, int> Cavalry::AttackBonusMap = {
		{ Cell::Landscape::Water, -2 },
		{ Cell::Landscape::Grass, 10 },
		{ Cell::Landscape::Sand, 7 },
		{ Cell::Landscape::Soil, 10 },
		{ Cell::Landscape::Marsh, 5 },
		{ Cell::Landscape::Forest, 7 },
};

std::map < Cell::Landscape, int> Cavalry::DefenceBonusMap = {
		{ Cell::Landscape::Water, 2 },
		{ Cell::Landscape::Grass, 1 },
		{ Cell::Landscape::Sand, 3 },
		{ Cell::Landscape::Soil, 3 },
		{ Cell::Landscape::Marsh, 1 },
		{ Cell::Landscape::Forest, 5}
};

Cavalry::Cavalry(int h, int d, Cell& c) : Unit<UnitType::Military, LandingType>(h,d,c)
{
   std::cout << "Cavalry(int h, damage d, Cell& c) : health (h), damage(d), cell(c)" << std::endl;
}

std::map<Cell::Landscape, int> Cavalry::getAttackBonusMap()
{
	return this->AttackBonusMap;
}

std::map<Cell::Landscape, int> Cavalry::getDefenceBonusMap()
{
	return this->DefenceBonusMap;
}


Cavalry::~Cavalry()
{
   std::cout << "Cavalry::~Cavalry()" << std::endl;
}