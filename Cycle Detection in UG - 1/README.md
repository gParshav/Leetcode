Problem Link - https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

Notes:
1. Since we are computing the existing of a cycle in the graphs, the parent matters to us. So if we are travelling to a vertex B, we also have to know which vertex is it coming from, say, vertex A. The point of all this is we cannot go to A again from B and say that a cycle exists.

2. So again now the same BFS. Our queue element includes the node itself and the parent. 

3. Iterate until the queue is empty. At every step, go to all the unvisited neighbours except the parent.

4. If you somehow land on an element that is already visited and not the parent, a cycle exists.

This may seem confusing, always once dry run a simple triangular graph to understand if a cycle exists.