#include "Wall.h"

MovingWall::MovingWall(float x, float y, int width, int height): Sprite("../assets/photos/paddle2.png", x, y, width, height) {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr_dir(0, 1);
	int dir = distr_dir(eng);
	if (dir == 0) dir = -1;
	std::uniform_real_distribution<> distr_vel(0.5, 1.5);
	velocity[1] = dir*distr_vel(eng);
}

void MovingWall::Update() {
	x += velocity[0];
	y += velocity[1];
}
