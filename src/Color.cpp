#include "Color.h"

Color::Color(std::initializer_list<int> l) {
	int max = *std::max_element(l.begin(), l.end());
        int min = *std::min_element(l.begin(), l.end());
        if (l.size() == 4 && (max <= 255 && min >= 0)) color_ = l;
	else if (l.size() == 3 && (max <= 255 && min >= 0)) {
		color_.assign({*l.begin(), *(l.begin() + 1), *(l.begin() + 2), 255});
	}
        else throw std::invalid_argument("Error: Color constructor: arguments invalid. Either incorrect length for the initializer or one of the values passed in is not within the 0-255 range");
}

Color::Color(int red, int green, int blue) {
	if ((red <= 255 && red >= 0) && (green <= 255 && green >= 0) && (blue <= 255 && blue >= 0))
		color_.assign({red, green, blue, 255});
	else
		throw std::invalid_argument("Error: Color::Color(int red, int green, int blue): red, green, or blue is not within the 0-255 range.");
}
Color::Color(int red, int green, int blue, int alpha) {
	if ((red <= 255 && red >= 0) && (green <= 255 && green >= 0) && (blue <= 255 && blue >= 0) && (alpha <= 255 && alpha >= 0))
                color_.assign({red, green, blue, alpha});
        else
		throw std::invalid_argument("Error: Color::Color(int red, int green, int blue, int alpha): red, green, blue, or alpha is not within the 0-255 range.");

}


SDL_Color Color::ConvertToSDL() {
	SDL_Color res;
	res.r = color_[0];
	res.g = color_[1];
	res.b = color_[2];
	res.a = color_[3];
	return res;
}
