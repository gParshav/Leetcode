The problem is that two arrays with the same elements and different arrays are not allowed.
SO say, our array is [1, 2, 1], and targetSum = 3, the answer will be [[1, 2]] and not [[1, 2], [2, 1]]


Brute Force:
1. Sort the array
2. Perform all the recursions, put all the  arrays in a set
3. Pop the set, and put all the arrays in the big 2D answer array

Problem is that we explore all the possible subsequences which is really inefficient.

Better: (We need to eliminate the set datastructure used in the the brute force cause that is all the problem)
1. You don't ever go on two subsequences which are same. (Check the code and dry run the recursions to understand how exactly is that happening).
2. Therefore, we don't need the set anymore and that just works.