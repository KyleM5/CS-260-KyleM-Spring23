#include "graph_node.hpp"
#include <vector>
#include <string>
#ifndef graph_hpp
#define graph_hpp

using std::vector;
using std::string;

class Graph {
    private:

    //Way of storing data
    vector<graphNode*> nodes;

    public:
    //Constructor
    Graph () {};

    //Deconstructor
    ~Graph() {
        for (auto node : nodes) {
            delete node;
        };
    };

    //Add node
    void addNode(string value) {
        graphNode* newNode = new graphNode(value);
        nodes.push_back(newNode);
    };

    //Add edge
    void addEdge(string source, string destination, int weight) {
        graphNode* sourceNode = nullptr;
        graphNode* destinationNode = nullptr;

        for (auto node :nodes) {
            if (node->getValue() == source) {
                sourceNode = node;
            } if (node->getValue() == destination) {
                destinationNode = node;
            };
        
        };

        if (sourceNode && destinationNode) {
            sourceNode->addEdge(destinationNode, weight);
        };
    };

    //Shortest path
    vector<string> shortestPath(string source, string destination) {
        //Todo Make shortest path Using d-something algorithm
        return vector<string>();
    };

    //Minimum Spanning tree
    vector<string> minSpanTree(string source, string destination) {
        //Todo Make minimum spanning tree using stuff
        return vector<string>();
    }



};

#endif