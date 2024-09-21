You should know the correct way to memoize recursions and actually also of sending parameters in recursion.
I initially thought of sending the previous element in the recursion. But that fucks up things at so many levels.

Main fuck up is that you can't create the DP array.(The initial prev element will be -1e5)

What's better is to send the previdx. (Even for that, the initial prevIdx will be -1. We can solve this by having a 1 indexed-array. Initial index can be 0 in that case)