#pragma once
#include "TileMap.h"
#include "Board.h"

#define NUM_OF_ITEMS 4

class Menu
{
	int width;
	int height;
	static int selectedIndex;
	sf::Font font;
	sf::Text text[NUM_OF_ITEMS];
	sf::Texture textures[NUM_OF_ITEMS];
	sf::Sprite sprites[NUM_OF_ITEMS];
	
public:
	void draw(sf::RenderWindow&, Board&);
	void moveLeft();
	void moveRight();
	void action(Board &);
	static int getSelectedIndex();
	static void setSelectedIndex(int);
	void loadTextures(int, int);
	Menu(float, float);
	~Menu();
};

