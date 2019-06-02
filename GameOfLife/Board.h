#pragma once
#include <memory>
#include "Cell.h"

class Menu;
class Cell;
class Board
{
	int size;
	int X;
	int Y;
	matrix cells;
	friend class Menu;
public:
	void initBoard();
	void countNeighbours();
	void displayTheBoard();
	void letsPlayTheGame();
	void loadNewBoard(std::string);
	void loadPatternFromFile(std::string);
	void setCeils(int, int, int);
	void setXandY(int, int);
	matrix getCells();
	Board& operator=(const Board&);
	Board& operator=(Board&&);
	Board();
	Board(int);
	Board(int, int);
	Board(const Board&);
	Board(Board&&);
	~Board();
};

