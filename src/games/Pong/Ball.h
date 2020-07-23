#include "Sprite.h"
#include <vector>
#include <cmath>
#include <random>

class Ball: public Sprite {
public:
	Ball(float x, float y, float width, float height);	
	void SetVelocity();
	void HandleCollision();
	void Update();
};
