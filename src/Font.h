#ifndef FONT_H
#define FONT_H

#include <fstream>
#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

class Font {
public:
	Font(std::string font);

	Font(std::string font, float size);
	
	Font(std::string font, SDL_Color color);

	Font(std::string font, float size, SDL_Color color);

	~Font();

	std::string GetFontName() { return font_; }

	SDL_Color GetColor() { return color_; }

	void SetFont(std::string newFont);
	
	void SetFont(Font newFont);

	void SetSize(float size);
	
	void SetColor(SDL_Color color);

	static bool FontExists(std::string font);

	static bool IsValidRGB(SDL_Color color);

	static bool IsValidSize(float size);

	void SDLConvert();

	TTF_Font* GetTTF();
private:
	std::string font_{"Ubuntu-M"};
	SDL_Color color_;
	TTF_Font* fontTTF_ = nullptr;
	float size_;

	void SetDefaultColor();

	static bool IsValidRGBPoint(int val);

};


#endif
