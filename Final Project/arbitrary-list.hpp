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
        
            head = nullptr; //Makes this start as an empty list
        };
        
        void insert(int value, int position) {
            //Create the new node with the data we want to insert

            //Counter for finding the spot used for inserting

            //Test to make sure it is a valid insert position

            //Now insert
        };

        void remove(int position) {
            //Counter for finding the spot before deletion, store for later

            //Find the next for thing we are deleting, store for later

            //Make previous spot in list point further ahead and delete previous entry
        };

        void showData(int position) {
            node *current = head; //Start at head

            for (int i = 0 < position && current != nullptr; i++) { //Counts to where data is
                current = current->next;
            };
            
            cout << current->data << endl; //Prints out the data
            //Counter for finding data in the list

            //return the data in that spot
        };

};


#endif