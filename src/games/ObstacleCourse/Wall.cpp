#include "Wall.h"

MovingWall::MovingWall(float x, float y, int width, int height): Sprite("../assets/photos/paddle2.png", x, y, width, height) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 1);
	int direction = distr(eng);
	if (direction == 0)
		velocity[1] = -1;
	else
		velocity[1] = 1;
}

void MovingWall::Update() {
	x += velocity[0];
	y += velocity[1];
}
