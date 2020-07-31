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
#include "TextManager.h"

class Text: public Node {
public:
	Text(std::string text);

	Text(std::string text, Font font);
	
	Text(std::string text, Font font, float x, float y);

	Font GetFont() { return font_; }

	void AddFont(Font font);

	void SetStyle(int ind);
	
	void AddSource(std::string text);

	void AssignRenderer(SDL_Renderer* renderer);

	void Render();

	void Clear();

	void ConstructRectangle();
	
protected:

private:
	TextManager textManager_;
	std::string text_;
	std::vector<std::string> textOptions_;
	Font font_{Font("Ubuntu-M")};
};

#endif
