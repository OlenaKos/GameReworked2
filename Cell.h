#pragma once

class Cell
{
private :
	int x;
	int y;
public:
	enum Landscape
	{
		Water,
		Grass,
		Sand,
		Soil,
		Marsh,
		Forest
	};

	Landscape LandscapeValue;
public:
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Cell();
	Cell(Cell::Landscape land);
	~Cell();
	Cell::Landscape getLandscape();

};
