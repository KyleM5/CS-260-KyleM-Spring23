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
    
    return 0;
    // Show stortest path

    // Show minimum spanning tree

}