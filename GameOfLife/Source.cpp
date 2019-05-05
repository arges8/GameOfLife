#include "Board.h"
#include "Menu.h"

int main() {
	Board board(10);
	board.loadPatternFromFile("./data/glider.txt");
	sf::RenderWindow window(sf::VideoMode(600, 600), "Game of Life");
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased: {
				switch (event.key.code) {
				case sf::Keyboard::Left:
					menu.moveLeft();
					break;
				case sf::Keyboard::Right:
					menu.moveRight();
					break;
				case sf::Keyboard::Enter:
					menu.action(board);
					break;
				}
				break;
			}

			case sf::Event::Closed: {
				window.close();
				break;
			}
			}
		}
		window.clear(sf::Color(255,255,255));
		menu.draw(window);
		window.display();
	}
	

	
	//board.loadNewBoard("./data/activeCeils.txt");
	
	//board.letsPlayTheGame();

	system("pause");
}