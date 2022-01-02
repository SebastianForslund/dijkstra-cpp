#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Node.h"
#include "Graph.h"

using namespace std;

Graph::Graph() {
	
}

Graph::Graph(istream& in) {
	string input;
	string place;
	int cost;
	string connection;
	while(getline(in, input, '\n')) {
		if (!in.eof()) { //Sista raden har ingen newline
			input.pop_back();
		}
		auto index = input.find(':');
		place = input.substr(0, index);
		input.erase(0, index+2);
		index = input.find(' ');
		cost = stoi(input.substr(0, index));
		input.erase(0, index+1);
		index = input.find('\n');
		connection = input.substr(0, index);
		if (find(place) == NULL) {
			nodes.push_back(unique_ptr<Node>(new Node(place)));
		}
		auto originNode = find(place);
		if (find(connection) == NULL) {
			nodes.push_back(unique_ptr<Node>(new Node(connection)));
		}
		originNode->addEdge(find(connection), cost);
	}
}

vector<unique_ptr<Node>>::iterator Graph::end() {
	return nodes.end();
}

vector<unique_ptr<Node>>::iterator Graph::begin() {
	return nodes.begin();
}

void Graph::addNode(string name) {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		if ((*((*it).get())).getName() == name) {
			//lägg inte in, finns redan.
			return;
		}
	}
	nodes.push_back(unique_ptr<Node>(new Node(name)));
	return;
}
	
void Graph::resetVals() {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		(*((*it).get())).setValue(Node::max_value);
		// ^ Hoppas det finns bättre syntax för detta
	}
}

Node* Graph::find(string input) {
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		if ((*(*it).get()).getName() == input) {
			return (*it).get();
		}
	}
	return NULL;
}