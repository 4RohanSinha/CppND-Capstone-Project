#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game();
	void Run();
private:
	std::shared_ptr<Engine> gameEngine;
};

#endif
