#ifndef NEW_COLLISION_DETECTOR_H
#define NEW_COLLISION_DETECTOR_H

#include <memory>

template <typename T>
class NewCollisionDetector {
public:
	NewCollisionDetector(std::shared_ptr<T> firstNode, std::shared_ptr<T> secondNode): nodeOne(firstNode), nodeTwo(secondNode) {}
	void operator()() { CheckForCollisions(); }
	bool IsColliding() const { return isColliding_; }
	bool CheckInitCollision() const { return initCollisionOccurred_; }
private:
	std::shared_ptr<T> nodeOne = nullptr;
	std::shared_ptr<T> nodeTwo = nullptr;
	bool initCollisionOccurred_;
	bool isColliding_;

	void CheckForCollisions();
};

#endif
