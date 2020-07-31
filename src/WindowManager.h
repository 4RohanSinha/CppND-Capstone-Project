#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "Window.h"

class WindowManager {
public:
	WindowManager() {}
	void Update();
	Window* CreateNewWindow(std::string identifier, int width, int height, std::string title);
	Window* get(std::string identifier);
	Window& getRef(std::string identifier);
	void DestroyWindow(std::string identifier);
private:
	std::unordered_map<std::string, std::unique_ptr<Window>> windows_;
};

#endif
