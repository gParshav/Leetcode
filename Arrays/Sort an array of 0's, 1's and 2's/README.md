Brute Force:
Sort the array using the sort() function.
Time Complexity - O(N*logN)
Space Complexity - O(N)

Better:
Iterate the array once to count the number of zeroes, ones and twos. Iterate the array again to fill it in such a fashion.
Time Complexity - O(N)+O(N) = O(N)
Space Complexity - O(1)

Optimal:
Initialize 3 pointers, low = 0, mid = 0 and high = n-1, and assume the array to have 4 parts. 
0 to low-1 -> 0
low to mid-1 -> 1
mid to high -> Random Unsorted(We iterate the entire array until this random unsorted array ceases to exist)
high+1 to n-1 -> 2
(We have to keep iterating the array and keep editing it in a way such that the above conditions hold themselves true)
We are iterating the mid pointer constantly.

3 conditions
arr[mid] = 0;
 - Swap arr[low] and arr[mid]. Do low++, mid++. (We are doing this to maintain the above mentioned conditions)
arr[mid] = 1;
 - mid++. Other than that, do nothing.
arr[mid] = 2;
 - Swap arr[high] and arr[mid]. Do high--
Iterate the entire array and keep doing this until mid<=high

Time Complexity - O(N)
Space Complexity - O(1)