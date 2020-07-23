#include "Pong.h"

Pong::Pong(): Game() {
	paddle1 = std::make_shared<Sprite>("../assets/photos/paddle1.jpg", 20, 200, 25, 100);
	paddle2 = std::make_shared<Sprite>("../assets/photos/paddle2.png", 450, 200, 25, 100);
	ball = std::make_shared<Ball>(250, 250, 50, 50);
	gameEngine->audioManager.AddMusic("../assets/audio/beat.wav", "beat");
	gameEngine->audioManager.AddSoundEffect("../assets/audio/medium.wav", "medium");
	Setup();
}

void Pong::Setup() {
	gameEngine->AddLayers(5);
	gameEngine->AddToLayer(1, ball);
	gameEngine->AddToLayer(1, paddle1);
	gameEngine->AddToLayer(1, paddle2);
	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
		if (paddle1->y > 0)
                	paddle1->y -= 2;
        });

        gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
		if (paddle1->y < 450)
                	paddle1->y += 2;
        });

        gameEngine->HandleCollisionsBetween(ball, paddle1, [this] () {
                gameEngine->audioManager.Play("medium");
		ball->HandleCollision();
        });

        gameEngine->HandleCollisionsBetween(ball, paddle2, [this] () {
                gameEngine->audioManager.Play("medium");
		ball->HandleCollision();
        });

}

void Pong::Run() {
	int iter = 0;

	while (gameEngine->IsRunning()) {
		gameEngine->RenderLoop();
		paddle2->y += paddle2Vel;
		if (paddle2->y == 0 || paddle2->y == 450)
			paddle2Vel *= -1;
		ball->Update();
		iter++;
	}
}
