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
	Engine gameEngine(200, 400);

	Font font = Font("Ubuntu-M", 20);
	Text* test = new Text("Hello World", font, 50, 50);
	Text* testA = new Text("Hello Again", font, 50, 100);
	gameEngine.AddNode(test);

	std::thread mover;

	int iter = 0;
	while (gameEngine.IsRunning()) {
		gameEngine.RenderLoop();
		iter++;
		
		if (iter == 100) {
			test->Move(100, 100);
		}

		if (iter == 200) {
			test->Move(50, 50);
		}
	}

	delete test;
	delete testA;
	
}
