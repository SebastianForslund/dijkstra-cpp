#include <string>

#include "Edge.h"
using namespace std;

Node* Edge::getDestination() const {
	return this->dest;
}

int Edge::getLength() const {
	return this->length;
}