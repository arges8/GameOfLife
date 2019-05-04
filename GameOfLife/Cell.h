#pragma once
#pragma warning(disable : 4996)
#include "boost/multi_array.hpp"
#include <cassert>
#include <vector>

class Cell;
typedef boost::multi_array<Cell, 2> matrix;
typedef matrix::index index;

class Cell
{
	bool active;
	int neighbours;
public:
	void setNeighbours(int);
	int getNeighbours();
	void setActive(bool);
	bool isActive();
	Cell& operator=(const Cell&);
	Cell& operator=(Cell&&);
	Cell();
	Cell(const Cell&);
	Cell(Cell&&);
	~Cell();
};

