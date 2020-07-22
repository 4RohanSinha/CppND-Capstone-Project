#include "Node.h"
#include "Text.h"
#include "Font.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>

Text::Text(std::string text): Node(0, 0), text_(text) {
	rendererSetDimensions_ = true;
	collisionBitMask = "Text";
	textOptions_.push_back(text_);
	newSurfaces_ = std::queue<std::shared_ptr<SDL_Surface>>();
}

Text::Text(std::string text, Font font) : Node(0, 0), text_(text) {
	font_ = font;
	rendererSetDimensions_ = true;
	collisionBitMask = "Text";
	textOptions_.push_back(text_);
	newSurfaces_ = std::queue<std::shared_ptr<SDL_Surface>>();
}

Text::Text(std::string text, Font font, float x, float y): Node(x, y), text_(text) {
	font_ = font;
	rendererSetDimensions_ = true;
	collisionBitMask = "Text";
	textOptions_.push_back(text_);
	newSurfaces_ = std::queue<std::shared_ptr<SDL_Surface>>();
}

void Text::SetText(std::string text) {
	for (int i = 0; i < textOptions_.size(); i++) {
		if (textOptions_[i] == text) {
			currentForm_ = i;
			return;
		}
	}

	textOptions_.push_back(text);
	currentForm_ = textOptions_.size() - 1;
	auto fontTTF = font_.GetTTF();
	surface_ = integration::create_shared(TTF_RenderText_Solid(fontTTF.get(), text.c_str(), font_.GetColor()));
	surfaces_.push_back(surface_);
	newSurfaces_.push(surface_);
	status_ = TextureRender::kRenderNow;
}

void Text::ChangeFont(Font newFont) {
	font_.SetFont(newFont);
	//TODO: Re-render
	
	

}

void Text::ChangeColor(SDL_Color color) {
	font_.SetColor(color);
	//TODO: Re-render
}

void Text::CreateSurface(int i) {
	auto fontTTF = font_.GetTTF();
	surface_ = integration::create_shared(TTF_RenderText_Solid(fontTTF.get(), textOptions_[i].c_str(), font_.GetColor()));
	surfaces_.push_back(surface_);
}

void Text::GenerateSurfacesFromSources() {
	int i = 0;
	while (i < textOptions_.size()) {
		CreateSurface(i);
		i++;
	}
}

void Text::GetCurrentTexture() {

}
