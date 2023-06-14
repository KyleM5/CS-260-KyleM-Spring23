#include <string>
#include <vector>

#ifndef graph_node_hpp
#define graph_node_hpp

using std::string;
using std::vector;

class graphNode;

//Structure to represent an edge
struct edge {
    graphNode *source;
    graphNode *destination;
    int weight;
};

class graphNode {
    public:
    //Constructor
    graphNode(string newName) : value(newName) {}; //O(1)

    //Destructor
    ~graphNode() {
        for (auto neighbor : neighbors) { //O(n)
            delete neighbor;
        };
        neighbors.clear();
    };
    
    //add edge
    void addEdge(graphNode *destination, int weight) { //O(1)
        edge *newEdge = new edge{this, destination, weight};
        neighbors.push_back(newEdge);
    };

    //Get the data of a node
    string getValue() { //O(1)
        return value;
    };

    //has nearby nodes
    vector<edge*> getNeighbors() { //O(1)
        return neighbors;
    };
    private:
    //Stored Value
    string value;

    //reference to neighbors
    vector<edge*> neighbors;
};

#endif