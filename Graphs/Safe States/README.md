This is the reverse of topological sort.

Instead of indegree, we are interested in the outdegree.

And normally, we have the graph that tells us where is the edge going to starting from a vertex a.
But now we need to know from where is the edge coming from.

So basically, you will have to reverse the graph, use outdegrees instead of indegrees and then do toposort.