#include "Game.h"

Game::Game() {
	gameEngine = std::make_shared<Engine>(500, 500, "Test Game Engine");
	Font font = Font("Ubuntu-M", 20);
	test = std::make_shared<Text>("Hello World", font, 50, 50);
	testA = std::make_shared<Text>("Hello Again", font, 50, 100);
	bird = std::make_shared<Sprite>("../photos/bird.png", 200, 200, 100, 100);
	Setup();
}

void Game::Setup() {
	bird->AddImage("../photos/alligator.png");
	bird->SetImage(0);
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(2, test);
	gameEngine->AddToLayer(3, testA);
	gameEngine->AddToLayer(4, bird);
	gameEngine->HandleCollisionsBetween(test, testA, [this] () {
                gameEngine->HideNode(testA);
        });

        gameEngine->HandleCollisionsBetween(test, bird, [this] () {
                bird->ChangeSpeed(0.0);

        });

        gameEngine->HandleKeyPressFor(KeyCharacter::keyLeftArr, [this] () {
                if (!bird->IsAnimating())
                        bird->Move(bird->GetX() - 10, bird->GetY(), 4);
                bird->SetImage(1);
        });

        gameEngine->HandleKeyPressFor({KeyCharacter::keyLeftArr, KeyCharacter::keyUpArr}, [this] () {
                if (!bird->IsAnimating())
                        bird->Move(bird->GetX() - 10, bird->GetY() - 10, 4);     
        });

	gameEngine->HandleKeyPressFor(KeyCharacter::keyRightArr, [this] () {
                if (!bird->IsAnimating())
                        bird->Move(bird->GetX() + 10, bird->GetY(), 4);
                bird->SetImage(0);
        });

        gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
                if (!bird->IsAnimating())
                        bird->Move(bird->GetX(), bird->GetY() - 10, 4);
        });

        gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
                if (!bird->IsAnimating())
                        bird->Move(bird->GetX(), bird->GetY() + 10, 4);
        });

        gameEngine->HandleKeyUpFor(KeyCharacter::kAll, [this] () {
                bird->ClearAnimations();
        });


}

void Game::Run() {
	//TODO: replace iter with Timer class
	int iter = 0;
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


	}
}
