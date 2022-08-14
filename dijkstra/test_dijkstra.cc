#include <iostream>
#include <cassert>
#include <fstream>

#include "Graph.h"
#include "dijkstra.h"

using std::cout;
using std::endl;

void test()
{
    ifstream graf;
	graf.open("graf.txt");
    Graph g(graf);
	
	//Vanlig dijkstra
    Dijkstra::dijkstra(g.find("Lund"), &g, [](Edge e1) {
		return e1.getLength();
	});
	assert(g.find("Bjarred")->getValue() == 17);
	assert(g.find("Staffanstorp")->getValue() == 12);
	assert(g.find("Kavlinge")->getValue() == 19);
	assert(g.find("Dalby")->getValue() == 12);
	assert(g.find("Lund")->getValue() == 0);
	assert(g.find("Veberod")->getValue() == 23);
	
	g.resetVals();
	//Denna kollar antalet noder passerade
	Dijkstra::dijkstra(g.find("Lund"), &g, [](Edge e1) {
		return 1;
	});
	//Svaren här kommer vara 1 lägre än vad de borde, startnoden har alltid 0 som värde.
    assert(g.find("Staffanstorp")->getValue() == 1);
	assert(g.find("Torna Hallestad")->getValue() == 2);
	assert(g.find("Flyinge")->getValue() == 2);
	assert(g.find("Bjarred")->getValue() == 2);
	assert(g.find("Lund")->getValue() == 0);

#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "Test for the generalized dijkstra passed." << endl;
}

void test_old()
{
    Node lund{"Lund"};
    Node dalby{"Dalby"};
    Node sandby{"Sodra Sandby"};
    Node hallestad{"Torna Hallestad"};
    Node flyinge{"Flyinge"};
    Node veberod{"Veberod"};

    lund.addEdge(&dalby,12);
    lund.addEdge(&sandby,12);
    dalby.addEdge(&sandby,12);
    dalby.addEdge(&veberod,11);
    dalby.addEdge(&hallestad,5);
    sandby.addEdge(&lund,12);
    sandby.addEdge(&flyinge,4);
    hallestad.addEdge(&veberod,8);
	
    Dijkstra::dijkstra_old(&lund);

    assert(lund.getValue() == 0);
    assert(dalby.getValue() == 12);
    assert(sandby.getValue() == 12);
    assert(hallestad.getValue() == 17);
    assert(veberod.getValue() == 23);
    assert(flyinge.getValue() == 16);
	
	/*
		Kolla getParent()
	*/
	assert(sandby.getParent()->getName() == "Lund");
	assert(veberod.getParent()->getName() == "Dalby");
	assert(flyinge.getParent()->getName() == "Sodra Sandby");
	assert(lund.getParent() == nullptr);
	

#ifdef INFO
    cout << "----\nAll distances from Lund:\n";

    for(auto& t : {lund, dalby, sandby, hallestad, veberod, flyinge}) {
        cout << t.getName() << " : " << t.getValue() << " ";
        cout << endl;
    }
#endif
    cout << "Test for the non generalised dijkstra passed" << endl;
}


int main()
{
    test_old();
	test();
    return 0;
}
