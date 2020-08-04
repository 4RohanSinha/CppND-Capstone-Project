#include "games/Pong/Pong.h"
#include "games/ObstacleCourse/ObstacleCourse.h"

int main() {
	std::cout << "C++ Nanodegree Program - Capstone Project\n-----------------------------------------\n";
	int choice;
	while (choice != 2) {
		choice = 2;
		std::cout << "\nThere are two games in this game collection.\n\nPick 0 to play Pong against the computer.\nPick 1 to play a single-player Obstacle Course game.\nPick 2 to quit.\n";
		std::cout << "Choice: ";
		std::cin >> choice;
		//using std::cin.fail() - https://www.learncpp.com/cpp-tutorial/5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
		if (std::cin.fail() || (choice < 0 && choice > 2)) {
			std::cout << "Error: input not valid\n";
			break;
		}
		std::cout << "\n";
		std::cout << "You picked choice " << choice << ".\n\n";
		if (choice == 0) {
			Pong game;
			game.Run();
		} else if (choice == 1) {
			ObstacleCourse game;
			game.Run();
		} else {
			choice = 2;
			std::cout << "Thank you for running this program. Goodbye!\n";
		}
	}

	return 0;
}
