#pragma once
#include <memory>
#include "Cell.h"

class Cell;
class RLEDecryptor;
class Board
{
	int size;
	int X;
	int Y;
	Matrix<Cell> cells;
	friend class RLEDecryptor;
public:
	void initBoard();
	void countNeighbours();
	void displayTheBoard();
	void letsPlayTheGame();
	void loadNewBoard(std::string);
	void loadPatternFromFile(std::string);
	void setCeils(int, int, int);
	Board& operator=(const Board&);
	Board& operator=(Board&&);
	Board();
	Board(int);
	Board(int, int);
	Board(const Board&);
	Board(Board&&);
	~Board();
};

