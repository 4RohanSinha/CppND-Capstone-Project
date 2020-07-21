#include "CollisionDetector.h"
#include <iostream>

void CollisionDetector::CheckForCollisions() {
	auto iWidth = (nodeOne->GetWidth())/2;	
	auto iHeight = (nodeOne->GetHeight())/2;	
	auto jWidth = (nodeTwo->GetWidth())/2;	
	auto jHeight = (nodeTwo->GetHeight())/2;	

	auto iCenterX = iWidth + (nodeOne->x);
	auto iCenterY = iHeight + (nodeOne->y);
	auto jCenterX = jWidth + (nodeTwo->x);
	auto jCenterY = jHeight + (nodeTwo->y);

	if (abs(iCenterX - jCenterX) > (iWidth + jWidth)) {
	
	} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
	
	} else if (nodeOne == nodeTwo) {       

	} else {
		Event collision = Event(EventType::kCollision, 2, nodeOne, nodeTwo);
		handlerFunction_();
	}

}
