#ifndef ENGINE_H
#define ENGINE_H

#include "audio/AudioManager.h"
#include "Window.h"
#include "Renderer.h"
#include "Timer.h"
#include "Controller.h"
#include "CollisionDetector.h"
#include "SceneManager.h"

class Engine {
public:
	std::unique_ptr<Window> window = nullptr;
	AudioManager audioManager;
	std::unique_ptr<Controller> controller = nullptr;

	Engine();
	Engine(int WindowWidth, int WindowHeight, std::string WindowTitle);
	~Engine();
	//there should not be multiple engines at once
	//also, the engine should not be moved
	Engine(const Engine& source) = delete;
	Engine& operator=(const Engine& source) = delete;
	Engine(Engine&& source) = delete;
	Engine& operator=(Engine&& source) = delete;

	void Loop();
	bool IsRunning();
	template<typename T>
	void HandleKeyPressFor(KeyCharacter key, T handlerFunction) {
		controller->HandleKeyPressFor(key, handlerFunction);
	}

	template<typename T>
	void HandleKeyPressFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		controller->HandleKeyPressFor(keys, handlerFunction);
	}

	template<typename T>
	void HandleKeyUpFor(KeyCharacter key, T handlerFunction) {
		controller->HandleKeyUpFor(key, handlerFunction);
	}

	template<typename T>
	void HandleKeyUpFor(std::initializer_list<KeyCharacter> keys, T handlerFunction) {
		controller->HandleKeyUpFor(keys, handlerFunction);
	}
private:
	std::unique_ptr<Timer> timer_ = nullptr;
	SDL_Event event;
};

#endif
