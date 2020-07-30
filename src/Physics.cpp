#include "Physics.h"
#include "Node.h"

void Physics::Update() {
	node_->x += pvector_.dx;
	node_->y += pvector_.dy;
}
