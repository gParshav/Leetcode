Why do Disjoint Sets exist and what's the point?

Say we have two components of a graph, 1->2->3->4 and 5->6, and we want to know if 1 and 5 are in the same graph.

We have two ways:
1. DFS/BFS(Brute Force) - O(N+E)
2. Disjoint Sets - Constant Time - O(1)

We can start from wherever 1 is and traverse the entire graph through BFS or DFS, and know if we ever reach 5. This will take
linear time and is not the best way to solve the problem.

Two main functionalities of a Disjoint Set - 
1. Find Parent
2. Union 

Two ways to perform the Union operation by Disjoint Set:
1. Rank
2. Size

What is the meaning of the Union Operation?
- Connect two unconnected nodes/graphs.

Disjoint sets are particularly more useful in dynamic graphs, where connections, components and graphs are changing constantly.

Psuedo Code for Union of u and v:
Firstly, initialize a rank and a parent array.
1. Find ultimate parent of u and v and call it pu and pv.
2. Find rank of pu and pv.
3. Connect smaller rank to larger rank always.

A key understanding is that every node inside the same component has the same ultimate parent.
If two nodes have the same ultimate parent, they are in the same component.

SO two check if two nodes belong to the same component, we need their ultimate parents and that may take O(logn) time in the worst case. We do path compression to reduce that time.

Path compression in simple sense means that we always store the ultimate parent in the parent array and not the immediate parent.
While doing path compression and finding the ultimate parent, you are not supposed to change the ranks. That just doesn't make sense.

Why do we connect smaller rank to larger rank in the union operation?
- Doing this will not affect the height of the tree.
- Doing the opposite will simply increase the height of the tree/graph and make the find operation even slower. Which doesn't make sense. Connecting the smaller rank one to the larger rank.


- Rank Matrix of a node is basically the maximum height of the tree formed using that node as the root node.

Another alternative method - 
- Union by size

Everything is the same except that we use the size matrix instead of the rank matrix.

Size of a particular node is the number of nodes connected to that node in a tree formed using that as the root node. 