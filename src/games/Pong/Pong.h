#ifndef PONG_H
#define PONG_H

#include <random>
#include "Ball.h"
#include "Game.h"


class Pong: public Game {
public:
	Pong();
	void Run();
protected:
	void Setup();
private:
	std::shared_ptr<Ball> ball = nullptr;
	std::shared_ptr<Sprite> paddle1 = nullptr;
	std::shared_ptr<Sprite> paddle2 = nullptr;
	float paddle2Vel{-1.0};
	int player1Score = 0;
	int player2Score = 0;
};

#endif
