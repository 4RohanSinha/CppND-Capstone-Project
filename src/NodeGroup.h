#ifndef NODE_GROUP_H
#define NODE_GROUP_H

#include "Node.h"

class NodeGroup {
public:
	NodeGroup() {}
	void AddNode(std::shared_ptr<Node> node);
	void DeleteNode(int ind);
	std::shared_ptr<Node> operator[](int ind);	
	int size();
private:
	std::vector<std::shared_ptr<Node>> nodes_;
};

#endif
