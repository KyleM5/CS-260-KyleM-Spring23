#include <iostream>

#ifndef arbitrary_list_hpp
#define arbitrary_list_hpp

using namespace std;

// This defines the node structure
struct node {
    int data;
    node *next;
};

//Define the list class for arbitrary list
class list {
    private:
        
        node *head; //Head is the start of the list

    public:
        list() {
        
            head = NULL; //Makes this start as an empty list
        };

};


#endif