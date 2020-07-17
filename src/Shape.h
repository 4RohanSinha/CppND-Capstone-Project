#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Node.h"
#include "Color.h"


class Shape: public Node {
public:
	Shape() { Draw(); }
	Shape(Color color): color_(color) { Draw(); }
	virtual void Draw();
	void GenerateSurfacesFromSurfaces() {}
	void CreateSurface(int i) {}
	void AnimationChange() {}
protected:
	std::vector<SDL_Point> points;
	Color color_{255, 255, 255, 255};
};

#endif
