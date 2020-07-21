#include <numeric>
#include <random>
#include "Game.h"


Game::Game() {
	gameEngine = std::make_shared<Engine>(500, 500, "Pong");
	text = std::make_shared<Text>("Hello World", Font("Ubuntu-M", 20), 50, 50);
	bird = std::make_shared<Sprite>("../photos/bird.png", 100, 100, 100, 100);
	alligator = std::make_shared<Sprite>("../photos/alligator.png", 200, 200, 100, 100);
	paddle1 = std::make_shared<Rectangle>(20, 200, 25, 100, Color(26, 178, 255, 255));
	paddle1->Draw();
	paddle2 = std::make_shared<Rectangle>(450, 200, 25, 100, Color(0, 204, 102, 255));
	paddle2->Draw();
	ball2 = std::make_shared<Circle>(250, 250, 25, Color(230, 230, 0, 255));
	ball2->Draw();
	Setup();
}

void Game::Setup() {
	bird->AddImage("../photos/alligator.png");
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(1, ball2);
	gameEngine->AddToLayer(1, paddle1);
	gameEngine->AddToLayer(1, paddle2);
	gameEngine->AddToLayer(1, bird);
	gameEngine->AddToLayer(1, alligator); 
	gameEngine->AddToLayer(1, text);
	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
		bird->SetImage(0);
		bird->y -= 2;
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
		bird->SetImage(1);		
		bird->y += 2;
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyLeftArr, [this] () {
		bird->x -= 2;		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyRightArr, [this] () {
		bird->x += 2;		
	});

	gameEngine->HandleCollisionsBetween(bird, alligator, [this] () {
		bird->x -= 100;		
	});
}

void Game::Run() {
	//TODO: replace iter with Timer class
	//NOTE: the code commented out below is kept just in case it may be needed again
	int iter = 0;
	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();

		iter++;

	}
/*	int iter = 0;
	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();
		iter++;
		if (iter == 100) {
                        test->Move(100, 100, 2);
                        test->Move(200, 0, 2);
                        test->Move(50, 100, 2);
                        test->Move(0, 0, 2);
                        test->Move(300, 300, 2);
                        test->Move(75, 10, 2);
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


	}*/
}
