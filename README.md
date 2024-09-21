Whenever you get a memory limit exceeded, first go and try passing all the variables by address.

You can never pass a pointer as an index to a vector in C++.
Even if you declare it like vector<TreeNode*> vis.
TreeNode* temp;
YOu can't do vis[temp].
Simply not allowed.

Lets learn a few things about priority queues.

Total - 185 DONE