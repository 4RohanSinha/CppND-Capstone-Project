#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include <string>
#include <unordered_map>

class SceneManager {
public:
	SceneManager() {}
	void AddScene(Scene& scene, std::string identifier);
	void ShowScene(std::string identifier);
	void DeleteScene(std::string identifier);
private:
	std::unordered_map<std::string, Scene> scenes_;
	std::string currentScene_;
};

#endif
