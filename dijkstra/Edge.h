#ifndef EDGE_H
#define EDGE_H

class Node; //Vet inte om detta är vad man bör göra

class Edge {
public:
	
	/** Skapa en ny båge till noden destination, med längden length. */
	Edge(Node* destination, int length): dest(destination), length(length){ }
	
	/** Hämtar bågens destination. */
	Node* getDestination() const;
	
	/** Hämtar bågens längd. */
	int getLength() const;
	
private:
	Node* dest;
	int length;
	
};
#endif