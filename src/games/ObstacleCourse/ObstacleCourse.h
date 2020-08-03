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
	std::unique_ptr<CollisionDetector> mv1ToWall = nullptr;
	std::unique_ptr<CollisionDetector> mv1ToWall2 = nullptr;
	std::unique_ptr<CollisionDetector> mv2ToWall = nullptr;
	std::unique_ptr<CollisionDetector> mv2ToWall2 = nullptr;
	std::unique_ptr<CollisionDetector> mv3ToWall = nullptr;
	std::unique_ptr<CollisionDetector> mv3ToWall2 = nullptr;
	std::unique_ptr<CollisionDetector> playerWall1 = nullptr;
	std::unique_ptr<CollisionDetector> playerWall2 = nullptr;
	std::unique_ptr<CollisionDetector> playerWall3 = nullptr;
	std::unique_ptr<CollisionDetector> playerWall4 = nullptr;
	std::unique_ptr<CollisionDetector> playerMv1 = nullptr;
	std::unique_ptr<CollisionDetector> playerMv2 = nullptr;
	std::unique_ptr<CollisionDetector> playerMv3 = nullptr;
	int lives;
	void Setup();
};
