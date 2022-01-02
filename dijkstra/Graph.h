#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <memory>

#include "Node.h"

using namespace std;

class Graph {
public:
	Graph(istream& in);
	
	vector<unique_ptr<Node>>::iterator end();
	
	vector<unique_ptr<Node>>::iterator begin();
	
	Graph();
	
	void addNode(string name);
	
	void resetVals();
	
	Node* find(string input);
	
private:
	vector<unique_ptr<Node>> nodes;
};
#endif