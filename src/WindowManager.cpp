#include "Window.h"
#include "rendering/Renderer.h"
#include "WindowManager.h"
#include <algorithm>

Window* WindowManager::CreateNewWindow(std::string identifier, int width, int height, std::string title) {
	windows_[identifier] = std::make_unique<Window>(width, height, title);
	return windows_[identifier].get();
}

void WindowManager::Update() {
	for (auto it = windows_.begin(); it != windows_.end(); it++) {
		(it->second)->sceneManager->RenderCurrentScene();
	}
}

Window* WindowManager::get(std::string identifier) {
	return windows_[identifier].get();
}

Window& WindowManager::getRef(std::string identifier) {
	return *(windows_[identifier]);
}

void WindowManager::DestroyWindow(std::string identifier) {
	windows_.erase(identifier);
}
