#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>
#include <climits>

#include "Edge.h"

class Edge; //Vet inte om detta är vad man bör göra

class Node {
public:
	/** Skapar en nod med givet namn, utan bågar och med maximalt värde. */
	Node(const std::string& name): name(name), value(INT_MAX), parent(nullptr){ }
	
	void setParent(Node* in);
	
	Node* getParent();
	
	/** Hämtar nodens namn. */
	std::string getName() const;
	
	/** Sätter nodens värde till v. */
	void setValue(int v);
	
	/** Hämtar nodens värde. */
	int getValue() const;
	
	/** Lägger till en ny båge från denna nod till en given destination.
	Bågen ska ha längden length. */
	void addEdge(Node* destination, int length);
	
	/** Hämtar de bågar som utgår från denna nod. */
	const std::vector<Edge>& getEdges() const;
	
	static const int max_value = INT_MAX;
private:
	std::vector<Edge> adjacentEdges;
	std::string name;
	int value;
	Node* parent;
	
};
#endif