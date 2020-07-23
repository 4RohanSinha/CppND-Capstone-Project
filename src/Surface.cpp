#include "Surface.h"

Surface::Surface(std::string text, Font font) {
	auto fontTTF = font.GetTTF();
	surface_ = integration::create_shared(TTF_RenderText_Solid(fontTTF.get(), text.c_str(), font.GetColor()));
}

std::shared_ptr<SDL_Surface> Surface::GetSDL() {
	return surface_;
}
