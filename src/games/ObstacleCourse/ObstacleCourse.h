#include "Game.h"
#include "CollisionManager.h"
#include "Projectile.h"
#include "Wall.h"

class ObstacleCourse: public Game {
public:
	ObstacleCourse();
	void Run();

private:
	//the SceneManager owns the Scene objects
	//these are nonowning references so that the scenes can be modified
	//the SceneManager returns raw pointers but stores scenes as unique pointers internally
	Scene* initialScene = nullptr;
	Scene* scene1 = nullptr;
	Scene* win_scene = nullptr;

	//shared pointers - shared between ObstacleCourse object and Scene object
	std::shared_ptr<Sprite> player = nullptr; //the sprite representing the player
	std::shared_ptr<Sprite> goal = nullptr; //sprite for the goal

	//stationary walls
	std::shared_ptr<Wall> wall1 = nullptr;
	std::shared_ptr<Wall> wall2 = nullptr;
	std::shared_ptr<Wall> wall3 = nullptr;
	std::shared_ptr<Wall> wall4 = nullptr;
	
	//moving walls
	std::shared_ptr<MovingWall> movingWall1 = nullptr;
	std::shared_ptr<MovingWall> movingWall2 = nullptr;
	std::shared_ptr<MovingWall> movingWall3 = nullptr;

	//horizontal projectiles
	std::shared_ptr<Projectile> projectile1 = nullptr;
	std::shared_ptr<Projectile> projectile2 = nullptr;
	std::shared_ptr<Projectile> projectile3 = nullptr;

	//random projectiles - move in any direction
	std::shared_ptr<DiagonalProjectile> diagProj1 = nullptr;
	std::shared_ptr<DiagonalProjectile> diagProj2 = nullptr;
	std::shared_ptr<DiagonalProjectile> diagProj3 = nullptr;

	//instructions text - is in an image for custom design
	std::shared_ptr<Sprite> instructions = nullptr;

	//you win text
	std::shared_ptr<Text> winText = nullptr;

	//collision manager
	CollisionManager collisionManager;

	//create node groups to simplify the collision detection
	NodeGroup projectiles;
	NodeGroup diagonalProjectiles;
	NodeGroup movingWalls;
	NodeGroup allWalls;
	NodeGroup mmWalls;
	NodeGroup diagWalls;
};
