#include "CollisionDetector.h"
#include <iostream>

void CollisionDetector::CheckForCollisions() {
	if (nodeOne == nullptr || nodeTwo == nullptr) return;
	auto iWidth = (nodeOne->width)/2;	
	auto iHeight = (nodeOne->height)/2;	
	auto jWidth = (nodeTwo->width)/2;	
	auto jHeight = (nodeTwo->height)/2;	

	auto iCenterX = iWidth + (nodeOne->x);
	auto iCenterY = iHeight + (nodeOne->y);
	auto jCenterX = jWidth + (nodeTwo->x);
	auto jCenterY = jHeight + (nodeTwo->y);

	if (abs(iCenterX - jCenterX) > (iWidth + jWidth)) {
		isColliding_ = false;	
		initCollide_ = false;

	} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
		isColliding_ = false;	
		initCollide_ = false;
	
	} else if (nodeOne == nodeTwo) {       
		isColliding_ = false;	
		initCollide_ = false;

	} else if (isColliding_) {
		initCollide_ = false;

	} else {
		isColliding_ = true;
		initCollide_ = true;
		if (handlerFunction_)
			handlerFunction_();
	}

}
