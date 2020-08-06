#ifndef ENGINE_H
#define ENGINE_H

#include "AudioManager.h"
#include "Window.h"
#include "Renderer.h"
#include "Timer.h"
#include "Controller.h"
#include "CollisionDetector.h"
#include "SceneManager.h"

class Engine {
public:
	//the Window object is initialized in the game
	std::unique_ptr<Window> window = nullptr;
	//stack-allocated objects
	AudioManager audioManager;
	Controller controller;

	//allocate memory for SDL and extension libraries
	Engine();
	//destructor - clean up memory used by SDL + extension libraries
	~Engine();
	//there should not be multiple duplicates of the Engine object at once
	Engine(const Engine& source) = delete;
	Engine& operator=(const Engine& source) = delete;
	//move constructors and assignment operators are permitted because they still only permit one copy of the Engine object at a time
	Engine(Engine&& source);
	Engine& operator=(Engine&& source);

	//code to execute on each iteration of the game loop
	void Loop();

	//returns data from Controller about whether program is still running
	bool IsRunning();
private:
	//the Timer class is adjusted depending on the speed of the game
	std::unique_ptr<Timer> timer_ = nullptr;
	SDL_Event event;
};

#endif
