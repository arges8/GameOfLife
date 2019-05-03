#pragma once
#include <vector>

template <class T>
using Matrix = std::vector<std::vector<T>>;

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

