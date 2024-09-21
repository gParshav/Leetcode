Recursion:
Getting the recursion solves 80% of all dp problems. 
Recursion for this, f(n) = f(n-1) + f(n-2)
Time Complexity: O(2^N)
Space Complexity: Recursion Stack Space - O(N)

Memoization:
The dimensions of the array you use for memoization is equal to the number of variables in the recursion.
Now, store the results of recursion in the array, to use it further. 
Time Complexity: O(N)
Space Complexity: O(N)+O(N){Recursion Stack Space}

Tabulation:
Convert memoization into tabulation to save the recursion stack space.
Time Complexity: O(N)
Space Complexity: O(N)

Space Optimization:
Understand that you don't really require the entire array or whatever datastructure you are using in tabulation. You just require a small part of it. Keep just that much.
Time Complexity: O(N)
Space Complexity: O(2)

Its important to mentally understand that the meaning of calling the function from the main function, each recursive calls, each cell in the array in tabulaton is all the same.

In this case, it is the number of ways in which you can reach at that step.

f(n) = is the number of ways in which you can reach n steps.
dp[i] = is the number of ways in which you can reach the ith step.