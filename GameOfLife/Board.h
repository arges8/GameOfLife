#pragma once
#include <memory>
#include "Cell.h"
#include <vector>

class Menu;
class Cell;
class Board
{
	int iterator;
	int size;
	int X;
	int Y;
	matrix cells;
	std::vector<matrix> matrixBackup;
	friend class Menu;
public:
	void initBoard();
	void countNeighbours();
	void displayTheBoard();
	void letsPlayTheGame();
	void loadNewBoard(std::string);
	void loadPatternFromFile(std::string);
	void setXandY(int, int);
	void nextStep();
	void previousStep();
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

