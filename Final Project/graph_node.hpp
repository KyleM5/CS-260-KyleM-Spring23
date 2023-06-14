#include <string>
#include <vector>

#ifndef graph_node_hpp
#define graph_node_hpp

using std::string;
using std::vector;

class GraphNode;

//Structure to represent an edge
struct edge {
    GraphNode *source;
    GraphNode *destination;
    int weight;
};

class GraphNode {
    public:
    //Constructor
    GraphNode(string newName) : value(newName) {}; // "?"

    //Destructor
    ~GraphNode() {
        for (auto neighbor : neighbors) {
            delete neighbor;
        };
        neighbors.clear();
    };
    
    //add edge
    void addEdge(GraphNode *destination, int weight) {
        edge *newEdge = new edge{this, destination, weight}
        neighbors.push_back(newEdge);
    };

    //Get the data of a node
    string getValue() {
        return value
    };

    //has nearby nodes
    vector<edge*> getNeighbors() {
        return neighbors;
    };
    private:
    //Stored Value
    string value;

    //reference to neighbors
    vector<edge*> neighbors;
};

#endif