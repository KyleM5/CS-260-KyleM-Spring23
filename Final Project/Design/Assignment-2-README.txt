Assignment 2: Design [No code needed]
 - List what functions are likely needed for a queue like the one discussed in class

Likely functions that we would need would be a function to add a value to the back of the queue, a function to take an item off from the front of the queue, and a function to read the queue (you could forget what is in the middle!) An enqueue, a dequeue, and a checkQueue function.

 - What values will we need to know about the structure for the queue to function properly
We would need to know the end of the queue so that we could tack on to it and change the end of the queue to the tacked on value, we would need to know the beginning of the queue so that you could take off the value, and the value right before the beginning so that you could set the new beginning to nullptr.

Based on what we know about linked lists, design a list data structure that allows us to add or remove values at a given location in the list
 - What functions are we liekly going to need for this
You would need a function that lets you add arbitrarily to the list, a function that lets you arbitrarily remove from the list, and a function that lets you read from the list. As part of the arbitrarily add function, you would need it to make sure for it to update the starting pointer when appending to the beginning..
 - What values will we need to know about the structure for our list to function 
 You would need the memory location of the first entry of the list. You can do everything else from there as linked-list components are linked to the next component, with the final component is directed to nullptr.