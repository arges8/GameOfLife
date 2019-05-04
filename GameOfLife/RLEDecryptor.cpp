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
				std::cout << tmp << std::endl;
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
				std::cout << tmp << std::endl;
			}
			row= stoi(tmp);
			std::cout << "reading pattern from file: X: " << col << " Y: " << row << std::endl;
		}
	}
	char ch;
	cells.resize(boost::extents[row][col]);
	std::cout << "Rows: " <<cells.size() << "Columns: " << cells[0].size() << std::endl;
	int iterRow = 0;
	int iterCol = 0;
	int repeat = 1;
	std::string numberOfRepeats = "";
	while (file >> std::noskipws >> ch)
	{
		if (ch >= 48 && ch <= 57)
		{
			numberOfRepeats += ch;
			repeat = stoi(numberOfRepeats);
			std::cout << repeat << std::endl;
		}
		else if (ch == 'b')
		{
			for (int i = 0; i < repeat; ++i) {
				cells[iterRow][iterCol + i].setActive(false);
				std::cout << i << std::endl;
			}
			iterCol += repeat;
			repeat = 1;
			numberOfRepeats = "";
		}
		else if (ch == 'o')
		{
			for (int i = 0; i < repeat; ++i)
				cells[iterRow][iterCol+i].setActive(true);
			iterCol += repeat;
			repeat = 1;
			numberOfRepeats = "";
		}
		else if (ch == '$')
		{
			iterCol = 0;
			iterRow++;
		}
	}
}

RLEDecryptor::RLEDecryptor()
{
}


RLEDecryptor::~RLEDecryptor()
{
}
