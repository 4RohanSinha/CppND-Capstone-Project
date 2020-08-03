#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <memory>
#include "SceneManager.h"
#include "rendering/Renderer.h"

class Window {
public:
	Window() {}
	Window(int width, int height, std::string title);
	//copying windows is not permitted because for this project, there may only be one window open at a time.
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
	void Hide();
	void Show();	
	std::unique_ptr<SceneManager> sceneManager = nullptr;
private:
	int width_;
	int height_;
	std::string title_;
	SDL_Window* window_ = nullptr; //All SDL objects must be allocated and freed according to their specific functions, so RAII is used to manage them
	SDL_Renderer* renderer = nullptr;
};

#endif
