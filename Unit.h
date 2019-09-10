#pragma once
#include "Cell.h"
#include <map>
#include <iostream>



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

template <UnitType, LandingType >

class Unit

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;



public:

	Unit(int h, int ch, Cell& c);

	virtual ~Unit() 
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	int getHealth();

	Cell::Landscape getCurrentLandscape();

	bool getIsDefenced();

	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;

	int getDefenceBonus();

};


template  < >
class Unit < UnitType::Civil, LandingType::Land > // template specialization for civil units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;



public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

	{

		std::cout<< "Unit::GetDefenceBonus()" << std::endl;

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

};

template  <>
class Unit < UnitType::Military, LandingType::Air > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;



public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

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

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};

template  <>
class Unit < UnitType::Military, LandingType::Land > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;



public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

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

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};

template  <>
class Unit < UnitType::Military, LandingType::Navy > // template specialization for military units

{

private:

	int health;

	int damage;

	Cell& cell;

	bool IsDefenced;



public:

	//Constructor
	Unit(int h, int d, Cell& c) : health(h), damage(d), cell(c), IsDefenced(true)

	{

		std::cout << "Unit(int h, int d, cell& c) : health(h), damage(d), cell(c) isCivil(isCivil)  LandingTypeValue(lVal), IsDefenced(true) " << std::endl;

	}
	//Destructor
	virtual ~Unit()
	{

		std::cout << "Unit::~Unit()" << std::endl;

	}

	//Common functions
	int getHealth()
	{
		std::cout << this->health << std::endl;
		return this->health;
	}
	bool getIsDefenced()

	{

		std::cout << "this->IsDefenced = " << this->IsDefenced << std::endl;

		return this->IsDefenced;

	}
	Cell::Landscape getCurrentLandscape()
	{

		return this->cell.LandscapeValue;

	}
	virtual std::map <Cell::Landscape, int> getDefenceBonusMap() = 0;
	int getDefenceBonus()

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

	//military
	void attack(Unit* unit)
	{

		int attackBonus = this->getAttackBonus();

		int defenceBonus = this->getDefenceBonus();

		int damage = this->damage + attackBonus - defenceBonus;

		unit->health = unit->health - damage;

		std::cout << this->getHealth() << std::endl;

		return;

	}
	int getAttackBonus()
	{
		std::cout << "Unit::GetAttackBonus()" << std::endl;

		Cell::Landscape landScapeValue = Unit::getCurrentLandscape();

		int attackBonus = this->getAttackBonusMap().find(landScapeValue)->second;

		return attackBonus;
	}
	virtual std::map <Cell::Landscape, int> getAttackBonusMap() = 0;

};



