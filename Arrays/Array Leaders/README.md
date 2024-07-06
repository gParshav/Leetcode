Brute Force:
For every element, iterate the rest of the array on the right, to find if any greater element exists. If not, add them into the answer array.
Time Complexity: O(N^2)
Space Complexity: O(1)


Better:
Make another array. Start iterating from the end of the beginning. Every index in the new temp array has to have the highest element from that index to the end. Do this simply by maintaining a max variable.Fill this array completely.
Now, iterate our original array, if the element in our array is == element at the same index in the temp array, that means it itself is the highest element from that index to n-1. Push that element to the answer array.DO that for the entire array.
Time Complexity: O(N)+O(N) = O(N)
Space Complexity: O(N)


Optimal:
You can actully do the better solution without using an extra array. Just a max variable will do. Start iterating the array from the end. If we need to maintain the order in the answer array, we can reverse it.(That's why an extra O(N))
Time Complexity: O(N)+O(N) = O(N)
Space Complexity: O(1)

