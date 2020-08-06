#include "Engine.h"

Engine::Engine() {
	//initialize SDL and extension libraries
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG|MIX_INIT_MP3);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);
}

Engine::~Engine() {
	//assigning it to nullptr will cause the smart pointer to delete its internal raw pointer
	window = nullptr;

	//free all memory used for SDL and its extension libraries
	TTF_Quit();
	IMG_Quit();
	SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
}

Engine::Engine(Engine&& source) {
	//move all of the source's member variables to this
	//std::move already invalidates the source
	//just the source's unique_ptrs (Window, Timer) needs to be set to nullptr
	window = std::move(source.window);
	audioManager = std::move(source.audioManager);
	controller = std::move(source.controller);
	timer_ = std::move(source.timer_);
	source.window = nullptr;
	source.timer_ = nullptr;
	//the other objects are on the stack
	//std::move already invalidates them - the pointers just need to be set to nullptr
}

//same as above, but the assignment operator
Engine& Engine::operator=(Engine&& source) {
	if (this == &source)
		return *this;

	window = std::move(source.window);
	audioManager = std::move(source.audioManager);
	controller = std::move(source.controller);
	timer_ = std::move(source.timer_);
	
	source.window = nullptr;
	source.timer_ = nullptr;
	return *this;
}

//the engine gets the input and renders the current scene
void Engine::Loop() {
	controller.Update(); //controller's update also gets the input
	//the Update portion of the game loop is done in the implementation of the game itself
	if (window != nullptr)
		window->sceneManager->RenderCurrentScene(); //updates the rendering
}

//used to limit the game loop and break out of it when the window closes
bool Engine::IsRunning() {
	return controller.IsRunning();
}
