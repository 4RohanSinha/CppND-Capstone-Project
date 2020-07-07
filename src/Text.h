#ifndef TEXT_H
#define TEXT_H

#include "Node.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "Font.h"

class Text: public Node {
public:
	Text(std::string text);

	Text(std::string text, Font font);
	
	Text(std::string text, Font font, float x, float y, float width, float height);
	
	void ChangeFont(Font newFont);
	
	void ChangeColor(SDL_Color color);
	
	void CreateSurface();

	void ConstructRectangle();
private:
	std::string text_;
	Font font_{Font("Ubuntu-M")};
};

#endif
