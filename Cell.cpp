
#include <iostream>
#include "Cell.h"

Cell::Cell ()
{
	std::cout << "Cell::Cell()" << std::endl;
};

Cell::Cell(Cell::Landscape land) : LandscapeValue(land)
{
	this->LandscapeValue = land;
	std::cout << "Cell::Cell()" << std::endl;
};

int Cell::getX()
{
	std::cout << "Cell::getX" << this->x << std::endl;
	return this->x;
}

int Cell::getY()
{
	std::cout << "Cell::getY" << this->y << std::endl;
	return this->y;
}

void Cell::setX(int x)
{
	std::cout << "Cell::setX" << this->x << std::endl;
	this->x = x;
}

void Cell::setY(int y)
{
	std::cout << "Cell::setY" << this->y << std::endl;
	this->y = y;
}

Cell::Landscape Cell::getLandscape()
{
	std::cout << "this -> LandscapeValue " << this->LandscapeValue << std::endl;
	return this->LandscapeValue;
}

Cell::~Cell()
{
	std::cout << "Cell::~Cell()" << std::endl;
}