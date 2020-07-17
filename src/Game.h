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
};

#endif
