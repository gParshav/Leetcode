Came up with a very interesting way to solve it, pretty sure that its not the standard way.

If you look at the tree, give the root a y coordinate of 0, decrement it by 1 everytime you go to the left, increment it by 1 everytime you go to the right. Every single node has a y coordinate.

If you draw any symmetric tree, and assign a y coordinate to every node, the sum of node->val*y will be 0.

When I dry ran it, I understood that this logic is wrong.
There can be many such false positives.

One very brute force soluton that comes to my mind is that the array formed at every level/height has to be a palindrome.

Also a recursive solution that comes to mind is that for a tree to be symmetric both its left and right subtrees should be symmetric.

We will try both.

Recursion works. Other one will work but is slightly pointless, much more complicated and less efficient.

Crazy