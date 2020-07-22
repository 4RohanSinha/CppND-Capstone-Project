#include "CollisionDetector.h"
#include <iostream>

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
	
	} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
	
	} else if (nodeOne == nodeTwo) {       

	} else {
		handlerFunction_();
	}

}
