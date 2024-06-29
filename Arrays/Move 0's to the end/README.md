Brute force involves taking a seperate array, storing values and again changing values in our original array.

Time Complexity - O(n)
Space Complexity - O(n)

Optimal - 2 Pointers
Time Complexity - O(n)
Space Complexity - O(1)


Steps:
- Initialize i with -1 and j with 0. Everytime you have a 0 at j, simply move ahead(increment j).
- If you have a non zero value at j, increment i, do nums[i] = nums[j], and then increment j.
- Then first i values in your array have non zero values. Rest all are supposed to have 0. So do that.
