Simple definition for a bipartite graph - 
If you are able to color a graph such that no two adjacent vertices have the same color, its a bipartite graph.

Steps:
1. Initialize a color array which will also act like the visietd array.
2. Call normal DFS.
3. Return false if the node you are visiting is already coloured with the opposite of what it should be having.