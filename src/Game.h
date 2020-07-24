#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Timer.h"
#include "Shape.h"
#include <memory>
#include <random>

class Game {
public:
	Game();
	virtual void Run() = 0;

protected:
	std::unique_ptr<Engine> gameEngine = nullptr;
	std::unique_ptr<Timer> timer = nullptr;
	virtual void Setup() = 0;
};

#endif
