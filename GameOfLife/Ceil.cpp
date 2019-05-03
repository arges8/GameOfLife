#include "Ceil.h"



void Ceil::setNeighbours(int nei)
{
	neighbours = nei;
}

int Ceil::getNeighbours()
{
	return neighbours;
}

void Ceil::setActive(bool activate)
{
	this->active = activate;
}

bool Ceil::isActive()
{
	return active;
}

Ceil& Ceil::operator=(const Ceil& ceil)
{
	if (this != &ceil)
	{
		active = ceil.active;
		neighbours = ceil.neighbours;
	}
	return *this;
}

Ceil& Ceil::operator=(Ceil&& ceil)
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

Ceil::Ceil()
{
}

Ceil::Ceil(const Ceil& ceil)
{
	active = ceil.active;
	neighbours = ceil.neighbours;
}

Ceil::Ceil(Ceil && ceil): active(ceil.active), neighbours(ceil.neighbours)
{
	ceil.active = false;
	ceil.neighbours = 0;
}


Ceil::~Ceil()
{
}
