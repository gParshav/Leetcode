Important notes:
1. If a directed graph has a cycle in it, it will have no nodes with indegree[node] == 0. Every node will have atleast one incoming edge and atleast one outgoing edge.
2. For DAG's, another important thing is that if Topological Sort can be done, and if the answer element after Topological Sorting has all the vertices, that means that it doesn't have a cycle.

So basically, 
If Topological Sorting is possible - It doesn't have a cycle
If not - It does have a cycle\

So just do the topological sort and check the length of the answer array at the end of it.