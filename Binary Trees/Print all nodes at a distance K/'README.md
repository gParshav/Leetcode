A certain challenge in solving problems on Binary Trees arises when we have to sort of go up towards the parents instead of going to the children.

So this is a challenge, since binary trees are naturally designed to be travelled downwards.

If you wish to travel upwards, you can make a new data structure such as a map to store the parents of every node.

This is really helpful.

Now you can travel upwards by going to the parent.

This question involves a radial traversal.
At every step, we go to the parent, to the left child and to the right child.