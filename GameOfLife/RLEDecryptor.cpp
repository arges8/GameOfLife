#include "RLEDecryptor.h"
#include <fstream>
#include <sstream>
#include <iostream>


void RLEDecryptor::decrypt(matrix& cells, std::string path)
{
	int col = 0, row = 0;
	std::string line;
	std::ifstream file;
	std::istringstream iss;
	file.open(path.c_str());
	bool found = false;
	// Find x and y
	while (!found && getline(file, line))
	{
		iss.str(line);
		std::size_t index = line.find("x = ") + 4;
		if (index != std::string::npos)
		{
			std::string tmp = "";
			while (line[index] != ',')
			{
				tmp += line[index];
				index++;
			}
			col = stoi(tmp);
		}
		index = line.find("y = ") + 4;
		if (index != std::string::npos)
		{
			found = true;
			std::string tmp = "";
			while (index != line.size())
			{
				tmp += line[index];
				index++;
			}
			row = stoi(tmp);
		}
	}

	int margin = 0;
	cells.resize(boost::extents[row + margin][col + margin]);
	
	for (int i = 0; i < row + margin; ++i)
	{
		for (int j = 0; j < col + margin; ++j)
		{
			cells[i][j].setActive(false);
		}
	}

	int iterRow = 0;
	int iterCol = 0;
	int sum = 0;
	int repeat = 1;
	std::string numberOfRepeats = "";
	char ch;
	while (file >> std::noskipws >> ch)
	{
		// Check if char is a number
		if (ch >= 48 && ch <= 57)
		{
			numberOfRepeats += ch;
			repeat = stoi(numberOfRepeats);
		}
		// Check if cell is dead
		else if (ch == 'b')
		{
			for (int i = 0; i < repeat; ++i)
				cells[iterRow + margin][iterCol + margin + i].setActive(false);
			iterCol += repeat;
			repeat = 1;
			numberOfRepeats = "";
		}
		// Check if cell is alive
		else if (ch == 'o')
		{
			for (int i = 0; i < repeat; ++i)
				cells[iterRow + margin][iterCol + margin + i].setActive(true);
			iterCol += repeat;
			repeat = 1;
			numberOfRepeats = "";
		}
		// Check if it's end of line
		else if (ch == '$')
		{
			iterRow += repeat;
			repeat = 1;
			numberOfRepeats = "";
			iterCol = 0;
		}
		// Check if it's end of the file
		else if (ch == '!')
		{
			break;
		}
	}
}

RLEDecryptor::RLEDecryptor()
{
}


RLEDecryptor::~RLEDecryptor()
{
}
