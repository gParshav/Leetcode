Imagine a graph with N nodes and M edges.

What is a spanning tree?

 - A spanning tree is a tree/graph in which we have N nodes and  N-1 edges, and all nodes are reachable from each other.
 
What is a Minimum Spanning Tree?

 - A MST is the spanning tree that has the least sum of all the edges among all the spanning trees.
 
Algorithms to find the Minimum Spanning Tree of a Graph:-
 - Prim's Algorithm
 - Kruskal's Algorithm
 
Intro - 
1. You need a priority queue, a visited array and a MST array.

Steps:
1. Push a node in the priority queue.
2. Pop it and continue only if its not already visited.
3. Go to all its neighbours and push all the unvisited nodes.

As a result, we will pick the shortest edges first and visit all the nodes just once. This forms the MST.
This is a greedy solution.