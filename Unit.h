#pragma once
#include "Cell.h"
#include <map>

enum LandingType
{
	Navy,
	Land,
	Air
};
enum UnitType
{
	Civil,
	Military
};

template < UnitType,  LandingType >
class Unit
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	   Unit < UnitType, LandingType > (int h, int ch, Cell& c);
       virtual ~Unit() = 0;
	   int getHealth();
	   Cell::Landscape getCurrentLandscape();
	   bool getIsDefenced();
	   virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	   int getDefenceBonus();
};

template  <LandingType>
class Unit < UnitType::Civil, LandingType > // template specialization for civil units
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
	bool isCivil;
	Unit(int h, int ch, Cell& c);
	virtual ~Unit() = 0;
	int getHealth();
	Cell::Landscape getCurrentLandscape();
	bool getIsDefenced();
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus();
};

template  <LandingType>
class Unit < UnitType::Military, LandingType > // template specialization for military units
{
private:
	int health;
	int damage;
	Cell& cell;
	bool IsDefenced;

public:
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

//constructor
template < UnitType,  LandingType >
Unit < UnitType, LandingType > :: Unit  (int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)
{
	std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;
}

//common
template < UnitType,  LandingType >
int Unit < UnitType,  LandingType > ::getHealth()
{
	std::cout << this->health << std::endl;
	return this->health;
}

template < UnitType,  LandingType  >
bool Unit < UnitType,  LandingType  > ::getIsDefenced()
{
	std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;
	return this->IsDefenced;
}

template < UnitType,  LandingType  >
int Unit < UnitType,  LandingType  > ::getDefenceBonus()
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

template < UnitType,  LandingType  >
Cell::Landscape Unit < UnitType,  LandingType  >::getCurrentLandscape()
{
	return this->cell.LandscapeValue;
}

//military
template < LandingType  >
void Unit < UnitType::Military, LandingType > ::attack(Unit* unit)
{
	int attackBonus = this->getAttackBonus();
	int defenceBonus = this->getDefenceBonus();
	int damage = this->damage + attackBonus - defenceBonus;
	unit->health = unit->health - damage;
	std::cout << this->getHealth() << std::endl;
	return;
}

template < LandingType >
int Unit < UnitType::Military, LandingType > ::getAttackBonus()
{
	std::cout << "Unit::GetAttackBonus()" << std::endl;
	Cell::Landscape landScapeValue = Unit::getCurrentLandscape();
	int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;
	return attackBonus;
}


