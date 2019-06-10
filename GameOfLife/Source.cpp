//#include "Board.h"
#include "Menu.h"
#include <TGUI/TGUI.hpp>

int main() {
	Board board(10);
	board.loadPatternFromFile("./data/copperhead.txt");
	int iterator = 0;
	sf::RenderWindow window(sf::VideoMode(1200, 750), "Game of Life");
	tgui::Gui gui(window);
	auto patterns = tgui::ComboBox::create();
	patterns->setPosition(1010, 20);
	patterns->setSize(180, 21);
	patterns->addItem("Glider");
	patterns->addItem("Copperhead");
	patterns->addItem("Gosper Glider Gun");
	patterns->addItem("Queen Bee Shuttle");
	patterns->setSelectedItemByIndex(2);
	patterns->moveToFront();
	gui.add(patterns);
	Menu menu(window.getSize().x, window.getSize().y);
	bool playSimulation = false;

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
					switch (Menu::getSelectedIndex()) {
					case 0: {
						playSimulation = !playSimulation;
						break;
					}
					case 1: {
						switch (patterns->getSelectedItemIndex()) {
						case 0: {
							board.loadPatternFromFile("./data/glider.txt");
							break;
						}
						case 1: {
							board.loadPatternFromFile("./data/copperhead.txt");
							break;
						}
						case 2: {
							board.loadPatternFromFile("./data/gliderGun.txt");
							break;
						}
						case 3: {
							board.loadPatternFromFile("./data/queenBeeShuttle.txt");
							break;
						}
						default:
							break;
						}
						break;
					}
					case 2: {
						board.previousStep();
						break;
					}
					case 3: {
						board.nextStep();
						break;
					}
					default: {
						break;
					}
					}
					break;
				}
				break;
			}

			case sf::Event::Closed: {
				window.close();
				break;
			}
			case sf::Event::Resized: {
				window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width), 
					static_cast<float>(event.size.height))));
				//menu.loadTextures(event.size.width, event.size.height);
				gui.setView(window.getView());
			}
			default: {
				break;
			}
			}
			gui.handleEvent(event);
		}
		if (playSimulation) {
			board.nextStep();
		}
		window.clear(sf::Color(255,255,255));
		gui.draw();
		menu.draw(window, board);
		window.display();
	}


	system("pause");
}