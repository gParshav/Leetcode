This again is cycle detection but by DFS.

Steps:
1. Have a visited array, and understand we need to store the parent while we are traversing the graph by DFS.

2. We need to store the parent because we cannot go back to the parent. We go to all the adjacent nodes except the parent.

3. If we land on a visited node in such a fashion, we can say that a cycle exists.