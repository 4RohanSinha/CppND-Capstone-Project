#include "ObstacleCourse.h"

ObstacleCourse::ObstacleCourse(): Game() {
	gameEngine->window = std::make_unique<Window>(500, 500, "Obstacle Course");
	scene1 = gameEngine->window->sceneManager->CreateNewScene("scene1");
	scene2 = gameEngine->window->sceneManager->CreateNewScene("scene2");
	win_scene = gameEngine->window->sceneManager->CreateNewScene("win_scene");
	lose_scene = gameEngine->window->sceneManager->CreateNewScene("lose_scene");
	timer = std::make_unique<Timer>(16.66);
	wall1 = std::make_shared<Wall>(0, 50, 500, 15);
	wall2 = std::make_shared<Wall>(0, 175, 450, 15);
	wall3 = std::make_shared<Wall>(50, 300, 500, 15);
	wall4 = std::make_shared<Wall>(0, 425, 500, 15);
	movingWall1 = std::make_shared<MovingWall>(110, 70, 16, 60);
	movingWall2 = std::make_shared<MovingWall>(260, 70, 16, 60);
	movingWall3 = std::make_shared<MovingWall>(410, 70, 16, 60);
	movingWalls.AddNodes({movingWall1, movingWall2, movingWall3});
	mmWalls.AddNodes({wall1, wall2});
	allWalls.AddNodes({wall1, wall2, wall3, wall4});
	player = std::make_shared<Sprite>("../assets/photos/ball.png", 50, 125, 25, 25);


	//lambda function that will be called when the player loses a life
	//is passed into the collision detector methods
	auto playerLosesLife = [this] () {
		lives--;
		player->x = 50;
		player->y = 125;
	};
	
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall1, "mm1wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall2, "mm2wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall3, "mm3wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(allWalls, player, "wallPlayer", playerLosesLife);
	collisionManager.DetectCollisionsBetweenGroupAndNode(movingWalls, player, "movingWallPlayer", playerLosesLife);

	Setup();
}

void ObstacleCourse::Setup() {
	scene1->AddNodes({player, wall1, wall2, wall3, wall4, movingWall1, movingWall2, movingWall3});
	gameEngine->HandleKeyPressFor(KeyCharacter::keyLeftArr, [this] () {
		if (player->x > 0)
			player->x -= 2;
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyRightArr, [this] () {
		if (player->x < 500)
			player->x += 2;		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
		if (player->y > 0)
			player->y -= 2;		
	});

	gameEngine->HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
		if (player->y < 500)
			player->y += 2;		
	});
}

void ObstacleCourse::Run() {
	gameEngine->window->sceneManager->ShowScene("scene1");
	while (gameEngine->IsRunning()) {
		timer->BeginKeyframe();
		gameEngine->Loop();
		movingWall1->Update();
		movingWall2->Update();
		movingWall3->Update();
		collisionManager.Update();

		if (collisionManager["mm1wall"]) {
			movingWall1->velocity[1] *= -1;
		}

		if (collisionManager["mm2wall"]) {
			movingWall2->velocity[1] *= -1;
		}


		if (collisionManager["mm3wall"]) {
			movingWall3->velocity[1] *= -1;
		}

		timer->EndKeyframe();
	}
}
