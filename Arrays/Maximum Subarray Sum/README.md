Brute Force:
Three For loops. Two for having all the subarrays. Third for loop for calculating the sum of the subarray from i to j.
Maintain a variable that holds the maximum sum at all points and return that.
Time Complexity - O(N^3)
Space Complexity - O(1)

Better:
Tweak the brute force just a little bit to eliminate the third for loop.
Time Complexity - O(N^2)
Space Complexity - O(1)

Optimal:
Iterate the array once. Keep two variables - tempSum and ans. At every iteration, do ans = max(ans, tempSum).
If tempSum is positive, simply add the element to the tempSum. If not just check if our element is greater than the tempSum. If it is do tempSum = ele.
Time Complexity - O(N)
Space Complexity - O(1)