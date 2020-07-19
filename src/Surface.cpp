#include "Surface.h"

Surface::Surface(std::string text, Font font) {
	font.SDLConvert();
	TTF_Font* fontTTF = font.GetTTF();
	surface_ = GetSharedPtr(TTF_RenderText_Solid(fontTTF, text.c_str(), font.GetColor()));
	font.DeleteTTF();
}

std::shared_ptr<SDL_Surface> Surface::GetSDL() {
	return surface_;
}
