If multiple LCS's exist, you will have to use recursion.
First find out the length, and then make a seperate function to find common subsequences of that length.
To do this efficiently through memoization, we have to make a 3D array which I am not able to understand.

However, if only a single LCS exists, you can use the dp matrix, and traverse in a particular way which is not so difficult to understand, to get the longest common subsequence.