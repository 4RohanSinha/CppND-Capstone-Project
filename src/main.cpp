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
	//shared pointer so that the same object can be used by the main() function and also be captured by controller methods to manipulate nodes
	std::shared_ptr<Engine> gameEngine = std::make_shared<Engine>(500, 500, "Test Game Engine");

	Font font = Font("Ubuntu-M", 20);
	std::shared_ptr<Text> test = std::make_shared<Text>("Hello World", font, 50, 50);
	std::shared_ptr<Text> testA = std::make_shared<Text>("Hello Again", font, 50, 100);
	std::shared_ptr<Sprite> bird = std::make_shared<Sprite>("../photos/bird.png", 200, 200, 100, 100);	
	//test->SetText("Hi");
	//test->SetText("Hello World");
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(2, test);
	gameEngine->AddToLayer(3, testA);
	gameEngine->AddToLayer(4, bird);
	gameEngine->HandleCollisionsBetween(test, testA, [gameEngine, testA] () {
		gameEngine->HideNode(testA);
	});

	gameEngine->HandleCollisionsBetween(test, bird, [gameEngine, test] () {
		gameEngine->HideNode(test);		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyLeftArr, [bird] () {
		bird->Move(bird->GetX() - 200, bird->GetY(), 4);		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyRightArr, [bird] () {
		bird->Move(bird->GetX() + 200, bird->GetY(), 4);		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [bird] () {
		bird->Move(bird->GetX(), bird->GetY() - 200, 4);
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [bird] () {
		bird->Move(bird->GetX(), bird->GetY() + 200, 4);		
	});

	gameEngine->HandleKeyUpFor(KeyCharacter::kAll, [bird] () {
		bird->ClearAnimations();		
	});
	

	int iter = 0;
	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();
		iter++;
		if (iter == 100) {
			test->Move(100, 100);
			test->Move(200, 0);
			test->Move(50, 100);
			test->Move(0, 0);
			test->Move(300, 300);
			test->Move(75, 10);
		}

		if (iter == 150) {
			test->SetText("Hi");
		}

		if (iter == 200) {
			test->SetText("Hello Again Again");
		}

		if (iter == 500) {
			gameEngine->ShowNode(testA);
		}

	}
	return 0;
}
