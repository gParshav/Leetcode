Brute Force:
Observe the mapping of the current matrix to the answer matrix if we want to rotate the matrix.
Create another 2D array, perform the mapping and fill the other 2D array.
Copy that into the original matrix and return.
Time Complexity - O(N^2)
Space Complexity - O(N^2)

Brute Force2:
We know the mappings. The problem is that if we keep swapping according to that, we will lose the original matrix. Suppose I know [0][0] goes to [0][2]. I do that. But then when do I place [0][2]? You can simply use a recursive function, and put [0][2] at its right place and do the same for wherever [0][2] is going. The only thing is that we will not know which elements are already placed at its correct position. Maintain a visited array for that.
Time Complexity - O(N^2)
Space Complexity - O(N^2)

Optimal:
Understand that if you take the transpose, and then reverse every single row, you will get the rotated 2D matrix. This doesn't take any extra space.

Time Complexity - O(N^2)
Space Complexity - O(1)