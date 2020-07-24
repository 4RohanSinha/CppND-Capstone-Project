#include "Engine.h"
#include <iostream>
#include <thread>
#include <future>

Engine::Engine(int WindowWidth, int WindowHeight, std::string WindowTitle) {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	renderer_ = std::make_unique<Renderer>(WindowWidth, WindowHeight, WindowTitle);
	controller = std::make_unique<Controller>();
}

void Engine::AddLayers(int n) {
	renderer_->AddLayers(n);
}

void Engine::AddToLayer(int layer, std::shared_ptr<Node> node) {
	renderer_->AddToLayer(layer, node);
}

void Engine::AddNode(std::shared_ptr<Node> node) {
	renderer_->AddNode(node);
}

void Engine::Loop() {
	controller->Update();
	renderer_->Update();
}

bool Engine::IsRunning() {
	return controller->IsRunning();
}

void Engine::ClearNode(std::shared_ptr<Node> node) {
	renderer_->ClearNode(node);
}

void Engine::HideNode(std::shared_ptr<Node> node) {
	renderer_->HideNode(node);
}

void Engine::ShowNode(std::shared_ptr<Node> node) {
	renderer_->ShowNode(node);

}
