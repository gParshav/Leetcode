The end goal is to find the shortest path from the source node to all other nodes.

Instructions:
1. First intuitively try to understand that having an array of edges will not help you. You need to pick up an edge and travel to all its surrounding edges to relax them. SO its kind of a BFS.

Steps:
1. You are given an array consisting of all the edges. Firstly, convert it into an adjacency list. 
2. Initialize an answer array with everything to INT_MAx except ans[src]. Also, initialize a queue for the BFS.
3. Now, push the src into the queue, and keep popping the elements out of the queue until its empty.
4. Everytime you pop out an element, visit all the neighbours, and check for one condition. if(dist[second]>dist[first]+edge_weight). If this is true then relax the dist[second] by doing, dist[second] = dist[first]+edge_weight. And, push the second node to the queue.