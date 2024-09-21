Dry running the solution is a very good way to understand it.

But otherwise, if we find p we return p, if we find q we return q, if we have found both then thats the LCA.
If we find nothing we simply return NULL.

So every node recieves something from the nodes below.
If we get something and NULL, we have found one of the two nodes.
If we get something and something, we have found both the nodes. Therefore return that node, because the first node where you find out that you have found both the nodes already is the LCA.