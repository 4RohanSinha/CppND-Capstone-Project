#include "Engine.h"
#include <iostream>
Engine::Engine(int WindowWidth, int WindowHeight, std::string WindowTitle) {
	nodes_ = std::make_shared<std::vector<std::shared_ptr<Node>>>();
	renderer_ = std::make_unique<Renderer>(WindowWidth, WindowHeight, WindowTitle, nodes_);
	controller = std::make_unique<Controller>(nodes_);
	collideDetect = std::make_unique<CollisionDetector>(nodes_);
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

void Engine::SetPlayer(std::shared_ptr<Node> node) {
	renderer_->AddNode(node);
	player = node;
}

void Engine::RenderLoop() {
	collideDetect->CheckForCollisions();
	//TODO: abstract this part so that the user can call this function without accessing the Controller class directly
	controller->HandleKeyPressFor(KeyCharacter::kNone, [] () {
	});
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
