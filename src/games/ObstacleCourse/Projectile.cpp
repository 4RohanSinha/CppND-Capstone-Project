#include "Projectile.h"


Projectile::Projectile(float x_val, float y_val): Sprite("../assets/photos/ball.png", x_val, y_val, PROJECTILE_SIZE, PROJECTILE_SIZE) {
	initial_x = x_val;
	initial_y = y_val;
	SetVelocity();
}

void Projectile::SetVelocity() {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> distr_vel(0.25, 3);
	velocity[0] = distr_vel(eng);
}

void Projectile::Update() {
	x += velocity[0];
	y += velocity[1];
	if (x >= 450) {
		x = initial_x;
		SetVelocity();
	}
}

DiagonalProjectile::DiagonalProjectile(float x_val, float y_val): Sprite("../assets/photos/ball.png", x_val, y_val, PROJECTILE_SIZE, PROJECTILE_SIZE) {
	SetVelocity();
}

void DiagonalProjectile::SetVelocity() {
	std::random_device rd;
	std::mt19937 eng(rd());
	//random angle of diagonal projectile
	std::uniform_real_distribution<> distr_angle(0, 2.0*M_PI);
	double angle = distr_angle(eng);
	//random speed
	std::uniform_real_distribution<> distr_speed(0.5, 3);
	int speed = distr_speed(eng);
	while (speed == 0) {
		speed = distr_speed(eng);
	}

	//add another unit to modify direction
	std::uniform_int_distribution<> distr_dir(0, 1);
	int direction = distr_dir(eng);
	if (direction == 0) direction = -1;

	//assign to velocity
	velocity[0] = direction*speed*std::cos(angle);
	velocity[1] = direction*-speed*std::sin(angle);
}

void DiagonalProjectile::Update() {
	x += velocity[0];
	y += velocity[1];
	if (x <= 0 || x >= 425)
		velocity[0] *= -1;
	if (y <= 0 || y >= 425)
		velocity[1] *= -1;
}
