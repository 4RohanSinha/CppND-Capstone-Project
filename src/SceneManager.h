#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Camera.h"
#include "Scene.h"
#include <string>
#include <unordered_map>

class SceneManager {
public:
	SceneManager(std::shared_ptr<SDL_Renderer> renderer): renderer_(renderer) {}
	std::shared_ptr<Scene> CreateNewScene(std::string identifier);
	void AddScene(std::shared_ptr<Scene> scene, std::string identifier);
	void ShowScene(std::string identifier);
	std::string GetCurrentScene() { return currentScene_; }
	void RenderCurrentScene();
	void DeleteScene(std::string identifier);
private:
	std::shared_ptr<SDL_Renderer> renderer_;
	std::unordered_map<std::string, std::shared_ptr<Scene>> scenes_;
	std::string currentScene_;
	Camera camera_;
};

#endif
