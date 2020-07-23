#ifndef ENGINE_H
#define ENGINE_H

#include "audio/AudioManager.h"
#include "rendering/Renderer.h"
#include "Timer.h"
#include "Controller.h"
#include "CollisionDetector.h"

class Engine {
public:
	AudioManager audioManager;
	std::unique_ptr<Controller> controller = nullptr;

	Engine(int WindowWidth, int WindowHeight, std::string WindowTitle);
	void AddLayers(int n);
	void AddToLayer(int layer, std::shared_ptr<Node> node);
	void AddNode(std::shared_ptr<Node> node);
	void RenderLoop();
	bool IsRunning();
	void ClearNode(std::shared_ptr<Node> node);
	void HideNode(std::shared_ptr<Node> node);
	void ShowNode(std::shared_ptr<Node> node);

	template<typename T>
	void HandleCollisionsBetween(std::shared_ptr<Node> nodeOne, std::shared_ptr<Node> nodeTwo, T handlerFunction) {
		controller->HandleCollisionsBetween(nodeOne, nodeTwo, handlerFunction);
	}

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
	std::unique_ptr<Renderer> renderer_ = nullptr;
	std::unique_ptr<Timer> timer_ = nullptr;
	SDL_Event event;
};

#endif
