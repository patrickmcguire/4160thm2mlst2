#include "Node.h"

Node::Node() {
	std::vector<Node> * children = new std::vector<Node>();
}

Node::~Node() {
	delete children;
}
