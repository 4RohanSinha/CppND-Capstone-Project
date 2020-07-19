#include "Shape.h"
#include <cmath>

Ellipse::Ellipse(int x, int y, int xlength, int ylength): x_(x), y_(y), Shape(Color(255, 255, 255)) {
	AssignAxes(xlength, ylength);
}


Ellipse::Ellipse(int x, int y, int xlength, int ylength, Color color): x_(x), y_(y), Shape(color) {
	AssignAxes(xlength, ylength);
}

void Ellipse::Draw() {
        for (int x_iter = x_ - xlength_; x_iter <= x_ + xlength_; x_iter++) {
                for (int y_iter = y_ - ylength_; y_iter <= y_ + ylength_; y_iter++) {
                        SDL_Point curPoint;
                        if ((std::pow(y_ - y_iter, 2))/(std::pow(ylength_, 2)) + std::pow(x_ - x_iter, 2)/(std::pow(xlength_, 2)) <= 1) {
                                curPoint.x = x_iter;
                                curPoint.y = y_iter;
                                points_.push_back(curPoint);
                        }
                }
        }
}

void Ellipse::AssignAxes(int x, int y) {
	if (x > 0 && y > 0) {
		xlength_ = x;
		ylength_ = y;
	} else {
		throw std::invalid_argument("Error: an axis of Ellipse is not positive. Cannot construct Ellipse.");
	}
}

Rectangle::Rectangle(int x, int y, int width, int height): x_(x), y_(y), Shape(Color(255, 255, 255)) {
	AssignSides(width, height);
}

Rectangle::Rectangle(int x, int y, int width, int height, Color color): x_(x), y_(y), Shape(color) {
	AssignSides(width, height);
}

void Rectangle::Draw() {
	for (int x_iter = x_; x_iter <= x_ + width_; x_iter++) {
		for (int y_iter = y_; y_iter <= y_ + height_; y_iter++) {
			SDL_Point curPoint;
			curPoint.x = x_iter;
			curPoint.y = y_iter;
			points_.push_back(curPoint);
		}
	}
}

void Rectangle::AssignSides(int w, int h) {
	if (w > 0 && h > 0) {
		width_ = w;
		height_ = h;
	} else {
		throw std::invalid_argument("Error: invalid side for Rectangle constructor");
	}
}
