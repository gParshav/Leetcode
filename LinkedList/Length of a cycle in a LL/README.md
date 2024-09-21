You can do this by mantaining a map that stores the ondes as a key and a counter as a value.

First find if there is a cycle in the linked list. You can use slow and fast pointers to do that. Once slow and fast pointers meet, you know that a cycle exists. Now use one of those pointers to traverse the entire cycle and maintain a counter to keep the total length of the cycle. When slow and fast meet again, you know that the entire cycle has been traversed and then return the length of the cycle.
