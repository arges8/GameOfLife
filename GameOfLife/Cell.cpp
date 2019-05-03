#include "Cell.h"



void Cell::setNeighbours(int nei)
{
	neighbours = nei;
}

int Cell::getNeighbours()
{
	return neighbours;
}

void Cell::setActive(bool activate)
{
	this->active = activate;
}

bool Cell::isActive()
{
	return active;
}

Cell& Cell::operator=(const Cell& ceil)
{
	if (this != &ceil)
	{
		active = ceil.active;
		neighbours = ceil.neighbours;
	}
	return *this;
}

Cell& Cell::operator=(Cell&& ceil)
{
	if (this != &ceil)
	{
		active = ceil.active;
		neighbours = ceil.neighbours;
		ceil.active = false;
		ceil.neighbours = 0;
	}
	return *this;
}

Cell::Cell()
{
}

Cell::Cell(const Cell& ceil)
{
	active = ceil.active;
	neighbours = ceil.neighbours;
}

Cell::Cell(Cell && ceil): active(ceil.active), neighbours(ceil.neighbours)
{
	ceil.active = false;
	ceil.neighbours = 0;
}


Cell::~Cell()
{
}
