#include "Engine.h"
#include "Window.h"
#include <iostream>
#include <thread>
#include <future>

Engine::Engine() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	controller = std::make_unique<Controller>();
}

Engine::Engine(int WindowWidth, int WindowHeight, std::string WindowTitle) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
	windowManager.CreateNewWindow("main", WindowWidth, WindowHeight, WindowTitle);
	controller = std::make_unique<Controller>();
}

Engine::~Engine() {
	TTF_Quit();
	IMG_Quit();
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

void Engine::Loop() {
	controller->Update();
	windowManager.Update();
}

bool Engine::IsRunning() {
	return controller->IsRunning();
}
