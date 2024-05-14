This question introduces us to a very interesting datatype in C++ called sets.

There are two types of sets that Standard template Libray(STL) library provides:-
1. unordered_set
2. set(These are ordered)

These are actually written in a header file called set.h and can be imported in such a way:-

#include <set>

These have to be used like this - std::set<int>mySet

You can skip the std:: in the start by - using namespace std;

Basic differences and notes on set and unordered_set:

In C++ there are two types of sets provided by the Standard Template Library (STL): std::set and std::unordered_set. 

Both containers store unique elements, but they differ in how they are implemented and their performance characteristics.

std::set
1. Ordered Set: The elements are stored in a specific order, typically in ascending order.
2. Underlying Data Structure: Usually implemented as a balanced binary search tree (e.g., red-black tree).
3. Complexity: Insertion, deletion, and search operations have a logarithmic time complexity, i.e., O(log n).
4. Use Case: When you need a sorted collection of unique elements and order matters.


std::unordered_set
1. Unordered Set: The elements are not stored in any specific order.
2. Underlying Data Structure: Usually implemented as a hash table.
3. Complexity: Average time complexity for insertion, deletion, and search operations is constant time, i.e., O(1). In the worst    case, it can degrade to O(n) if many collisions occur.
4. Use Case: When you need a collection of unique elements and do not care about the order.


When can you use sets in your problems?

 - You care about the uniqueness of elements.
 - You care about the order of elements.
 - You really need a data structure where you can insert elements, erase elements and search for elements.(Important)
   All of these can happen really fast in sets.