#pragma once
#include "SFML/Graphics.hpp"
#include "Board.h"

#define NUM_OF_ITEMS 4

class Menu
{
	int selectedIndex;
	sf::Font font;
	sf::Text text[NUM_OF_ITEMS];
	sf::Texture textures[NUM_OF_ITEMS];
	sf::Sprite sprites[NUM_OF_ITEMS];
public:
	void draw(sf::RenderWindow&);
	void moveLeft();
	void moveRight();
	void action(Board &);
	Menu(float, float);
	~Menu();
};

