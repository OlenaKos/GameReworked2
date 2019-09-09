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
	   Unit(int h, int ch, Cell& c);
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
	Unit(int h, int ch, Cell& c);
	virtual ~Unit() = 0;
	int getHealth();
	Cell::Landscape getCurrentLandscape();
	bool getIsDefenced();
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus();
};


template  <>
class Unit < false, LandingType > // template specialization for military units
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	LandingType LandingTypeValue;
	bool isCivil;
	Unit(int h, int ch, Cell& c);
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

template < bool isCivil, class LT >
Unit < isCivil, LT > :: Unit  (int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)
{
	std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;
}

//template < true, class LT >
//Unit < true, LT > ::Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)
//{
//	std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;
//}
//
//template < false, class LT >
//Unit < false, LT > ::Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)
//{
//	std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;
//}


template < bool isCivil, class LT >
int Unit < isCivil, LT > ::getHealth()
{
	std::cout << this->health << std::endl;
	return this->health;
}

template < bool isCivil, class LT >
bool Unit < isCivil, LT > ::getIsDefenced()
{
	std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;
	return this->IsDefenced;
}

template < bool isCivil, class LT >
Cell::Landscape Unit < isCivil, LT >::getCurrentLandscape()
{
	return this->cell.LandscapeValue;
}

template < bool isCivil, class LT >
void Unit < isCivil, LT > ::attack(Unit* unit)
{
	int attackBonus = this->getAttackBonus();
	int defenceBonus = this->getDefenceBonus();
	int damage = this->damage + attackBonus - defenceBonus;
	unit->health = unit->health - damage;
	std::cout << this->getHealth() << std::endl;
	return;
}

template < bool isCivil, class LT >
int Unit < isCivil, LT > ::getAttackBonus()
{
	std::cout << "Unit::GetAttackBonus()" << std::endl;
	Cell::Landscape landScapeValue = Unit::getCurrentLandscape();
	int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;
	return attackBonus;
}

template < bool isCivil, class LT >
int Unit < isCivil, LT > ::getDefenceBonus()
{
	std::cout << "Unit::GetDefenceBonus()" << std::endl;
	Cell::Landscape landScapeValue = Unit::getCurrentLandscape();
	bool isDefenced = Unit::getIsDefenced();
	int defenceBonus;

	if (isDefenced)
	{
		defenceBonus = this->getDefenceBonusMap().find(landScapeValue)->second;
	}
	else
	{
		defenceBonus = 0;
	}

	return defenceBonus;
}

template < bool isCivil, class LT >
Unit < isCivil, LT > ::~Unit()
{
	std::cout << "Unit::~Unit()" << std::endl;
}
