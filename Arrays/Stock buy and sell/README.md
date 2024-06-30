Brute Force:
Technically, if you buy today, you can sell on any of the remaining days.
So brute force is that try buying every day, and selling on all the remaining days.
2 for loops. Maintain a variable to store the maximum profit.

Time Complexity - O(N^2)
Space Complexity - O(1)

Optimal:
Optimal is that try selling every day.
Buy everytime the element is lesser than your previous buying price.

Time Complexity - O(N)
Space Complexity - O(1)
