#include "Game.h"
#include "games/Pong/Pong.h"
#include "games/ObstacleCourse/ObstacleCourse.h"
int main() {
	int choice;
	std::cout << "There are two games in this game collection.\nPick 0 to play Pong against the computer.\nPick 1 to play a single-player Obstacle Course game.\nPick 2 to quit.\n";
	std::cout << "Choice: ";
	std::cin >> choice;
	std::cout << "\n";
	if (choice == 0) {
		Pong game;
		game.Run();
	} else if (choice == 1) {
		ObstacleCourse game;
		game.Run();
	} else if (choice == 2) {
		std::cout << "Thank you for running this program. Goodbye!\n";
	}
	return 0;
}
