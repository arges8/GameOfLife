#include "Menu.h"
#include <Windows.h>
//#include "boost/thread.hpp"

void Menu::draw(sf::RenderWindow& window, Board& board)
{
	for (int i = 0; i < NUM_OF_ITEMS; ++i)
	{
		window.draw(sprites[i]);
	}
	int pix = 7;
	int noOfRows = width / pix;
	int noOfCols = height / pix;
	TileMap map;
	map.load(sf::Vector2f(pix, pix), board.cells,noOfRows, noOfCols);
	map.setPosition(10, 10);
	window.draw(map);
}

void Menu::moveLeft()
{
	if (selectedIndex - 1 >= 0) {
		sprites[selectedIndex].setColor(sf::Color(255, 255, 255));
		sprites[selectedIndex-1].setColor(sf::Color(0, 255, 0, 128));
		selectedIndex--;
	}
	else {
		sprites[selectedIndex].setColor(sf::Color(255, 255, 255));
		sprites[NUM_OF_ITEMS-1].setColor(sf::Color(0, 255, 0, 128));
		selectedIndex = NUM_OF_ITEMS - 1;
	}
}

void Menu::moveRight()
{
	if (selectedIndex + 1 < NUM_OF_ITEMS) {
		sprites[selectedIndex].setColor(sf::Color(255, 255, 255));
		sprites[selectedIndex + 1].setColor(sf::Color(0, 255, 0, 128));
		selectedIndex++;
	}
	else {
		sprites[selectedIndex].setColor(sf::Color(255, 255, 255));
		sprites[0].setColor(sf::Color(0, 255, 0, 128));
		selectedIndex = 0;
	}
}

void Menu::action(Board& board)
{
	//boost::thread t(boost::bind(&Board::letsPlayTheGame, &board));
	while (selectedIndex == 0)
	{
		board.letsPlayTheGame();
		//Sleep(500);
	}
	if (selectedIndex == 1)
	{
		system("cls");
		board.loadPatternFromFile("./data/glider.txt");
	}
	if (selectedIndex == 3)
	{
		board.letsPlayTheGame();
	}
}

Menu::Menu(float width, float height)
{
	textures[0].loadFromFile("./images/play.png");
	sprites[0].setTexture(textures[0]);
	sprites[0].setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprites[0].setPosition(width/(NUM_OF_ITEMS+1), (height/10) * 9 );
	sprites[0].setColor(sf::Color(0,255,0,128));

	textures[1].loadFromFile("./images/stop.png");
	sprites[1].setTexture(textures[1]);
	sprites[1].setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprites[1].setPosition((width / (NUM_OF_ITEMS+1)) * 2, (height / 10) * 9);

	textures[2].loadFromFile("./images/back.png");
	sprites[2].setTexture(textures[2]);
	sprites[2].setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprites[2].setPosition((width / (NUM_OF_ITEMS+1)) * 3, (height / 10) * 9);

	textures[3].loadFromFile("./images/next.png");
	sprites[3].setTexture(textures[3]);
	sprites[3].setTextureRect(sf::IntRect(0, 0, 50, 50));
	sprites[3].setPosition((width / (NUM_OF_ITEMS + 1)) * 4, (height / 10) * 9);
	
	selectedIndex = 0;
	this->width = (int)width - 20;
	this->height = (int)(height*0.9 - 20);
}

Menu::~Menu()
{
}
