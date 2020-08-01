#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <memory>
#include "SceneManager.h"
#include "rendering/Renderer.h"

//TODO: fix errors with multiple windows in event handling

class Window {
public:
	Window() {}
	Window(int width, int height, std::string title);
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	Window(Window&& other);
	Window& operator=(Window&& other);
	~Window();
	void SetTitle(std::string new_title);
	std::string GetTitle() {return title_; }
	int GetWidth() { return width_; }
	int GetHeight() { return height_; }
	void SetWidth(int w);
	void SetHeight(int h);
	void SetDimensions(int w, int h);
	SDL_Window* get() { return window_; }
	
	std::unique_ptr<SceneManager> sceneManager = nullptr;
private:
	int width_;
	int height_;
	std::string title_;
	SDL_Window* window_ = nullptr; //All SDL objects must be allocated and freed according to their specific functions, so RAII is used to manage them
	SDL_Renderer* renderer = nullptr;
};

#endif
