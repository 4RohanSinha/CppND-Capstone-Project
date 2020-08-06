#include "Surface.h"

Surface::Surface(std::string text, Font font) {
	auto fontTTF = font.GetTTF();
	//using custom deleter with std::shared_ptr & std::unique_ptr: https://thispointer.com/shared_ptr-and-custom-deletor/
//https://blog.galowicz.de/2016/02/21/automatic_resource_release_with_sdl/

	//custom deleter is required because an SDL_Surface is freed differently - it does not use the delete keyword
	//RAII could have been used, but this was just something new to try out
	surface_ = std::shared_ptr<SDL_Surface>(TTF_RenderText_Solid(fontTTF.get(), text.c_str(), font.GetColor()), SDL_Deleter());
}

std::shared_ptr<SDL_Surface> Surface::GetSDL() {
	return surface_;
}
