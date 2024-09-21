class Solution{

	public:
	
	void find(int i, int arr[], int tempSum, int& ans){
	    
	    
	    if (i < 0) {
            if (tempSum == 0) {
                ans = (ans + 1);
            }
            return;
        }
	    
	    find(i-1, arr, tempSum-arr[i], ans);
	    find(i-1, arr, tempSum, ans);
	    
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ans = 0;
        find(n-1, arr, sum, ans);
        return ans;
	}
	  
};



class Solution{

	public:
	
	const int MOD = 1e9+7;
	int find(int i, int arr[], int tempSum, vector<vector<int>>& dp){
	    
	    
	    if (i < 0) {
            if (tempSum == 0) {
                return 1;
            }
            return 0;
        }
	    
	    if(tempSum > 0 && dp[i][tempSum]!=-1){
	        return dp[i][tempSum];
	    }
	    
	    if(tempSum<0){
	        return 0;
	    }
	    
	    if(tempSum>=arr[i]){
	        return dp[i][tempSum] = (find(i-1, arr, tempSum-arr[i], dp) + find(i-1, arr, tempSum, dp)) % MOD;    
	    }
	    
	    
	    return dp[i][tempSum] = find(i-1, arr, tempSum, dp) % MOD;
	    
	    
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return find(n-1, arr, sum, dp);
	}
	  
};



class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        const int MOD = 1e9+7;
        int k = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                k=k*2;
            }
            
            dp[i][0] = k;
            
        }
        
        if (arr[0]!=0 && arr[0] <= sum) {
            dp[0][arr[0]] = 1;
        }

        for(int i=1;i<n;i++){
            for(int tempSum=0;tempSum<=sum;tempSum++){
                if(tempSum>=arr[i]){
        	        dp[i][tempSum] = (dp[i-1][tempSum-arr[i]] + dp[i-1][tempSum]) % MOD;    
        	    }
        	    
        	    else{
        	        dp[i][tempSum] = dp[i-1][tempSum] % MOD;    
        	    }
        	    
        	        
            }
        }
        
        
        
        return dp[n-1][sum];
	}
	  
};


class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        const int MOD = 1e9+7;
        vector<int> prev(sum+1, 0);
        int k = 1;
        if(arr[0]==0){
            k = k*2;
        }
        prev[0] = k;
        
        if (arr[0]!=0 && arr[0] <= sum) {
            prev[arr[0]] = 1;
        }

        for(int i=1;i<n;i++){
            if(arr[i]==0){
                k = k*2;
            }
            vector<int> curr(sum+1, 0);
            curr[0] = k;
            for(int tempSum=0;tempSum<=sum;tempSum++){
                int notTaken = prev[tempSum];
                int taken = 0;
                if(tempSum>=arr[i]){
        	        taken = prev[tempSum-arr[i]];    
        	    }
        	    
        	    curr[tempSum] = (taken+notTaken)%MOD;
        	    
        	        
            }
            
            prev = curr;
        }
        
        
        
        return prev[sum];
	}
	  
};