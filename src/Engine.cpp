#include "Engine.h"

Engine::Engine(int WindowWidth, int WindowHeight, std::string WindowTitle) {
	renderer_ = std::make_unique<Renderer>(WindowWidth, WindowHeight, WindowTitle);
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

void Engine::AssignPlayer(std::shared_ptr<Node> node) {
	renderer_->AddNode(node);
	player = node;
}

void Engine::RenderLoop() {
	SDL_Delay(8);
	SDL_PollEvent(&event);
	renderer_->Update();
}

bool Engine::IsRunning() {
	return !(event.type == SDL_QUIT);
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
