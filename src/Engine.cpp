#include "Engine.h"
#include "Window.h"
#include <iostream>
#include <thread>
#include <future>

Engine::Engine() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG|MIX_INIT_MP3);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	controller = std::make_unique<Controller>();
}

Engine::~Engine() {
	//reset is called on the unique_ptr window to call the destructor early
	//otherwise, it would get called too late (after SDL_Quit), which would cause a memory leak
	if (window != nullptr) {
		window.reset();
		window = nullptr;
	}
	TTF_Quit();
	IMG_Quit();
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

void Engine::Loop() {
	controller->Update();
	if (window != nullptr)
		window->sceneManager->RenderCurrentScene();
}

bool Engine::IsRunning() {
	return controller->IsRunning();
}
