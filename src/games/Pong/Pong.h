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
	//non-owning references to the Scene objects - the SceneManager owns them
	//the SceneManager automatically deallocates the memory for these raw pointers
	//therefore, the user does not need to
	//the user simply creates a scene by calling a method in the scene manager
	//this method creates a unique_ptr internally and also returns a raw pointer
	//these raw pointers are assigned to the variables below
	Window* mainWindow = nullptr;
	Scene* scene = nullptr;
	Scene* win_scene = nullptr;
	Scene* lose_scene = nullptr;
	float paddle2Vel{-1.0};
	int player1Score = 0;
	int computerScore = 0;
};

#endif
