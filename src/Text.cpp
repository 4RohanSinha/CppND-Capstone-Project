#include "Node.h"
#include "Text.h"
#include "Font.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

Text::Text(std::string text): Node(0, 0, 100, 100), text_(text) {
	rect_ = new SDL_Rect;
	ConstructRectangle();
	CreateSurface();
}

Text::Text(std::string text, Font font) : Node(0, 0, 100, 100), text_(text) {
	rect_ = new SDL_Rect;
	font_ = font;
	ConstructRectangle();
	CreateSurface();
}

Text::Text(std::string text, Font font, float x, float y, float width, float height): Node(x, y), text_(text) {
	font_ = font;
	rect_ = new SDL_Rect;
	CreateSurface();
	if (CheckLength(width) && CheckLength(height)) {
		width_ = width;
		height_ = height;
		ConstructRectangle();
	} else {
		throw std::invalid_argument("Error: invalid length");
	}
}

void Text::ConstructRectangle() {
	rect_->x = x_;
	rect_->y = y_;
	rect_->w = width_;
	rect_->h = height_;
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
