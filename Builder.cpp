//#include "Builder.h"
//#include "Cell.h"
//#include "Unit.h"
//#include <iostream>
//#include <map>
//
//std::map <Cell::Landscape, int> Builder::AttackBonusMap = {
//
//		{ Cell::Landscape::Water, -2 },
//		{ Cell::Landscape::Grass, 10 },
//		{ Cell::Landscape::Sand, 7 },
//		{ Cell::Landscape::Soil, 10 },
//		{ Cell::Landscape::Marsh, 5 },
//		{ Cell::Landscape::Forest, 7 },
//};
//
//std::map < Cell::Landscape, int> Builder::DefenceBonusMap = {
//		{ Cell::Landscape::Water, 2 },
//		{ Cell::Landscape::Grass, 1 },
//		{ Cell::Landscape::Sand, 3 },
//		{ Cell::Landscape::Soil, 3 },
//		{ Cell::Landscape::Marsh, 1 },
//		{ Cell::Landscape::Forest, 5}
//};
//
//Builder::Builder(int h, int d, Cell& c) : Unit(h, d, c)
//{
//	std::cout << "Builder(int h, damage d, Cell& c) : health (h), damage(d), cell(c)" << std::endl;
//}
//
//std::map<Cell::Landscape, int> Builder::getAttackBonusMap()
//{
//	return this->AttackBonusMap;
//}
//
//std::map<Cell::Landscape, int> Builder::getDefenceBonusMap()
//{
//	return this->DefenceBonusMap;
//}
//
//
//Builder::~Builder()
//{
//	std::cout << "Builder::~Builder()" << std::endl;
//}