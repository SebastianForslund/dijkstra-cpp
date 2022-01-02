#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <map>
#include <string>

#include "Node.h"
#include "Edge.h"
#include "NodeSet.h"
#include "Graph.h"


class Dijkstra {
public:
	static void dijkstra_old(Node* start); //Dijkstra without a "Graph" or value function
	static void dijkstra(Node* start, Graph* g, int (*valueFunc)(Edge e1));
private:
	static void addNeighbours_old(Node* node, std::map<std::string, int>* costMap, NodeSet* unvisited);
	static void addNeighbours(Node* node, std::map<std::string, int>* costMap, NodeSet* unvisited);
	static void recursiveListAdder(Node* origin, std::vector<std::string>* passes);
};
#endif