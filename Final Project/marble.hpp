#include <iostream>

#ifndef marbles_hpp
#define marbles_hpp

using std::cout;
using std::endl;

class marbleBag {
    public:
        int marbles;

        //Command to add marbles
            //Limit how many marbles you can add to prevent overflow/issues
        void addMarbles (int add) {
            /*The if statement checks to see if the number is negative, and doesn't add anti-marbles.
            The else if statement checks if the amount of marbles being added is reasonable, and then adds the number
            The else statement tells you if you had too many positive marbles.*/
            if (add > 0) {
                cout << "You can't add anti-marbles. You would need an anti-marble bag" << endl;
            }   else if (add < 1000) {
                marbles += add;
            }   else {
                cout << "Too many marbles. Make sure ot not add more than 1000 marbles at a time" << endl;
            };
        };

        //Command to see marbles in bag

        //Command to remove marbles
            //Make sure to add code in case you try to remove while there is no marbles
};

#endif