#include "CollisionDetector.h"
#include <iostream>
#include <chrono>
#include <thread>

void CollisionDetector::CheckForCollisions() {
	auto iWidth = (nodeOne->width_)/2;	
	auto iHeight = (nodeOne->height_)/2;	
	auto jWidth = (nodeTwo->width_)/2;	
	auto jHeight = (nodeTwo->height_)/2;	

	auto iCenterX = iWidth + (nodeOne->x);
	auto iCenterY = iHeight + (nodeOne->y);
	auto jCenterX = jWidth + (nodeTwo->x);
	auto jCenterY = jHeight + (nodeTwo->y);

	if (abs(iCenterX - jCenterX) > (iWidth + jWidth)) {
		isColliding_ = false;	
	} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
		isColliding_ = false;	
	
	} else if (nodeOne == nodeTwo) {       
		isColliding_ = false;	

	} else if (isColliding_) {
	
	} else {
		isColliding_ = true;
		handlerFunction_();
	}

}
