#include "Node.h"
#include "Text.h"
#include "Font.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

Text::Text(std::string text): Node(0, 0), text_(text) {
	CreateSurface();
}

Text::Text(std::string text, Font font) : Node(0, 0), text_(text) {
	font_ = font;
	CreateSurface();
}

Text::Text(std::string text, Font font, float x, float y): Node(x, y), text_(text) {
	font_ = font;
	CreateSurface();
}

void Text::ChangeFont(Font newFont) {
	font_.SetFont(newFont);
	//TODO: Re-render
	
	

}

void Text::ChangeColor(SDL_Color color) {
	font_.SetColor(color);
	//TODO: Re-render
}

void Text::CreateSurface() {
	font_.SDLConvert();
	TTF_Font * fontTTF = font_.GetTTF();
	surface_ = TTF_RenderText_Solid(fontTTF, text_.c_str(), font_.GetColor());
}
