#ifndef PROJECTILE_H
#define PROJECTILE_H

#define PROJECTILE_SIZE 15

#include <random>
#include "Sprite.h"

class Projectile: public Sprite {
public:
	Projectile(float x_val, float y_val);
	void SetVelocity();
	void Update();
private:
	float initial_x;
	float initial_y;
};

class DiagonalProjectile: public Sprite {
public:
	DiagonalProjectile(float x_val, float y_val);
	void SetVelocity();
	void Update();
};

#endif
