#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Renderer.h"
#include <iostream>
#include <memory>
using std::cout;

int main() {
	Renderer fw(200, 400);
	SDL_Event event;

	Font font = Font("Ubuntu-M", 300);
	Text* test = new Text("Hello World", font, 50, 50, 250, 50);
	fw.AddNode(test);
	while (!(event.type == SDL_QUIT)) {
		SDL_Delay(10);
		SDL_PollEvent(&event);
		fw.Update();
	}
	cout << "Hello, World\n";
	delete test;
}
