Ways to do DP:
1. Tabulation - Bottom up
2. Memoization - Top Down

Dynamic Programming is nothing but a way to fasten recursion by using extra space.

Cases where we can apply DP:(Where we can use extra space to fasten recursion) - 
1. Problems having overlapping subproblems. 
2. Optimal Substructure(You can actually solve the problem by breaking it into smaller subproblems)

Normal chronology for solving DP problems:
1. Normal Recursion
2. Memoization
3. Tabulation
4. Space Optimization

Steps to convert recursion into DP(Memoization):
1. Firstly declare an array or any other datastructure, that can store the values of our subproblems.
2. Before calling the recursion again for the next subproblem, check if it has been already computed and stored in our datastructure. If yes, just return that and don't call again.
3. If it has not been solved already, call the functions and store the result in the datastructure that you are using.


Steps to convert Memoization into Tabulation:
1. Initialize the array/data structure in the same way as you did in Memoization.
2. Fill the data structure with whatever your base case was in Memoization.
3. Copy whatever recursion you wrote in Memoization and implement it in a for loop or whatever. Fill the data structure from bottom up by iterating from i = 0 to i < n, using the same recursion logic.

Why is Tabulation slightly better than Memoization?
- Time Complexity is the same
- Space Complexity is slightly lesser as we eliminate the recursive stack space used in Memoization. Other than that the ewual amount of Memory is used. Memoization  = Tabulation + Stack Space

How to do Space Optimization in Tabulation?
1. Understanding that we don't actually requre the entire array. We just require a part of it according to the recursion relation.
Just use that much memory and not the entire array/data structure that you are using.

Whenever you have to go across all the possible ways - its a recursion problem.
While iterating across all the possible ways, you can only do two things:
1. Count the number of possible ways
2. Find the best/worst possible way


While converting from tabulation to space optimization in 2D DP, perform all the base case initializations that you did on prev to curr as well.

41 Done