#include "Pong.h"

Pong::Pong(): Game() {
	scene = std::make_shared<Scene>();
	win_scene = std::make_shared<Scene>();
	lose_scene = std::make_shared<Scene>();
	gameEngine->sceneManager->AddScene(scene, "main");
	gameEngine->sceneManager->AddScene(win_scene, "player_win");
	gameEngine->sceneManager->AddScene(lose_scene, "player_lose");
	gameEngine->sceneManager->ShowScene("main");
	timer = std::make_unique<Timer>(16.66);
	paddle1 = std::make_shared<Sprite>("../assets/photos/paddle1.jpg", 20, 200, 25, 100);
	paddle2 = std::make_shared<Sprite>("../assets/photos/paddle2.png", 450, 200, 25, 100);
	Font testFont = Font("Ubuntu-M", 20);
	playerText = std::make_shared<Text>("0", testFont, 50, 50);
	computerText = std::make_shared<Text>("0", testFont, 450, 50);
	helloWorld = std::make_shared<Text>("Hello World", testFont, 200, 200);
	win = std::make_shared<Text>("You win!", testFont, 200, 200);
	lose = std::make_shared<Text>("You win!", testFont, 200, 200);
	ball = std::make_shared<Ball>(250, 250, 50, 50);
	pad1 = std::make_unique<CollisionDetector>(paddle1, ball);
	pad2 = std::make_unique<CollisionDetector>(paddle2, ball);
	gameEngine->audioManager.AddMusic("../assets/audio/beat.wav", "beat");
	gameEngine->audioManager.AddSoundEffect("../assets/audio/medium.wav", "medium");
	Setup();
}

void Pong::Setup() {
	scene->AddNode(ball);
	scene->AddNode(paddle1);
	scene->AddNode(paddle2);
	scene->AddNode(helloWorld);
	scene->AddNode(playerText);
	scene->AddNode(computerText);
	win_scene->AddNode(win);
	lose_scene->AddNode(lose);

	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
		if (paddle1->y > 0)
                	paddle1->y -= 2;
        });

        gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
		if (paddle1->y < 450)
                	paddle1->y += 2;
        });
}

void Pong::Run() {
	gameEngine->sceneManager->ShowScene("main");
	while (gameEngine->IsRunning()) {
		timer->BeginKeyframe();
		if (player1Score == 5 && player1Score > computerScore) {
			gameEngine->sceneManager->ShowScene("player_win");
		} else if (computerScore == 5 && computerScore > player1Score) {
			gameEngine->sceneManager->ShowScene("player_lose");
		}
		gameEngine->Loop();
		gameEngine->sceneManager->RenderCurrentScene();
		(*pad1)();
		(*pad2)();
		if (pad1->FirstCollisionIsHappening() || pad2->FirstCollisionIsHappening()) {
			gameEngine->audioManager.Play("medium");
			ball->HandleCollision();
		}
		paddle2->y += paddle2Vel;
		if (paddle2->y == 0 || paddle2->y == 450)
			paddle2Vel *= -1;
		if (ball->x >= 500) {
			player1Score++;
			playerText->AddSource(std::to_string(player1Score));
			computerText->AddSource(std::to_string(computerScore));
			ball->SetVelocity();
			std::cout << player1Score << " " << computerScore << "\n";
		}
		else if (ball->x <= 0) {
			computerScore++;
			playerText->AddSource(std::to_string(player1Score));
			computerText->AddSource(std::to_string(computerScore));
			ball->SetVelocity();
			std::cout << player1Score << " " << computerScore << "\n";
		}

		if (ball->y <= 0 || ball->y >= 500)
			ball->velocity[1] *= -1;

		ball->Update();
		timer->EndKeyframe();
	}
}
