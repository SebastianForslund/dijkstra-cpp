#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

#include "dijkstra.h"
#include "Edge.h"
#include "Node.h"
#include "NodeSet.h"
#include "Graph.h"

using std::string;
using std::vector;
using std::pair;
using std::cout;
using std::endl;


void Dijkstra::dijkstra(Node* start, Graph* g, int (*valueFunc)(Edge e1)) {
	vector<Node*> visited;
	NodeSet unvisited;
	start->setValue(0);
	unvisited.add(start);
	std::map<string, int> costMap;
	costMap.insert(pair<string, int>(start->getName(), 0));
	
	while(!unvisited.isEmpty()) {
		Node* currentNode = unvisited.removeMin();
		addNeighbours_old(currentNode, &costMap, &unvisited);
		auto neighbours = currentNode->getEdges();
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) { //Check the new distances
			int newValue;
			newValue = costMap[currentNode->getName()] + valueFunc((*it));
			int oldValue = costMap[(*it).getDestination()->getName()];
			if (newValue < oldValue) {
				costMap[(*it).getDestination()->getName()] = newValue;
				(*it).getDestination()->setValue(newValue);
				(*it).getDestination()->setParent(currentNode);
			}
		}
		visited.push_back(currentNode);
	}
	
	cout << endl << "Shortest paths to every node: " << endl;
	
	for (auto it = g->begin(); it != g->end(); ++it) {
		cout << "Name: " << (*it).get()->getName() << " Value: " << (*it).get()->getValue() << endl;
		vector<string> passes;
		recursiveListAdder((*it).get(), &passes);
		for (auto it = passes.rbegin(); it != passes.rend(); ++it) {
			cout << *it << " -> ";
		}
		cout << endl << endl;
	}
}

void Dijkstra::recursiveListAdder(Node* origin, vector<string>* passes) {
	if (origin == nullptr) {
		return;
	}
	passes->push_back(origin->getName());
	recursiveListAdder(origin->getParent(), passes);
}

void Dijkstra::addNeighbours(Node* node, std::map<std::string, int>* costMap, NodeSet* unvisited) {
	auto neighbours = node->getEdges();
	for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
		/*
			Only if it has never been seen in the graph before
			//find(visited->begin(), visited->end(), *it) == visited->end()
		*/
			if (costMap->find((*it).getDestination()->getName()) == costMap->end()) {
				unvisited->add((*it).getDestination());
				costMap->insert(pair<string, int>((*it).getDestination()->getName(), INT_MAX));
			}
		}
}

void Dijkstra::dijkstra_old(Node* start) {	//Dijkstra without a "Graph" or value function
	vector<Node*> visited;
	NodeSet unvisited;
	start->setValue(0);
	unvisited.add(start);
	std::map<string, int> costMap;
	costMap.insert(pair<string, int>(start->getName(), 0));
	
	while(!unvisited.isEmpty()) {
		Node* currentNode = unvisited.removeMin();
		addNeighbours_old(currentNode, &costMap, &unvisited);
		auto neighbours = currentNode->getEdges();
		for (auto it = neighbours.begin(); it != neighbours.end(); ++it) { //Check the new distances
			int newValue;
			newValue = costMap[currentNode->getName()] + (*it).getLength(); //*it->getValue() funkar inte, måste kolla i costMap.
			int oldValue = costMap[(*it).getDestination()->getName()];
			if (newValue < oldValue) {
				costMap[(*it).getDestination()->getName()] = newValue;
				(*it).getDestination()->setValue(newValue);
				(*it).getDestination()->setParent(currentNode);
			}
		}
		visited.push_back(currentNode);
	}
	for (auto it = costMap.begin(); it != costMap.end(); ++it) {
		cout << it->first << " => " << it->second << endl;
	}
}

/*
	Adds unvisited neighbours of node to the costMap and unvisited.
*/
void Dijkstra::addNeighbours_old(Node* node, std::map<string, int>* costMap, NodeSet* unvisited) {
	auto neighbours = node->getEdges();
	for (auto it = neighbours.begin(); it != neighbours.end(); ++it) {
		/*
			Only if it has never been seen in the graph before
			//find(visited->begin(), visited->end(), *it) == visited->end()
		*/
			if (costMap->find((*it).getDestination()->getName()) == costMap->end()) {
				unvisited->add((*it).getDestination());
				costMap->insert(pair<string, int>((*it).getDestination()->getName(), INT_MAX));
			}
		}
}