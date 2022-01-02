#include <iostream>
#include <cassert>
#include "Graph.h"
#include <algorithm>
#include <utility>
#include <set>
#include <fstream>

using namespace std;

void print_neighbours(Node* n)
{
    cout << "Anslutningar från " << n->getName() << "(" << n->getValue() << ") :\n";
    for(auto de : n->getEdges()){
        cout << de.getLength() << " to " << de.getDestination()->getName() << endl;
    }
}

Node* find_and_test(const string& s, Graph& g)
{
	cout << "Asserting: " << s << endl;
    Node * n = g.find(s);
    assert(n != nullptr);
    assert(n->getName() == s);
    assert(n->getValue() == Node::max_value);
    return n;
}

void test_graph()
{
	ifstream graf;
	graf.open("graf.txt");
    Graph g(graf);

    auto n_lund = find_and_test("Lund", g);
    find_and_test("Dalby", g);
    find_and_test("Sodra Sandby", g);
    find_and_test("Veberod", g);
    find_and_test("Torna Hallestad", g);
    auto n_lomma = find_and_test("Lomma", g);

    n_lund->setValue(17);
    auto n2 = g.find("Lund");
    assert(n2->getValue()==17);

    auto n3 = g.find("Lomma");
    n_lomma->setValue(42);
    assert(n3->getValue()==42);

    g.resetVals();
    for(auto it = g.begin(); it != g.end(); ++it){
        assert((*it)->getValue() == Node::max_value); 
		// ^ Trodde inte detta skulle funka med min iterator
    }

    cout << "test_graph passed" << endl;
}


int main()
{
    test_graph();
    return 0;
}
