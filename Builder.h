#pragma once
#include "Unit.h"

class Builder : public Unit <true, Land>
{
private:
	static std::map <Cell::Landscape, int> DefenceBonusMap;

public:
	Builder(int h, int ch, Cell& c);
	~Builder();
	Factory * factory build(std::string const);
	virtual std::map<Cell::Landscape, int> getDefenceBonusMap();
};