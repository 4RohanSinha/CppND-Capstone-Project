#include "Window.h"
#include "rendering/Renderer.h"

Window::Window(int width, int height, std::string title): width_(width), height_(height), title_(title) {
	window_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, 0);
	renderer_ = std::make_unique<Renderer>(window_);
	sceneManager = std::make_unique<SceneManager>(renderer_->getSDL());
}

Window::~Window() {
	SDL_DestroyWindow(window_);
	window_ = nullptr;
}

void Window::SetTitle(std::string new_title) {
	title_ = new_title;
	SDL_SetWindowTitle(window_, new_title.c_str());
}

void Window::SetWidth(int w) {
	width_ = w;
	SDL_SetWindowSize(window_, width_, height_);
}

void Window::SetHeight(int h) {
	height_ = h;
	SDL_SetWindowSize(window_, width_, height_);
}

void Window::SetDimensions(int w, int h) {
	width_ = w;
	height_ = h;
	SDL_SetWindowSize(window_, width_, height_);
}
