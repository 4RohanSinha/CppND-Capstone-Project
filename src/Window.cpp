#include "Window.h"

Window::Window(int width, int height, std::string title): width_(width), height_(height), title_(title) {
	window_ = SDL_CreateWindow(title_.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_, height_, SDL_WINDOW_SHOWN);
	renderer_ = std::make_unique<Renderer>(window_);
	sceneManager = std::make_unique<SceneManager>(renderer_->getSDL());
}

Window::Window(Window&& other) {
	window_ = other.window_;
	renderer_ = std::move(other.renderer_);
	sceneManager = std::move(other.sceneManager);
	width_ = other.width_;
	height_ = other.height_;
	title_ = other.title_;

	other.window_ = nullptr;
	other.renderer_ = nullptr;
	other.sceneManager = nullptr;
	other.width_ = 0;
	other.height_ = 0;
	other.title_ = std::string();
}

Window& Window::operator=(Window&& other) {
	if (this == &other)
		return *this;
	window_ = other.window_;
	renderer_ = std::move(other.renderer_);
	sceneManager = std::move(other.sceneManager);
	width_ = other.width_;
	height_ = other.height_;
	title_ = other.title_;

	other.window_ = nullptr;
	other.renderer_ = nullptr;
	other.sceneManager = nullptr;
	other.width_ = 0;
	other.height_ = 0;
	other.title_ = "";
	return *this;
}

Window::~Window() {
	if (renderer_ != nullptr && window_ != nullptr) {
		renderer_ = nullptr; //ensure that the renderer is destroyed before the window to avoid memory leak
		SDL_DestroyWindow(window_);
		window_ = nullptr;
	}
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
