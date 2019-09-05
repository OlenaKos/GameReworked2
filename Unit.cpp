#include "Unit.h"
#include "Cell.h"
#include <iostream>
#include <map>

Unit::Unit(int h, int d, Cell& c, bool isCivil, Cell::LandingType lVal) : health(h), damage(d), cell(c), isCivil(isCivil), LandingTypeValue(lVal), IsDefenced(true)
{
	std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c)" << std::endl;
}

int Unit::getHealth()
{
	std::cout << this->health << std::endl;
	return this->health;
}

bool Unit::getIsDefenced()
{
	std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;
	return this->IsDefenced;
}

Cell::Landscape Unit::getCurrentLandscape()
{
	return this->cell.LandscapeValue;
}

void Unit::attack(Unit* unit)
{
	int attackBonus = this->getAttackBonus();
	int defenceBonus = this->getDefenceBonus();
	int damage = this->damage + attackBonus - defenceBonus;
	unit->health = unit->health - damage;
	std::cout << this->getHealth() << std::endl;
	return;
}

int Unit::getAttackBonus()
{
	std::cout << "Unit::GetAttackBonus()" << std::endl;
	Cell::Landscape landScapeValue = Unit::getCurrentLandscape();
	int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;
	return attackBonus;
}

int Unit::getDefenceBonus()
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


Unit::~Unit()
{
  std::cout << "Unit::~Unit()" << std::endl;
}
