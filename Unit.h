#pragma once
#include "Cell.h"
#include <map>

enum LandingType
{
	Navy,
	Land,
	Air
};


template < bool isCivil,  class LT >
class Unit
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	   LT LandingTypeValue;
	   bool isCivil;
	   Unit(int h, int ch, Cell& c, bool isCivil, LT lVal);
       virtual ~Unit() = 0;
	   void attack(Unit* unit);
	   int getHealth();
	   Cell::Landscape getCurrentLandscape();
	   bool getIsDefenced();
	   virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;
	   virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	   int getAttackBonus();
	   int getDefenceBonus();
};


template  <>
class Unit < true, LandingType > // template specialization for civil units
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	LandingType LandingTypeValue;
	bool isCivil;
	Unit(int h, int ch, Cell& c, bool isCivil, LandingType lVal);
	virtual ~Unit() = 0;
	int getHealth();
	Cell::Landscape getCurrentLandscape();
	bool getIsDefenced();
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus();
};


template  <>
class Unit < true, LandingType > // template specialization for military units
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	LandingType LandingTypeValue;
	bool isCivil;
	Unit(int h, int ch, Cell& c, bool isCivil, LandingType lVal);
	virtual ~Unit() = 0;
	void attack(Unit* unit);
	int getHealth();
	Cell::Landscape getCurrentLandscape();
	bool getIsDefenced();
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getAttackBonus();
	int getDefenceBonus();
};

