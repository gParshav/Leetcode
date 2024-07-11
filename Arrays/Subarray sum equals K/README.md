Can we use sliding window/2 pointer approach for finding the subarray sum equals K?
 - We can only use it if we have positive arrays. Can't use it for arrays having negative elements.
 - So, if in our question, we have arrays having both positive and negative elements, we cannot use this method.
 
Brute Force:
- 3 For loops. Every subarray is from i to j. (start=i, end = j). 3rd for loop is for calculating the sum for each element from i to j. If that sum is equal to k, ans++. Then return ans.

Time Complexity - O(N^3)
Space Complexity - O(1)

Better:
- You don't need an extra for loop for calculating the sum from i to j. With that extra for loop you first calculating the sum from 0 -> 1, then 0 -> 2, then 0 -> 3 etc. You can see that you are actually doing repitive work. If you keep the sum from 0->1 then simply do +=nums[2], that is 0-> 2. You don't need to always start over again.

Time Complexity - O(N^2)
Space Complexity - O(1)

Optimal:
Prefix sum is a crazy way to go from O(N^2) to O(N). 
We consider an array from index 0 to the present index. This entire array is not the subarray we are interested in. 
But say the sum for that is x, we check in the map if we have any subarrays prior to this with the sum of x-k. That will also in a way tell us the number of subarrays having sum k. Simply add that as you keep iterating.
One basic thing is that you check while making the map. And not after you have completed filling the entire map.
Time Complexity - O(N)
Space Complexity - O(1)
