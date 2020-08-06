#include "ObstacleCourse.h"

ObstacleCourse::ObstacleCourse(): Game() {
	//the window is a public member of Engine class
	gameEngine->window = std::make_unique<Window>(500, 500, "Obstacle Course");

	//create scenes - initial scene with instructions, gameplay scene, and you win scene
	//player has unlimited attempts, so no you lose scene
	initialScene = gameEngine->window->sceneManager->CreateNewScene("initial_scene");
	scene1 = gameEngine->window->sceneManager->CreateNewScene("scene1");
	win_scene = gameEngine->window->sceneManager->CreateNewScene("win_scene");
	
	//timer to slow down game a little
	timer = std::make_unique<Timer>(16.66);


	//create nodes to display on screen
	instructions = std::make_shared<Sprite>("../assets/photos/instructions.png", 10, -75, 480, 600);	
	goal = std::make_shared<Sprite>("../assets/photos/goal.png", 425, 330, 85, 75);
	
	wall1 = std::make_shared<Wall>(0, 50, 500, 15);
	wall2 = std::make_shared<Wall>(0, 175, 450, 15);
	wall3 = std::make_shared<Wall>(50, 300, 500, 15);
	wall4 = std::make_shared<Wall>(0, 425, 500, 15);
	
	movingWall1 = std::make_shared<MovingWall>(110, 70, 16, 60);
	movingWall2 = std::make_shared<MovingWall>(260, 80, 16, 60);
	movingWall3 = std::make_shared<MovingWall>(410, 90, 16, 60);
	
	projectile1 = std::make_shared<Projectile>(0, 190);
	projectile2 = std::make_shared<Projectile>(0, 230);
	projectile3 = std::make_shared<Projectile>(0, 270);
	
	diagProj1 = std::make_shared<DiagonalProjectile>(75, 400);
	diagProj2 = std::make_shared<DiagonalProjectile>(200, 380);
	diagProj3 = std::make_shared<DiagonalProjectile>(325, 350);
	
	winText = std::make_shared<Text>("You win!", Font("Ubuntu-M", 50), 200, 200);
	
	player = std::make_shared<Sprite>("../assets/photos/ball.png", 50, 125, 25, 25);

	//add the nodes to node groups - this will be useful for detecting collisions
	projectiles.AddNodes({projectile1, projectile2, projectile3});
	diagonalProjectiles.AddNodes({diagProj1, diagProj2, diagProj3});
	movingWalls.AddNodes({movingWall1, movingWall2, movingWall3});
	mmWalls.AddNodes({wall1, wall2});
	allWalls.AddNodes({wall1, wall2, wall3, wall4});
	diagWalls.AddNodes({wall3, wall4});


	//lambda function that will be called when the player hits an obstacle
	//is passed into the collision detector methods
	auto playerLosesLife = [this] () {
		player->x = 50;
		player->y = 125;
	};

	//initial scene just contains instructions
	initialScene->AddNode(instructions);

	//add obstacles, player, goal to gameplay scene
	scene1->AddNodes({player, wall1, wall2, wall3, wall4, movingWall1, movingWall2, movingWall3, projectile1, projectile2, projectile3, diagProj1, diagProj2, diagProj3, goal});

	//add you win text to win scene
	win_scene->AddNode(winText);

	//when the player collides with the goal, they win
	collisionManager.DetectCollisionsBetween(player, goal, "playerGoal", [this] () {
		gameEngine->window->sceneManager->ShowScene("win_scene");
	});

	//for these first three collisions:
	//these collision detectors will be stored in an unordered map in CollisionManager
	//the game loop will check to see if they have collided and act accordingly
	//these are using node groups to check for collisions between stationary walls and each moving wall
	//the corresponding moving wall will flip velocity once it hits a stationary wall
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall1, "mm1wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall2, "mm2wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(mmWalls, movingWall3, "mm3wall");

	//player goes back to the beginning if they hit stationary or moving walls, or any projectile
	collisionManager.DetectCollisionsBetweenGroupAndNode(allWalls, player, "wallPlayer", playerLosesLife);
	collisionManager.DetectCollisionsBetweenGroupAndNode(movingWalls, player, "movingWallPlayer", playerLosesLife);
	collisionManager.DetectCollisionsBetweenGroupAndNode(projectiles, player, "projectilePlayer", playerLosesLife);
	collisionManager.DetectCollisionsBetweenGroupAndNode(diagonalProjectiles, player, "diagonalProjectilePlayer", playerLosesLife);

	//when the diagonal (not horizontal moving) projectiles hit a wall, they flip velocity
	collisionManager.DetectCollisionsBetweenGroupAndNode(allWalls, diagProj1, "diag1Wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(allWalls, diagProj2, "diag2Wall");
	collisionManager.DetectCollisionsBetweenGroupAndNode(allWalls, diagProj3, "diag3Wall");

	//the enter key shows the game scene from the initial scene
	gameEngine->controller.HandleKeyPressFor(KeyCharacter::keyEnter, [this] () {
		gameEngine->window->sceneManager->ShowScene("scene1");		
	});


	//this moves the player to the left
	gameEngine->controller.HandleKeyPressFor(KeyCharacter::keyLeftArr, [this] () {
		if (player->x > 0) {
			player->x -= 2;
		}

	});

	//move the player to the right
	gameEngine->controller.HandleKeyPressFor(KeyCharacter::keyRightArr, [this] () {
		if (player->x < 475)
			player->x += 2;
	});

	//move player up
	gameEngine->controller.HandleKeyPressFor(KeyCharacter::keyUpArr, [this] () {
		if (player->y > 0)
			player->y -= 2;
	});

	//move player down
	gameEngine->controller.HandleKeyPressFor(KeyCharacter::keyDownArr, [this] () {
		if (player->y < 475)
			player->y += 2;
	});
}

void ObstacleCourse::Run() {
	//show the instructions scene when the game begins to run
	gameEngine->window->sceneManager->ShowScene("initial_scene");
	//game loop
	while (gameEngine->IsRunning()) {
		timer->BeginKeyframe(); //begin the current keyframe - Timer runs SDL_GetTicks
		//this method gets input and renders
		//the update part of the game loop is done in this while loop
		gameEngine->Loop();
			
		//check for collisions that were added in the constructor
		collisionManager.Update();

		//CollisionManager has overloaded [] operator (see .h file)
		//NGCollisionDetector, which composes CollisionManager, can be converted to a bool because it has overloaded operator bool()
		// [] operator returns NGCollisionDetector
		// it is converted to a bool, so an if statement with it will check if the collision has occurred or not
		// the string identifier is from the constructor when each collision sent to the collision manager was given a string ID
		
		//the moving wall flips velocity if it hits stationary walls
		if (collisionManager["mm1wall"]) {
			movingWall1->velocity[1] *= -1;
		}

		//same as above
		if (collisionManager["mm2wall"]) {
			movingWall2->velocity[1] *= -1;
		}

		//same as above
		if (collisionManager["mm3wall"]) {
			movingWall3->velocity[1] *= -1;
		}

		//the diagonal projectile flips its velocity if it hits a stationary wall
		if (collisionManager["diag1Wall"]) {
			diagProj1->velocity[0] *= -1;
			diagProj1->velocity[1] *= -1;
		}

		//same as above
		if (collisionManager["diag2Wall"]) {
			diagProj2->velocity[0] *= -1;
			diagProj2->velocity[1] *= -1;
		}

		//same as above
		if (collisionManager["diag3Wall"]) {
			diagProj3->velocity[0] *= -1;
			diagProj3->velocity[1] *= -1;
		}

		timer->EndKeyframe(); //ends current keyframe - Timer runs SDL_GetTicks and calls SDL_Delay if the keyframe was too fast
	}
}
