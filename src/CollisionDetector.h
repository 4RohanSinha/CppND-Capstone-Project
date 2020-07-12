#ifndef COLLISION_DETECTOR
#define COLLISION_DETECTOR

#include <vector>
#include <memory>
#include <thread>
#include <mutex>
#include "Node.h"
#include "Event.h"

class CollisionDetector {
public:
	CollisionDetector(std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes) { nodes_ = nodes; }

	void CheckForCollisions();

	
private:
	std::shared_ptr<std::vector<std::shared_ptr<Node>>> nodes_;	
	std::queue<Event> collisions_;	
};

#endif
