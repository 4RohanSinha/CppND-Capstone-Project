#include "Game.h"
#include "CollisionManager.h"
#include "Wall.h"

class ObstacleCourse: public Game {
public:
	ObstacleCourse();
	void Run();

private:
	Scene* scene1 = nullptr;
	Scene* scene2 = nullptr;
	Scene* win_scene = nullptr;
	Scene* lose_scene = nullptr;
	std::shared_ptr<Wall> wall1 = nullptr;
	std::shared_ptr<Wall> wall2 = nullptr;
	std::shared_ptr<Wall> wall3 = nullptr;
	std::shared_ptr<Wall> wall4 = nullptr;
	std::shared_ptr<MovingWall> movingWall1 = nullptr;
	std::shared_ptr<MovingWall> movingWall2 = nullptr;
	std::shared_ptr<MovingWall> movingWall3 = nullptr;
	std::shared_ptr<Sprite> player = nullptr;
	CollisionManager collisionManager;
	NodeGroup movingWalls;
	NodeGroup allWalls;
	NodeGroup mmWalls;
	int lives;
	void Setup();
};
