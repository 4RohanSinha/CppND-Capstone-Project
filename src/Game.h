#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include <memory>

class Game {
public:
	Game();
	void Run();
private:
	std::shared_ptr<Engine> gameEngine;
	std::shared_ptr<Text> test;
	std::shared_ptr<Text> testA;
	std::shared_ptr<Sprite> bird;

	void Setup();
};

#endif
