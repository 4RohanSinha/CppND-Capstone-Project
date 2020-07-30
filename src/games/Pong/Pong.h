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
	std::shared_ptr<Text> helloWorld = nullptr;
	std::shared_ptr<Text> win = nullptr;
	std::shared_ptr<Text> lose = nullptr;
	std::shared_ptr<Text> playerText = nullptr;
	std::shared_ptr<Text> computerText = nullptr;
	std::unique_ptr<CollisionDetector> pad1 = nullptr;
	std::unique_ptr<CollisionDetector> pad2 = nullptr;
	std::shared_ptr<Scene> scene = nullptr;
	std::shared_ptr<Scene> win_scene = nullptr;
	std::shared_ptr<Scene> lose_scene = nullptr;
	float paddle2Vel{-1.0};
	int player1Score = 0;
	int computerScore = 0;
};

#endif
