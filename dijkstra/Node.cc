#include <string>

#include "Node.h"

using namespace std;

std::string Node::getName() const {
	return name;
}

void Node::setParent(Node* in) {
	parent = in;
}
	
Node* Node::getParent() {
	return parent;
}

void Node::setValue(int v) {
	value = v;
}

int Node::getValue() const {
	return value;
}

void Node::addEdge(Node* destination, int length) {
	adjacentEdges.push_back(Edge(destination, length));
}

const vector<Edge>& Node::getEdges() const {
	return adjacentEdges;
}