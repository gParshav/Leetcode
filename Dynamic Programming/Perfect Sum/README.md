Got caught up in the base case.
Couldn't initially understand why is the base case always when i<0.
These above 2 lines are bullshit.(No its not)
The base case will actually be when i<0, because that allows us to go deep into the array and consider all the zeroes.

If we straight away return when target==0, we are ignoring all 0's in the rest of the array.
Therefore, don't do that. Go till the end.

Also, this is an exception in the sense that translating from memoization to tabulation was not normal and easy.  
It was not straight away copy pasting. You had to think. Check the code to understand more.

return dp[i][tempSum] = (find(i-1, arr, tempSum-arr[i], dp) + find(i-1, arr, tempSum, dp)) % (1e9+7);  This is wrong.

return dp[i][tempSum] = (find(i-1, arr, tempSum-arr[i], dp) + find(i-1, arr, tempSum, dp)) % MOD; This is fine.

Declare MOD = 1e9+7 somewhere. 