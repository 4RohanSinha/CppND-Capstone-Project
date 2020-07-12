#ifndef ENGINE_H
#define ENGINE_H

#include "Renderer.h"
#include "Timer.h"
#include "Controller.h"
#include "CollisionDetector.h"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight, std::string WindowTitle);
	void AddLayers(int n);
	void AddToLayer(int layer, std::shared_ptr<Node> node);
	void AddNode(std::shared_ptr<Node> node);
	void SetPlayer(std::shared_ptr<Node> node);
	void RenderLoop();
	bool IsRunning();
	void ClearNode(std::shared_ptr<Node> node);
	void HideNode(std::shared_ptr<Node> node);
	void ShowNode(std::shared_ptr<Node> node);
private:
	std::unique_ptr<Renderer> renderer_ = nullptr;
	std::unique_ptr<Timer> timer_ = nullptr;
	std::unique_ptr<CollisionDetector> collideDetect = nullptr;
	std::unique_ptr<Controller> controller = nullptr;
	std::shared_ptr<Node> player = nullptr;
	std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes_;
	SDL_Event event;
};

#endif
