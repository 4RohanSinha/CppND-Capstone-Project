#include "Node.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Engine.h"
#include <iostream>
#include <memory>
#include <thread>
#include <future>


//A sample program
//TODO: Find a way to prevent the user from having to declare pointers to Node objects
int main() {
	std::unique_ptr<Engine> gameEngine = std::make_unique<Engine>(500, 500, "Test Game Engine");

	Font font = Font("Ubuntu-M", 20);
	std::shared_ptr<Text> test = std::make_shared<Text>("Hello World", font, 50, 50);
	std::shared_ptr<Text> testA = std::make_shared<Text>("Hello Again", font, 50, 100);
	std::shared_ptr<Sprite> bird = std::make_shared<Sprite>("../photos/bird.png", 200, 200, 100, 100);	
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(2, test);
	gameEngine->AddToLayer(3, testA);
	gameEngine->AddToLayer(4, bird);
	

	int iter = 0;
	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();
		iter++;
		if (iter == 100) {
			test->Move(100, 100);
			test->Move(200, 200);
			test->Move(50, 100);
			test->Move(0, 0);
			test->Move(300, 300);
			test->Move(75, 10);
			bird->Move(400, 50);
			bird->Move(50, 50);
			bird->Move(300, 300);
		}

		if (iter == 150) {
			test->SetText("Hi");
		}

		if (iter == 200) {
		}

	}
	return 0;	
}
