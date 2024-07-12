We had to count the number of subarrays having given XOR k.
Classic problem with such a classic progression.
Most of these problems will be optimally solved by hashing and prefix sum/xor whatever.

Brute Force:
Simply check all the subarrays. That takes N^2 time, and then iterate through all of them once again to calculate the XOR value. That makes it N^3 time complexity. If the XOR matches the target, increase the counter.
Time Complexity: O(N^3)
Space Complexity: O(1)

Better:
Again check all the subarrays, but calculate the XOR value in a smarter way. Don't need to again iterate over all of them. Keep the XOR variable and update it, while iterating initially. If equal to the target, increment the counter by 1.
Time Complexity: O(N^2)
Space Complexity: O(1)

Optimal:
The first issue while solving this problem was how to use the prefix sum/xor/etc matching technique over here. Because for the sum problem, we can simply negate the sum operation by a subtract operation.And find currSum - target, in the prefix subarrays. That helps us know if we have any other subarrays matching our target. But what's the way to negate the xor operation? What exactly shall we look for in the prefix? This was a challenge.
Firstly, lets understand these terminlogies and then we will answer the above question too.
We have one full big subarray that we are considering. The xor for all of them is currXOR. Inside this full array, we are trying to find our subarray, whose xor equals to the target. The elements outside and before our subarray, but inside the entire big array constitute the prevXOR.
So we know for a fact that, prevXOR ^ target = currXOR;
Now, we need to find the value for prevXOR, and sort of negate the XOR on the left hand side, so that I have something to look up for in my hash map.
For that, we xor both the sides by target. Now, LHS = prevXOR^target^target = prevXOR
RHS = currXOR^target. So therefore, prevXOR = currXOR^target. This is the value you have to look up for in the map every time while iterating.
Time Complexity: O(N)
Space Complexity: O(N)