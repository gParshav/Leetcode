class Solution {
public:
    int find(int i, vector<int>& nums, int target){

        if(i<0){
            if(target==0){
                return 1;
            }

            return 0;
        }

        int pos = find(i-1, nums, target-nums[i]);
        int neg = find(i-1, nums, target+nums[i]);
        return pos+neg;

    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        return find(n-1, nums, target);


    }
};




class Solution {
public:
    int find(int i, vector<int>& nums, int tempSum, int target, int total, vector<vector<int>>& dp){

        if(i<0){
            if(tempSum==0){
                return 1;
            }

            return 0;
        }

        if(dp[i][tempSum+total-target]!=-1){
            return dp[i][tempSum+total-target];
        }

        int pos = find(i-1, nums, tempSum-nums[i], target, total, dp);
        int neg = find(i-1, nums, tempSum+nums[i], target, total, dp);
        return dp[i][tempSum+total-target] = pos+neg;

    }


    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size(),total = 0;
        for(auto it : nums){
            total+=it;
        }

        if(target>total){
            return 0;
        }

        if(target<-1*total){
            return 0;
        }

        vector<vector<int>> dp(n, vector<int>(2*total+1, -1));
        return find(n-1, nums, target, target, total, dp);


    }
};