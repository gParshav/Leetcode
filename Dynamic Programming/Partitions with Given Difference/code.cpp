class Solution {
  public:
    int find(int i, int sum, vector<int>& arr){
        if(i<0){
            if(sum==0){
                return 1;
            }
            
            return 0;
        }
        
        int notTaken = find(i-1, sum, arr);
        int taken = 0;
        if(sum>=arr[i]){
            taken = find(i-1, sum-arr[i], arr);
        }
        
        return notTaken+taken;
        
        
            
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        for(auto it : arr){
            total+=it;
        }
        
        int sum = (total+d)/2;
        // cout<<sum<<endl;
        if((total+d)%2!=0){
            return 0;
        }
        return find(n-1, sum, arr);
    }
};


class Solution {
  public:
    const int MOD = 1e9+7;
    int find(int i, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(i<0){
            if(sum==0){
                return 1;
            }
            
            return 0;
        }
        
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        
        int notTaken = find(i-1, sum, arr, dp);
        int taken = 0;
        if(sum>=arr[i]){
            taken = find(i-1, sum-arr[i], arr, dp);
        }
        
        return dp[i][sum] = (notTaken+taken)%MOD;
        
        
            
    }
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        for(auto it : arr){
            total+=it;
        }
        
        int sum = (total+d)/2;
        if((total+d)%2!=0){
            return 0;
        }
        
        if(sum>total){
            return 0;
        }
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return find(n-1, sum, arr, dp);
    }
};


class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        const int MOD = 1e9+7;
        for(auto it : arr){
            total+=it;
        }
        
        int sum = (total+d)/2;
        if((total+d)%2!=0){
            return 0;
        }
        
        if(sum>total){
            return 0;
        }
        
        int k = 1;
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                k = k*2;
            }
            
            dp[i][0] = k;
        }
        
        if(arr[0]!=0 && sum>=arr[0]){
            dp[0][arr[0]] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int notTaken = dp[i-1][j];
                int taken = 0;
                if(j>=arr[i]){
                    taken = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = (notTaken+taken)%MOD;
            }
        }
        
        return dp[n-1][sum];
    }
};


class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        const int MOD = 1e9+7;
        for(auto it : arr){
            total+=it;
        }
        
        int sum = (total+d)/2;
        if((total+d)%2!=0){
            return 0;
        }
        
        if(sum>total){
            return 0;
        }
        
        int k = 1;
        vector<int> prev(sum+1, 0);
        if(arr[0]==0){
            k = k*2;
        }
        
        prev[0] = k;
        
        if(arr[0]!=0 && sum>=arr[0]){
            prev[arr[0]] = 1;
        }
        
        for(int i=1;i<n;i++){
            vector<int> curr(sum+1, 0);
            if(arr[i]==0){
                k = k*2;
            }
            curr[0] = k;    
            for(int j=0;j<=sum;j++){
                int notTaken = prev[j];
                int taken = 0;
                if(j>=arr[i]){
                    taken = prev[j-arr[i]];
                }
                
                curr[j] = (notTaken+taken)%MOD;
            }
            prev=curr;
        }
        
        return prev[sum];
    }
};