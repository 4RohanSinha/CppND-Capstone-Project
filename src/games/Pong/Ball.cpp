#include "Ball.h"

Ball::Ball(float x, float y, float width, float height): Sprite("../assets/photos/ball.png", x, y, width, height) {
	SetVelocity();
}

void Ball::SetVelocity() {
	x = 200;
	y = 200;
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> distr(0, 2.0*M_PI);
	angle = distr(eng);
	velocity[0] = speed*std::cos(angle);
	velocity[1] = -speed*std::sin(angle);
}

void Ball::HandleCollision() {
	velocity[0] *= -1;
}

void Ball::Update() {
	if (x <= 0 || x >= 500) {
		velocity[0] *= -1;
		SetVelocity();
	}
	if (y <= 0 || y >= 500) {
		velocity[1] *= -1;
	}
	x += velocity[0];
	y += velocity[1];
}
