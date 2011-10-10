#include "Node.h"

Node::Node() {
	std::vector<Node> * children = new std::vector<Node>();
}

Node::~Node() {
	children->erase(children->begin(), children->end());
	delete children;
}

void Node::draw() {}


