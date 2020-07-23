#include <numeric>
#include <random>
#include "Game.h"


Game::Game() {
	gameEngine = std::make_unique<Engine>(500, 500, "Pong");
}
