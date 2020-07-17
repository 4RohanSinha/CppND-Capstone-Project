#ifndef COLOR_H
#define COLOR_H

#include <vector>
#include <initializer_list>

class Color {
public:
	//using std::initializer_list: https://en.cppreference.com/w/cpp/utility/initializer_list
	Color(std::initializer_list<int> l); 

	Color(int red, int green, int blue);

	Color(int red, int green, int blue, int alpha);

	Color(const Color& otherColor) const { color_ = otherColor.color_; }

	int GetRed() { return color_[0]; }

	int GetGreen() { return color_[1]; }

	int GetBlue() { return color_[2]; }

	int GetAlpha() { return color_[3]; }

	std::vector<int> GetColorVector() { return color_; }

	bool operator==(const Color& otherColor) const {
		return (color_ == otherColor.color_);
	}

	bool operator!=(const Color& otherColor) const {
		return !(*this == otherColor);
	}

	bool operator=(const Color& otherColor) const {
		color_ = otherColor.color_;
	}

	SDL_Color ConvertToSDL();

private:
	std::vector<int> color_;

};

#endif