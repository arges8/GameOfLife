#pragma once
class Ceil
{
	bool active;
	int neighbours;
public:
	void setNeighbours(int);
	int getNeighbours();
	void setActive(bool);
	bool isActive();
	Ceil& operator=(const Ceil&);
	Ceil& operator=(Ceil&&);
	Ceil();
	Ceil(const Ceil&);
	Ceil(Ceil&&);
	~Ceil();
};

