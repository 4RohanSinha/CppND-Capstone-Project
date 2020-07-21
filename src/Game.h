#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include "Shape.h"
#include <memory>

class Game {
public:
	Game();
	void Run();
private:
	std::shared_ptr<Engine> gameEngine = nullptr;
	std::shared_ptr<Rectangle> paddle1 = nullptr;
	std::shared_ptr<Rectangle> paddle2 = nullptr;
	std::shared_ptr<Circle> ball2 = nullptr;
	std::shared_ptr<Sprite> bird = nullptr;
	std::shared_ptr<Sprite> alligator = nullptr;
	std::shared_ptr<Text> text = nullptr;

	void Setup();
};

#endif
