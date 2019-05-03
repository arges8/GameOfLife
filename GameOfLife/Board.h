#pragma once
#include <memory>
#include <vector>
#include "Ceil.h"

template <class T>
using Matrix = std::vector<std::vector<T>>;

class Ceil;
class Board
{
	int size;
	int X;
	int Y;
	Matrix<Ceil> ceils;
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
	Board(const Board&);
	Board(Board&&);
	~Board();
};

