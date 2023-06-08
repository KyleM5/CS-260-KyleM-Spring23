Assignment 1: Bag of marbles
 - explain what a program could do to model a bag of marbles [x]
 - Attempt to implement this bag of marbles as simply as possible [x]
 - Test the implementation in a driver file. Try and test each function [x]
 - Mark what lines of code meet these requirements [x]

 Explain what a program could do to model a bag of marbles:

 To model a bag of marbles, the bag would need:
 - A marble bag class
 - A list to track how many marbles are in the bag (and maybe the color)
 - A method that lets you add marbles to the bag
 - A method that lets you see how many marbles are in the bag
 - A method that lets you take marbles out of the bag
 - (Optional) A space limit for the bag

 As we are trying to represent a bag of marbles as simply as possible, marbles would be represented by an integer

 To test a program that is meant to represent a bag of marbles you could put a lot of marbles in the bag and see how many are in the bag. If there ends up being not enough marbles in the bag, we know a more robust implementation is needed.

 Another way to test is by removing marbles. See how many marbles we had before removing, remove # amount of marbles, and see if there is the proper amount of marbles remaining. 

 Also configure what happens what happens when you try and remove too many marbles. We aren't making anti-marbles... Though that could be kinda funny.

 The code for the marblebag is in marble.hpp
 The code for testing is in final.cpp and is lines 15-41