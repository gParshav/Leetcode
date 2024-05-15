It is really essential to try and intuitively understand the difference between cycle detection in directed and undirected graphs.

So imagine we are using DFS.

We can detect cycles in undirected graphs using plain vanilla DFS with one simple detail.
So imagine the graph only consists of two nodes and one edge between them. Since it is undirected, the edge goes both ways,
and while traversing through DFS you will go back to the previously visited node and detect a cycle although there isn't a cycle technically.

So for undirected graphs:
Cycle Detection  = Plain DFS + ParentNode
The parent node just takes care that we are not going back to the visited node we just came from.

Now lets come to the directed graphs,
There exists a new problem.
In directed graphs, you can visit a node in two different ways without a cycle being present.

Imagine 0->1->2 and 0->2.
If you draw this in your notebook you will realize that a cycle doesn't actually exist.
But, a simple DFS with a visited array will tell that a cycle exists.

So this is a problem you have to solve in cycle detection in Directed Acyclic Graphs.

How do we solve it? 
One simple idea is go on to the DFS until you reach the dead end, and while climbing up the tree, keep doing the visited[i] = false.
But this can then turn into a TLE. Cause you will keep calling the DFS function from the main function.

So you need to now, have to visited functions.
One is visited and the other one is pathVisited.
You don't touch the visited while coming upwards in the tree. But instead do pathVisited[i] = false.