#include <iostream>
#include <string>
#include "marble.hpp"
#include "arbitrary-list.hpp"
#include "graph.hpp"
#include "graph_node.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

string testInput;

int main() {
    cout << "Do you want to start marble test? Y to start. Any other input to cancel. " << endl;
    cin >> testInput;
    if (testInput == "Y") {
        marbleBag myMarbleBag;
        myMarbleBag.showMarbles(); //Should print zero as marble bag is empty. Also shows function works
        
        //Test function to add marbles
        cout << "Adding 20 marbles." << endl;
        myMarbleBag.changeMarbles(20);
        myMarbleBag.showMarbles();

        // Test function to add too many marbles
        cout << "Attempting to add over 1000 marbles." << endl;
        myMarbleBag.changeMarbles(1200);
        myMarbleBag.showMarbles();

        //Test function to remove marbles
        cout << "Attempting to remove 10 marbles." << endl;
        myMarbleBag.changeMarbles(-10);
        myMarbleBag.showMarbles();

        //Test function to remove more marbles than are in the bag.
        cout << "Attempting to remove more marbles than the bag has." << endl;
        myMarbleBag.changeMarbles(-500);
        myMarbleBag.showMarbles();

        cout << "Test concluded";
    } else {
        cout << "Marble test will not run." << endl;
    };

    cout << "Do you want to start arbitrary-list test? Y to start. Any other input to cancel." << endl;
    cin >> testInput;
    if (testInput == "Y") {
        arbitraryList arblist;
        arblist.showData(0);
        arblist.showData(0);
        arblist.insert(7, 0);
        arblist.insert(6, 0);
        arblist.insert(5, 0);
        arblist.insert(4, 0);
        arblist.insert(3, 0);
        arblist.insert(2, 0);
        arblist.insert(1, 0);
        cout << "Added data to first seven positions" << endl;
        cout << "data in position 3: ";
        arblist.showData(3);
        arblist.remove(3);
        cout << "Data should have been removed and replaced with next position, being 5." << endl;
        arblist.showData(3);
        cout << "Test for going out of bounds" << endl;
        arblist.insert(10,10);
        arblist.remove(10);
        arblist.showData(10);

        cout << "Test concluded" << endl;
    } else {
        cout << "Arbitrary list will not be run" << endl;
    };

    cout << "Hello" << endl;
    
    //Show functional graph
    Graph myGraph;

    //Create edge to test simple edge situations

    //Creating nodes
    myGraph.addNode("Node1");
    cout << "Node1 has been created." << endl;
    myGraph.addNode("Node2");
    cout << "Node2 has been created." << endl;
    myGraph.addNode("Node3");
    cout << "Node3 has been created." << endl;
    myGraph.addNode("Node4");
    cout << "Node4 has been created." << endl;
    myGraph.addNode("Node5");
    cout << "Node5 has been created." << endl;
    myGraph.addNode("Node6");
    cout << "Node6 has been created." << endl;

    //Adding edges to nodes
    myGraph.addEdge("Node1", "Node2", 10);
    myGraph.addEdge("Node1", "Node2", 5);
    cout << "Added two edges between node1 and node2 (weights of 10 and 5)" << endl;
    myGraph.addEdge("Node1", "Node6", 1);
    cout << "Added edge between node1 and node6 (weight 1)" << endl;
    myGraph.addEdge("Node2", "Node5", 2);
    cout << "Added edge between node2 and node5 (weight 2)" << endl;
    myGraph.addEdge("Node5", "Node6", 2);
    cout << "Added edge between node5 and node6 (weight 2)" << endl;
    myGraph.addEdge("Node3", "Node4", 1);
    cout << "Added edge between node3 and node4 (weight 1)" << endl;
    myGraph.addEdge("Node1", "Node3", 4);
    cout << "Added edge between node1 and node3 (weight 4)" << endl;
    myGraph.addEdge("Node3", "Node5", 4);
    cout << "Added edge between node3 and node5 (weight 4)" << endl;
    myGraph.addEdge("Node3", "Node5", 2);
    cout << "Added edge between node3 and node5 (weight 2)" << endl;
    myGraph.addEdge("Node2", "Node4", 1);
    cout << "Added edge between node2 and node4 (weight 1)" << endl;

    // Show stortest path
    cout << "Testing shortest path between 1 and 5: " << myGraph.shortestPath("Node1", "Node5") << endl;
    cout << "Testing shortest path between 5 and 1: " << myGraph.shortestPath("Node5", "Node1") << endl;
    cout << "Testing shortest path between 3 and 4: " << myGraph.shortestPath("Node3", "Node4") << endl;
    cout << "That is all for testing shortest paths" << endl;

    // Show minimum spanning tree
    cout << "Testing min span tree from 1: " << myGraph.min_span_tree("Node1") << endl;
    cout << "Testing min span tree from 4: " << myGraph.min_span_tree("Node4") << endl;
    myGraph.addNode("Node7");
    myGraph.addEdge("Node7", "Node1", 300);
    cout << "Added a node7 with an edge of weight 300 to node1" << endl;
    cout << "Testing min span tree from 7: " << myGraph.min_span_tree("Node7") << endl;


    cout << "Done." << endl;

    return 0;

}