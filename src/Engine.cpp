#include "Engine.h"

Engine::Engine(int WindowWidth, int WindowHeight) {
	renderer_ = new Renderer(WindowWidth, WindowHeight);
}

void Engine::AddNode(Node* node) {
	renderer_->AddNode(node);
}

void Engine::RenderLoop() {
	SDL_Delay(10);
	SDL_PollEvent(&event);
	renderer_->Update();
}

bool Engine::IsRunning() {
	return !(event.type == SDL_QUIT);
}

void Engine::ClearNode(Node* node) {
	renderer_->ClearNode(node);
}

void Engine::HideNode(Node* node) {
	renderer_->HideNode(node);
}

void Engine::ShowNode(Node* node) {
	renderer_->ShowNode(node);
}

Engine::~Engine() {
	delete renderer_;
}
