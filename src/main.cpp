#include "Node.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Engine.h"
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include <cmath>

//A sample program
//TODO: Find a way to prevent the user from having to declare pointers to Node objects
int main() {
	//shared pointer so that the same object can be used by the main() function and also be captured by controller methods to manipulate nodes
	std::shared_ptr<Engine> gameEngine = std::make_shared<Engine>(500, 500, "Test Game Engine");

	Font font = Font("Ubuntu-M", 20);
	std::shared_ptr<Text> test = std::make_shared<Text>("Hello World", font, 50, 50);
	std::shared_ptr<Text> testA = std::make_shared<Text>("Hello Again", font, 50, 100);
	std::shared_ptr<Sprite> bird = std::make_shared<Sprite>("../photos/bird.png", 200, 200, 100, 100);	
	
	bird->AddImage("../photos/alligator.png");
	bird->SetImage(0);
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(2, test);
	gameEngine->AddToLayer(3, testA);
	gameEngine->AddToLayer(4, bird);
	gameEngine->HandleCollisionsBetween(test, testA, [gameEngine, testA] () {
		gameEngine->HideNode(testA);
	});

	gameEngine->HandleCollisionsBetween(test, bird, [gameEngine, test, bird] () {
		bird->ChangeSpeed(-4.0);
		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyLeftArr, [bird] () {
		if (!bird->IsAnimating())
			bird->Move(bird->GetX() - 10, bird->GetY(), 4);		
		bird->SetImage(1);
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyRightArr, [bird] () {
		if (!bird->IsAnimating())
			bird->Move(bird->GetX() + 10, bird->GetY(), 4);		
		bird->SetImage(0);
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [bird] () {
		if (!bird->IsAnimating())
			bird->Move(bird->GetX(), bird->GetY() - 10, 4);
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [bird] () {
		if (!bird->IsAnimating())
			bird->Move(bird->GetX(), bird->GetY() + 10, 4);		
	});

	gameEngine->HandleKeyUpFor(KeyCharacter::kAll, [bird] () {
		bird->ClearAnimations();		
	});
	

	int iter = 0;
	int delta = 200;
	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();
		iter++;
		if (iter == 100) {
/*			test->Move(100, 100, 2);
			test->Move(200, 0, 2);
			test->Move(50, 100, 2);
			test->Move(0, 0, 2);
			test->Move(300, 300, 2);
			test->Move(75, 10, 2);
*/		}

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
