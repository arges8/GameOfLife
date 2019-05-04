#include "Board.h"

int main() {
	
	Board board(10);
	//board.loadNewBoard("./data/activeCeils.txt");
	board.loadPatternFromFile("./data/testPattern.txt");
	board.letsPlayTheGame();

	system("pause");
}