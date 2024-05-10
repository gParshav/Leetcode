Problem Link - https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

For computing the DFS of a graph:
1. Firstly have a visited array and an answer array
2. Start with any vertex and call the DFS function.
3. Now keep traversing all the unvisited neighbours of this node recursively. Add all of these to the answer array.
4. Once there are no unvisited nodes left, you simply return.

Insights:

There may often times be unconnected components in a graph.
So every time, our code comes back to the for loop, its essentially a new component.(This is mostly, definitely true for undirected graph, a bit more nuanced for directed graphs).

Super interestingly, the next question(Problem 3) and Leetcode 547 is exactly what I am talking about.
That question again has an undirected graph.