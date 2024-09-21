Trick was in understanding how the recursion should work, what parameters to pass and the entire flow of writing function calls.

Basically the idea is, you keep iterating the preorder array, and incrementing the pointer.

For every element in the preorder array(call the ith ele temp), you find its location in inorder array. You call it x.
Now everything on left of x in the inorder array is temp->left.
Everything on the right of x in the inorder array is temp->right.
That's almost it.

Whenever base conditions are called, return NULL.