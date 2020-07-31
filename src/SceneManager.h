#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Camera.h"
#include "Scene.h"
#include <iostream>
#include <string>
#include <unordered_map>

class SceneManager {
public:
	SceneManager(SDL_Renderer* renderer): renderer_(renderer) {}
	Scene* CreateNewScene(std::string identifier);
	Scene* get(std::string identifier);
	Scene& getRef(std::string identifier);
	void ShowScene(std::string identifier);
	std::string GetCurrentScene() { return currentScene_; }
	void RenderCurrentScene();
	void DeleteScene(std::string identifier);
private:
	SDL_Renderer* renderer_;
	std::unordered_map<std::string, std::unique_ptr<Scene>> scenes_;
	std::string currentScene_;
	Camera camera_;
};

#endif
