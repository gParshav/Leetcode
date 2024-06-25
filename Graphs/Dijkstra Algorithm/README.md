Same classic Dijkstra as the other two problems.

Dijkstra and single source shortest path algorithms are all BFS algorithms.

Steps:
1. Push the source to the queue, and do BFS. Traverse to all the neigbouring nodes and relax them. If ans[second]>ans[first] + dist,
ans[second] = ans[first] + dist.
2. Keep doing this until the queue is empty and then return the answer.


There is lot more to Dijkstra then what I had initially thought:

First lets divide it among Directed and Undirected graphs:

Undirected Graphs:
 - We can solve it using queues and improve the time complexity using priority queues.
 - So bottom line, use priority queues and not just queues.
 
Directed Graphs:
 - Worst way to do it is by using queues.
 - Better way is using priority queues.
 - Best way is by using topological sort.
 
We need to try and intuitively understand why is topological sort the best way to do it.