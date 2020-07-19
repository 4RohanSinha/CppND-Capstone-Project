#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Node.h"
#include "Color.h"


class Shape: public Node {
public:
	//TODO: make sure Draw() is called
	Shape() { }
	Shape(Color color): color_(color) { }
	Color GetColor() { return color_; }
	virtual void Draw() = 0;
	void GenerateSurfacesFromSurfaces() {}
	void CreateSurface(int i) {}
protected:
	std::vector<SDL_Point> points_;
	Color color_{255, 255, 255, 255};
};

class Ellipse: public Shape {
public:
	Ellipse(int x, int y, int xlength, int ylength);
	Ellipse(int x, int y, int xlength, int ylength, Color color);
	void Draw();
protected:
	int x_;
	int y_;
	int xlength_;
	int ylength_;
	void AssignAxes(int x, int y);
};

class Circle: public Ellipse {
public:
	Circle(int x, int y, int radius): Ellipse(x, y, radius, radius) {}
	Circle(int x, int y, Color color): Ellipse(x, y, 5, 5, color) {}
	Circle(int x, int y, int radius, Color color): Ellipse(x, y, radius, radius, color) {}
	
};

class Rectangle: public Shape {
public:
	Rectangle(int x, int y, int width, int height);
	Rectangle(int x, int y, int width, int height, Color color); 
	void Draw();
protected:
	int x_;
	int y_;
	int width_;
	int height_;
	void AssignSides(int w, int h);
};

class Square: public Rectangle {
public:
	Square(int x, int y, int side): Rectangle(x, y, side, side) {}
	Square(int x, int y, int side, Color color): Rectangle(x, y, side, side, color) {}
};
#endif
