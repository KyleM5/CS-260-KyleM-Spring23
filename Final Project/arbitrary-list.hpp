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

            if (position < 0) { //Checks to see if position argument is valid
                cout << "Invalid position: Negative positions on the list are not allowed" << endl;
                return;
            };

            node *new_node = new node; //Creates the new node
            new_node->data = value; //Inserts the data
            
            

            if (position == 0) { //If pos = 0, inserts at start of the list
                new_node->next = head;
                head = new_node;
                return;
            };

            node *current = head; //Counts to position-1, and we can insert after that to get pos-1+1, or pos
            for (int i = 0; i < position-1 && current != nullptr; i++) {
                current = current->next;
            };

            if (current == nullptr) { //Checks to see if you went off of the list.
                cout << "invalid position" << endl;
                delete new_node;
                return;
            };

            new_node->next = current->next; //Inserts into the list
            current->next = new_node;
        };

        void remove(int position) {
            if (position < 0) { //Checks to see if position argument is valid
                cout << "Invalid position: Negative positions on the list are not allowed" << endl;
                return;
            };

            node *previous = head; //Tracks for previous
            node *current = nullptr;

            for (int i = 0; i < position-1 && current != nullptr; i++) { //Counts to position-1
                previous = previous->next;
            };
            current = current->next;

            if (current == nullptr || previous == nullptr) {
                cout << "Invalid position" << endl;
                return;
            };
            previous->next = current->next; //Sets previous to go to where current is pointing
            cout << current->data << endl; //Prints current data
            delete current; //Deletes current

            //Counter for finding the spot before deletion, store for later

            //Find the next for thing we are deleting, store for later

            //Make previous spot in list point further ahead and delete previous entry
        };

        void showData(int position) {
            node *current = head; //Start at head

            for (int i = 0; i < position && current != nullptr; i++) { //Counts to where data is
                current = current->next;
            };
            
            if (current == nullptr) { //If position is invalid, error.
                cout << "Invalid position" << endl;
                return;
            };

            cout << current->data << endl; //Prints out the data
        };

};


#endif