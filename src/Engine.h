#include "Renderer.h"

class Engine {
public:
	Engine(int WindowWidth, int WindowHeight);
	void AddNode(Node* node);
	void RenderLoop();
	bool IsRunning();
	void ClearNode(Node* node);
	void HideNode(Node* node);
	void ShowNode(Node* node);
	~Engine();
private:
	Renderer* renderer_;
	SDL_Event event;
};
