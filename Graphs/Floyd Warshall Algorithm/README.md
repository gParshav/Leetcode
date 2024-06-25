How is this different from Dijkstra and Bellman Ford?

Firstly, unlike these two, Floyd Warshall is a multisource shortest path algorithm. 
The other two are single source shortest paths algorithms.

So, Floyd Warshall is supposed to give you the length of the shortest path from one node to each and every other node.

It can also be used to detect negative edged cycles, like Bellman Ford.

Also in the Floyd Warshall Algorithm, we compare the path distance through all the vertices, and then choose the shortest path among all of them.

So, if I have to go from 0 to 1, and I have 5 nodes in total.

I will try to find out all these distances and then take the minimum. (This is exactly what we do if you look at the code)

0 -> 1
0 -> 2 + 2 -> 1
0 -> 3 + 3 -> 1
0 -> 4 + 4 -> 1

The minimum of all these will be my answer for 0 -> 1.


Input: Adjacency Matrix consisting of edge weights from one node to every other node.
Output: Matrix consisting of the shortest path from one node to every other node.

Points:
 - The shortest path from one node to that node, will always be 0. So, the diagonal of the answer matrix will always be zero. 