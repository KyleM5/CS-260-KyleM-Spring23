#include <iostream>

#ifndef marbles_hpp
#define marbles_hpp

using std::cout;
using std::endl;

class marbleBag {
    private:
        int marbles;
    
    public:    
        void changeMarbles (int cMarbleNum) { //Command to add marbles
            if (cMarbleNum + marbles < 0) { //Checks for too negative a number. Can't be adding anti-marbles
                cout << "You tried removing too many marbles. Bag's marbles being set to zero." << endl;
                marbles = 0;
            }   else if (cMarbleNum > 1000) { //Checks for too many marbles. The mouth of the bag is only so big
                cout << "Too many marbles. Make sure not not add more than 1000 marbles at a time" << endl;
            }   else { //It has done the checks it needs to do, it just modifies now.
                marbles += cMarbleNum;
            };
        };

        //Command to see marbles in bag. Not really needed when the marbles are a publicly accessible
        void showMarbles () {
            cout << "There are " << marbles << " marbles in the bag." << endl;
        };
};

#endif