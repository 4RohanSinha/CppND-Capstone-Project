#ifndef WALL_H
#define WALL_H

#include <random>
#include "Sprite.h"

class Wall: public Sprite {
public:
	Wall(float x, float y, int width, int height): Sprite("../assets/photos/paddle1.jpg", x, y, width, height) {}
};

class MovingWall: public Sprite {
public:
	MovingWall(float x, float y, int width, int height);

};


#endif
