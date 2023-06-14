#include "graph_node.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <vector>

#ifndef graph_hpp
#define graph_hpp

using std::vector;
using std::string;
using std::distance;
using std::find;
using std::set;
using std::min_element;
using std::numeric_limits;
using std::cout;
using std::endl;


class Graph {
    private:

    //Way of storing data
    vector<graphNode*> nodes;

    public:
    //Constructor
    Graph () {};

    //Deconstructor
    ~Graph() {
        for (auto node : nodes) { //O(n)
            delete node;
        };
    };

    //Add node
    void addNode(string value) { // O(1)
        graphNode* newNode = new graphNode(value);
        nodes.push_back(newNode);
    };

    //Add edge
    void addEdge(string source, string destination, int weight) {
        graphNode* sourceNode = nullptr;
        graphNode* destinationNode = nullptr;

        for (auto node :nodes) { //O(n)
            if (node->getValue() == source) {
                sourceNode = node;
            } if (node->getValue() == destination) {
                destinationNode = node;
            };
        
        };

        if (sourceNode && destinationNode) { //O(1)
            sourceNode->addEdge(destinationNode, weight);
            destinationNode->addEdge(sourceNode, weight);
        };
    };

    //Shortest path
    int shortestPath(string source, string destination) { //O(n)
        graphNode *start = nullptr;
        graphNode *end = nullptr;
        for (auto n : nodes) { //O(n)
            if (n->getValue() == source) start = n;
            if (n->getValue() == destination) end = n;
        };

        //Test to see if start and end are not on graph, returns high number
        if (start == nullptr || end == nullptr) {  //O(1)
            return INT_MAX;
        };

        //Create a vector that stores the distance to each node
        vector<int> dist(nodes.size(), INT_MAX);
        
        //Set the distance at the start node to zero
        dist[distance(nodes.begin(), find(nodes.begin(), nodes.end(), start))] = 0;

        //Create a set to store the unvisited nodes
        set<graphNode*> unvisited;
        for (auto n : nodes) { // O(n)
            unvisited.insert(n);
        };

        //Dijstra's algorithm
        while (!unvisited.empty()) { //O(Elog(v)) where E is edges and v is vertices
            graphNode *current = *min_element(unvisited.begin(), unvisited.end(), 
                [&](const graphNode* n1, const graphNode* n2) { 
                    return dist[distance(nodes.begin(), find(nodes.begin(), nodes.end(), n1))] < dist[distance(nodes.begin(), find(nodes.begin(), nodes.end(), n2))]; 
                });
            if (current == end) {
                // We have found the shortest path to the end node, so return its distance
                return dist[distance(nodes.begin(), find(nodes.begin(), nodes.end(), current))];
            }
            unvisited.erase(current);
// Update the tentative distances of the unvisited neighbors of the current node
            for (auto b : current->getNeighbors()) { //O(n)
                int alt = dist[distance(nodes.begin(), find(nodes.begin(), nodes.end(), current))] + b->weight;
                int idx = distance(nodes.begin(), find(nodes.begin(), nodes.end(), b->destination));
                if (alt < dist[idx]) {
                    dist[idx] = alt;
                }
            }
        };

        // If we have visited all nodes and haven't found the end node, it means there is no path
        return INT_MAX;

    };

    //Minimum Spanning tree. Apparently this is making a tree with the least weight possible, while I thought it was something else
    int min_span_tree(string startingnode) {
            // Find the starting node.
            graphNode *start = nullptr;
            for (auto n : nodes) { // O(n)
                if (n->getValue() == startingnode) {
                    start = n;
                    break;
                }
            }
            if (start == nullptr) {
                cout << "Starting node is nullptr" << endl;
                return -1; // Starting node not found.
            };
            // Initialize the set of visited nodes and the set of unvisited nodes.
            set<graphNode*> visited;
            set<graphNode*> unvisited;
            for (auto n : nodes) { // O(n)
                if (n == start) {
                    unvisited.insert(n);
                }   else {
                    visited.insert(n);
                };
            };
            // Initialize the minimum spanning tree.
            int minspan = 0; //O(1)
            // Repeat until all nodes are visited.
            while (!unvisited.empty()) { //O(n^2)
                // Find the node in the unvisited set with the smallest edge weight to a visited node.
                graphNode *current = nullptr; //O(1)
                edge *smallest = nullptr; //O(1)
                int smallest_weight = numeric_limits<int>::max();
                for (auto n : unvisited) { //O(n^2)
                    for (auto b : n->getNeighbors()) { //O(n)
                        if (visited.find(b->destination) != visited.end() && b->weight < smallest_weight) {
                            current = n;
                            smallest = b;
                            smallest_weight = b->weight;
                        }
                    }
                }
                if (current == nullptr) { //O(1)
                    cout << "Graph is not connected" << endl;
                    return -1; // Graph is not connected.
                };
                // Add the node and branch to the minimum spanning tree.
                visited.insert(current); //O(1)
                unvisited.erase(current); //O(1)
                minspan += smallest_weight; //O(1)
            }
            return minspan; //O(1)
        };



};

#endif