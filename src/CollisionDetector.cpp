#include "CollisionDetector.h"
#include <iostream>

void CollisionDetector::CheckForCollisions() {
	for (auto i: *nodes_) {
		for (auto j: *nodes_) {
			auto iWidth = ((i->rect_)->w)/2;	
			auto iHeight = ((i->rect_)->h)/2;	
			auto jWidth = ((j->rect_)->w)/2;	
			auto jHeight = ((j->rect_)->h)/2;	

			auto iCenterX = iWidth + (i->rect_)->x;
			auto iCenterY = iHeight + (i->rect_)->y;
			auto jCenterX = jWidth + (j->rect_)->x;
			auto jCenterY = jHeight + (j->rect_)->y;

			if (abs(iCenterX - jCenterX) > (iWidth + jWidth)) {
			
			} else if (abs(iCenterY - jCenterY) > (iHeight + jHeight)) {
			
			} else if (i == j) {       

			} else {
				Event collision = Event(EventType::kCollision, 2, i, j);
				collisions_.push(collision);
			}

		}
	}
}
