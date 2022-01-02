#include <string>
#include <limits>
#include <iostream>
#include <algorithm>

#include "NodeSet.h"

using namespace std;

NodeSet::NodeSet() {
	
}

void NodeSet::add(Node* node) {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		if (*it == node) {
			return;
		}
	}
	nodes.push_back(node);
}

bool NodeSet::isEmpty() {
	return nodes.size() == 0;
}

Node* NodeSet::removeMin() {
	if (isEmpty()) {
		return NULL;
	}
	size_t minPos = 0;
	for (size_t i = 0; i < nodes.size(); ++i) {
		if (nodes.at(i)->getValue() < nodes.at(minPos)->getValue()) {
			minPos = i;
		}
	}
	Node* temp = nodes.at(minPos);
	nodes.erase(nodes.begin() + minPos);
	return temp;
}