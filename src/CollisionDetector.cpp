#include "CollisionDetector.h"
#include <iostream>

void CollisionDetector::CheckForCollisions() {
	auto iWidth = ((nodeOne->rect_)->w)/2;	
	auto iHeight = ((nodeOne->rect_)->h)/2;	
	auto jWidth = ((nodeTwo->rect_)->w)/2;	
	auto jHeight = ((nodeTwo->rect_)->h)/2;	

	auto iCenterX = iWidth + (nodeOne->rect_)->x;
	auto iCenterY = iHeight + (nodeOne->rect_)->y;
	auto jCenterX = jWidth + (nodeTwo->rect_)->x;
	auto jCenterY = jHeight + (nodeTwo->rect_)->y;

	if (abs(iCenterX - jCenterX) > (iWidth + jWidth)) {
	
	} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
	
	} else if (nodeOne == nodeTwo) {       

	} else {
		Event collision = Event(EventType::kCollision, 2, nodeOne, nodeTwo);
		handlerFunction_();
	}

}
