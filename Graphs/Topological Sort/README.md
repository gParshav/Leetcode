This is only for Directed Acyclic Graphs.

Firstly meaning of the Topological Sort - 
If there is an edge from u to v, u will come before v in the topological sort.

So intuitively, all those vertices that have no incoming edges will come first.
You need an indegree array to do this.

What do you need?
1. Indegree array.
2. Queue

Steps:
1. Populate the indegree array
2. Push all the vertices with indegree==0 into the queue. Pop all of them one by one until the queue is empty.
3. Now push the popped elements into the answer, and reduce the indegree of all those vertices where an edge from this vertice was going. If indegree of some element becomes 0 in this process, push them to the queue.
4. Return the answer array once the queue is empty.