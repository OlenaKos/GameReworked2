//#include <iostream>
//#include "Infantry.h"
//#include <map>
//#include "Cell.h"
//
//std::map <Cell::Landscape, int> AttackBonusMap =
//{
//		{ Cell::Landscape::Water, -1 },
//		{ Cell::Landscape::Grass, 11 },
//		{ Cell::Landscape::Sand, 8 },
//		{ Cell::Landscape::Soil, 11 },
//		{ Cell::Landscape::Marsh, 6 },
//		{ Cell::Landscape::Forest, 8 },
//
//};
//
//std::map <Cell::Landscape, int> DefenceBonusMap =
//{
//		{ Cell::Landscape::Water, 3 },
//		{ Cell::Landscape::Grass, 2 },
//		{ Cell::Landscape::Sand, 4 },
//		{ Cell::Landscape::Soil, 4 },
//		{ Cell::Landscape::Marsh, 2 },
//		{ Cell::Landscape::Forest, 6 }
//};
//Infantry::Infantry(int h, int d, Cell& cell) : LandUnit(h, d, cell)
//{
//	std::cout << "Infantry::Infantry()" << std::endl;
//};
//
//Infantry::~Infantry()
//{
//	std::cout << "Infantry::~Infantry()" << std::endl;
//};
//
//std::map<Cell::Landscape, int> Infantry::getAttackBonusMap()
//{
//	std::cout << "Infantry::getAttackBonusMap()" << std::endl;
//	return this->AttackBonusMap;
//};
//
//std::map<Cell::Landscape, int> Infantry::getDefenceBonusMap()
//{
//	std::cout << "Infantry::getDefenceBonusMap()" << std::endl;
//	return this->DefenceBonusMap;
//};