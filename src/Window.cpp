#include "Window.h"
#include "rendering/Renderer.h"
#include "Integrate.h"

Window::Window(int width, int height, std::string title): width_(width), height_(height), title_(title) {
	window_ = (SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, 0));
	renderer = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	sceneManager = std::make_unique<SceneManager>(renderer);
}


Window::Window(Window&& other) {
	window_ = other.window_;
	renderer = other.renderer;
	sceneManager = std::move(other.sceneManager);
	width_ = other.width_;
	height_ = other.height_;
	title_ = other.title_;

	other.window_ = nullptr;
	other.renderer = nullptr;
	other.sceneManager = nullptr;
	other.width_ = 0;
	other.height_ = 0;
	other.title_ = std::string();
}

Window& Window::operator=(Window&& other) {
	if (this == &other)
		return *this;
	window_ = other.window_;
	renderer = other.renderer;
	sceneManager = std::move(other.sceneManager);
	width_ = other.width_;
	height_ = other.height_;
	title_ = other.title_;

	other.window_ = nullptr;
	other.renderer = nullptr;
	other.sceneManager = nullptr;
	other.width_ = 0;
	other.height_ = 0;
	other.title_ = "";
	return *this;
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window_);
}

void Window::SetTitle(std::string new_title) {
	title_ = new_title;
	SDL_SetWindowTitle(window_, new_title.c_str());}

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

void Window::Hide() {
	SDL_HideWindow(window_);
}

void Window::Show() {
	SDL_ShowWindow(window_);
}
