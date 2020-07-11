#ifndef ENGINE_H
#define ENGINE_H

#include "Renderer.h"
#include "Controller.h"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight, std::string WindowTitle);
	void AddLayers(int n);
	void AddToLayer(int layer, std::shared_ptr<Node> node);
	void AddNode(std::shared_ptr<Node> node);
	void AssignPlayer(std::shared_ptr<Node> node);
	void RenderLoop();
	bool IsRunning();
	void ClearNode(std::shared_ptr<Node> node);
	void HideNode(std::shared_ptr<Node> node);
	void ShowNode(std::shared_ptr<Node> node);
private:
	std::unique_ptr<Renderer> renderer_ = nullptr;
	std::unique_ptr<Controller> controller_ = nullptr;
	std::shared_ptr<Node> player = nullptr;
	SDL_Event event;
};

#endif
