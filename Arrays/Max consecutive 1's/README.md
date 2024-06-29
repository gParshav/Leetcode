Thinking of the brute and better is sort of pointless.
In this case, the optimal solution is a lot more intuitive.

Use two variables, prev and ans.
Everytime you have a 1 increase prev by 1 and check if it is greater than ans. If it is ans = prev.
If you come across a 0, prev = 0.

Time Complexity - O(N)
Space Complexity - O(1)

