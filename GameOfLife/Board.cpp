#include "Board.h"
#include "RLEDecryptor.h"
#include <random>
#include <functional>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



void Board::initBoard()
{
	this->cells.resize(this->X, std::vector<Cell>(this->Y, Cell()));
	auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
	for (int i = 0; i < this->X; ++i)
	{
		for (int j = 0; j < this->Y; ++j)
		{
			// activate random ceils (initial values)
			cells[i][j].setActive(gen());
		}
	}
}

void Board::countNeighbours()
{
	int counter;
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			counter = 0;
			if (i-1 >=0 && j-1>= 0)
				counter+= cells[i - 1][j - 1].isActive();
			else if (j == 0)
			{
				counter += cells[i][Y - 1].isActive();
				if (i - 1 >= 0)
				{
					counter += cells[i - 1][Y - 1].isActive();
				}
				if (i + 1 < X)
				{
					counter += cells[i + 1][Y - 1].isActive();
				}
			}
			if (i - 1 >= 0 && cells[i - 1][j].isActive())
				counter++;
			if (i - 1 >= 0 && j + 1 < Y)
				counter += cells[i - 1][j + 1].isActive();
			else if (j == Y - 1)
			{
				counter += cells[i][0].isActive();
				if (i - 1 >= 0)
				{
					counter += cells[i - 1][0].isActive();
				}
				if (i + 1 < X)
				{
					counter += cells[i + 1][0].isActive();
				}
			}
			if (j + 1 < Y)
				counter += cells[i][j + 1].isActive();
			if (i + 1 < X && j + 1 < Y)
				counter += cells[i + 1][j + 1].isActive();
			if (i + 1 < X)
				counter += cells[i + 1][j].isActive();
			if (i + 1 < X && j - 1 >= 0)
				counter += cells[i + 1][j - 1].isActive();
			if (j - 1 >= 0)
				counter += cells[i][j - 1].isActive();
			
			cells[i][j].setNeighbours(counter);
		}
	}
}

void Board::displayTheBoard()
{
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			if (cells[i][j].isActive())
				std::cout << "X";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void Board::letsPlayTheGame()
{
	while (true) {
		system("cls");
		displayTheBoard();
		countNeighbours();

		for (int i = 0; i < X; ++i)
		{
			for (int j = 0; j < Y; ++j)
			{
				if ((cells[i][j].isActive()) &&
					(cells[i][j].getNeighbours() < 2 || cells[i][j].getNeighbours() > 3))
				{
					cells[i][j].setActive(false);
				} 
				else if(!cells[i][j].isActive() && cells[i][j].getNeighbours() == 3)
				{
					cells[i][j].setActive(true);
				}
			}
		}
		getchar();
	}
}

void Board::loadNewBoard(std::string path)
{
	int x, y;
	std::string line;
	std::ifstream file;
	file.open(path.c_str());
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			cells[i][j].setActive(false);
		}
	}
	while (!file.eof())
	{
		file >> line;
		x = std::stoi(line);
		file >> line;
		y = std::stoi(line);
		cells[x][y].setActive(true);
		//std::cout << "x: " << x << "\ty: " << y << std::endl;
		//getchar();
	}
}

void Board::loadPatternFromFile(std::string path)
{
	/*int x = 0, y = 0;
	std::string line;
	std::ifstream file;
	std::istringstream iss;
	file.open(path.c_str());
	bool found = false;
	while (getline(file, line) && !found)
	{
		iss.str(line);
		std::size_t index = line.find("x = ");
		if (index != std::string::npos)
		{
			std::string tmp = "";
			while (line[index] != ',')
			{
				tmp += line[index];
			}
			this->X = stoi(tmp);
		}
		index = line.find("y = ");
		if (index != std::string::npos)
		{
			found = true;
			std::string tmp = "";
			while (line[index] != ',')
			{
				tmp += line[index];
			}
			this->Y = stoi(tmp);
			this->cells.resize(this->X, std::vector<Cell>(this->Y, Cell()));
		}
	}*/
	RLEDecryptor::decrypt(cells, path);
	this->X = cells.size();
	this->Y = cells[0].size();
	/*while (getline(file, line))
	{
		
	}*/
}

void Board::setCeils(int x, int startY, int endY)
{

}

Board& Board::operator=(const Board& board)
{
	if (this != &board)
	{
		// deep copy
		this->size = board.size;
		this->cells = board.cells;
	}
	return *this;
}

Board & Board::operator=(Board && board)
{
	if (this != &board)
	{
		this->size = board.size;
		this->cells = board.cells;
		board.size = 0;
		board.cells.clear();
	}
	return *this;
}

Board::Board()
{
	this->size = 100;
	this->X = this->size;
	this->Y = this->size;
/*	this->ceils.resize(this->size, std::vector<Ceil>(this->size, Ceil()));
	auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
	for (int i = 0; i < this->size; ++i)
	{
		for (int j = 0; j < this->size; ++j)
		{
			// activate random ceils (initial values)
			ceils[i][j].setActive(gen());
		}
	}*/
	initBoard();
}

Board::Board(int size)
{
	this->size = size;
	this->X = this->size;
	this->Y = this->size;
/*	this->ceils.resize(this->size, std::vector<Ceil>(this->size, Ceil()));
	auto gen = std::bind(std::uniform_int_distribution<>(0, 1), std::default_random_engine());
	for (int i = 0; i < this->size; ++i)
	{
		for (int j = 0; j < this->size; ++j)
		{
			// activate random ceils (initial values)
			ceils[i][j].setActive(gen());
		}
	}*/
	initBoard();
}

Board::Board(int x, int y)
{
	this->X = x;
	this->Y = y;
	initBoard();
}

Board::Board(const Board & board)
{
	this->size = board.size;
	this->cells = board.cells;
}

Board::Board(Board&& board): size(board.size), cells(board.cells)
{
	board.size = 0;
	board.cells.clear();
}


Board::~Board()
{
}
