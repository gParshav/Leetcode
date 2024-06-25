Why do we need this when we have Dijkstra?
- Dijkstra fails in graphs having negative cycles.


Random:
1. Bellman Ford is only for directed graphs.
2. Given edges can be in any order.
3. Relax all the edges, n-1 times sequentially.(Basically go through all the edges for n-1 times)
4. Condition for relaxation is the same:
    if(dist[v]>dist[u]+wt)