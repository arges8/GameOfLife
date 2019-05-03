#include "Board.h"

int main() {
	
	Board board(10);
	board.loadNewBoard("./data/activeCeils.txt");
	board.letsPlayTheGame();

	system("pause");
}