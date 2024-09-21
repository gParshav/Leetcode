class Solution{   
public:
    bool findSubset(int i, vector<int>arr, int tempSum, int sum){
        if(tempSum==sum){
            return true;
        }
        
        if(i==arr.size()-1){
            return false;
        }
        
        bool c1 = findSubset(i+1, arr, tempSum+arr[i], sum);
        bool c2 = findSubset(i+1, arr, tempSum, sum);
        return c1 ||  c2;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return findSubset(0, arr, 0, sum);
    }
};

class Solution{   
public:
    bool findSubset(int i, vector<int>& arr, vector<vector<int>>& dp, int tempSum){
        
        if(tempSum==0){
            return true;
        }
        
        if(i==0){
            return arr[i]==tempSum;
        }
        
        if(dp[i][tempSum]!=-1){
            return dp[i][tempSum];
        }
        
        bool c1 = false;
        if(tempSum>=arr[i]){
            c1 = findSubset(i-1, arr, dp, tempSum-arr[i]);
        }
        bool c2 = findSubset(i-1, arr, dp,tempSum);
        return dp[i][tempSum] = c1 ||  c2;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return findSubset(n-1, arr, dp, sum);
    }
};


//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        if (arr[0] <= sum) {
            dp[0][arr[0]] = true;
        }
        
        for(int i=1;i<n;i++){
            for(int tempSum = 1;tempSum<=sum;tempSum++){
                bool c1 = false;
                if(tempSum>=arr[i]){
                    c1 = dp[i-1][tempSum-arr[i]];
                }
                bool c2 = dp[i-1][tempSum];
                dp[i][tempSum] = c1 ||  c2;
            }
        }
        
        return dp[n-1][sum];
    }
};




class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<int> prev(sum+1, 0);
        prev[0] = true;
        if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }
        
        for(int i=1;i<n;i++){
            vector<int> curr(sum+1, 0);
            curr[0] = true;
            for(int tempSum = 1;tempSum<=sum;tempSum++){
                bool c1 = false;
                if(tempSum>=arr[i]){
                    c1 = prev[tempSum-arr[i]];
                }
                bool c2 = prev[tempSum];
                curr[tempSum] = c1 ||  c2;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};