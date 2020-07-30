#ifndef PHYSICS_H
#define PHYSICS_H

class Node;

struct Vector2D {
	double dx{0};
	double dy{0};
};

class Physics {
public:
	Physics(Node* node): node_(node) {}
	void SetGravity(double gravity_vel) { gravity_ = gravity_vel; }
	void Update();
private:
	//non-owning reference to Node
	//there is a unique_ptr to an object of this class in the Node class
	//The Node owns this object
	//This class needs to access the Node class to get x, y, width, and height values, for example
	Node* node_;
	Vector2D pvector_;
	double gravity_{0.0};
};

#endif
