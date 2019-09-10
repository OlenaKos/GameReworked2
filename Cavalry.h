#pragma once
#include<map>
#include<string>
#include "Cell.h"
#include "Unit.h"

class Cavalry : public Unit <UnitType::Military, LandingType::Land >
{
private:
	static std::map <Cell::Landscape, int> AttackBonusMap;
	static std::map <Cell::Landscape, int> DefenceBonusMap;

public:
	 Cavalry(int h, int ch, Cell& c);
     virtual ~Cavalry();
	 virtual std::map<Cell::Landscape, int> getAttackBonusMap();
	 virtual std::map<Cell::Landscape, int> getDefenceBonusMap();
};