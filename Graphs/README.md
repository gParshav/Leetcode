# Leetcode

Good practice - Don't ever change on the data that is given as an input to the problem.
If you want, create a copy/clone and change that.
Keep all the input data super intact.

Most commonly used data structure in graphs is the adjacency list.

This is an adjacency list.
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 

One of the most confusing things:
This is how you initalize a 2D array of dimensions m*n:-

1. vector<vector<int>> matrix(m, vector<int>(n, -1));

Priority Queue:

2. priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

The most decent way to represent a directed weighted graph is to have a vector of pairs.

3. The only decent way to represent a directed, weighted graph - vector<vector<pair<int, int>>> graph(n);


36 Done