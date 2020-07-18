#include "Game.h"

Game::Game() {
	//setup before game loop
	gameEngine_ = std::make_shared<Engine>(500, 500, "Test Game Engine");

}

void Game::Run() {
	while (gameEngine_->IsRunning()) {
		gameEngine_->RenderLoop();
	}
}
