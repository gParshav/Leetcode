class Solution {
public:
    int findLength(int i, int prev, vector<int>& nums){

        if(i==nums.size()){
            return 0;
        }
        
        int taken = 0;
        if(prev==0 || nums[i]>nums[prev-1]){
            taken = 1+findLength(i+1, i+1, nums);
        }

        int notTaken = findLength(i+1, prev, nums);
        return max(taken, notTaken);

    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        return findLength(0, 0, nums);

    }
};



class Solution {
public:
    int findLength(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){

        if(i==nums.size()){
            return 0;
        }

        if(dp[i][prev]!=-1){
            return dp[i][prev];
        }

        int taken = 0;
        if(prev==0 || nums[i]>nums[prev-1]){
            taken = 1+findLength(i+1, i+1, nums, dp);
        }

        int notTaken = findLength(i+1, prev, nums, dp);
        return dp[i][prev] = max(taken, notTaken);

    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return findLength(0, 0, nums, dp);

    }
};




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int prev=i;prev>=0;prev--){
                int taken = 0;
                if(prev==0 || nums[i]>nums[prev-1]){
                    taken = 1+dp[i+1][i+1];
                }

                int notTaken = dp[i+1][prev];
                dp[i][prev] = max(taken, notTaken);
            }
        }

        return dp[0][0];

    }
};




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        vector<int> next(n+1, 0);
        vector<int> curr(n+1, 0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i;prev>=0;prev--){
                int taken = 0;
                if(prev==0 || nums[i]>nums[prev-1]){
                    taken = 1+next[i+1];
                }

                int notTaken = next[prev];
                curr[prev] = max(taken, notTaken);
            }

            next = curr;
        }

        return next[0];

    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }

        int ans = 0;
        for(auto it : dp){
            ans = max(ans, it);
        }

        return ans;

    }
};