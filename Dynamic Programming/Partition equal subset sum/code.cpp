class Solution {
public:
    bool check(vector<int>& nums, int sum, int i){

        if(sum==0){
            return true;
        }

        if(i==0){
            return nums[i]==sum;
        }

        bool notTaken = check(nums, sum, i-1);
        bool taken = false;
        if(sum>=nums[i]){
            taken = check(nums, sum-nums[i], i-1);
        } 

        return taken || notTaken;

    }


    bool canPartition(vector<int>& nums) {
        
        int temp = 0;
        int n = nums.size();
        for(auto it : nums){
            temp+=it;
        }
        if(temp%2!=0){
            return false;
        }
        int sum = temp/2;
        return check(nums, sum, n-1);

    }
};





class Solution {
public:
    bool check(vector<int>& nums, int sum, vector<vector<int>>& dp, int i){

        if(sum==0){
            return true;
        }

        if(i==0){
            return nums[i]==sum;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        bool notTaken = check(nums, sum, dp, i-1);
        bool taken = false;
        if(sum>=nums[i]){
            taken = check(nums, sum-nums[i], dp, i-1);
        } 

        return dp[i][sum] = taken || notTaken;

    }


    bool canPartition(vector<int>& nums) {
        
        int temp = 0;
        int n = nums.size();
        for(auto it : nums){
            temp+=it;
        }
        vector<vector<int>> dp(n, vector<int>(temp+1, -1));
        if(temp%2!=0){
            return false;
        }
        int sum = temp/2;
        return check(nums, sum, dp, n-1);

    }
};




class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int temp = 0;
        int n = nums.size();
        for(auto it : nums){
            temp+=it;
        }
        vector<vector<int>> dp(n, vector<int>(temp+1, 0));
        if(temp%2!=0){
            return false;
        }
        int sum = temp/2;
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }

        if(nums[0]<=sum){
            dp[0][nums[0]] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTaken = dp[i-1][j];
                bool taken = false;
                if(j>=nums[i]){
                    taken = dp[i-1][j-nums[i]];
                } 

                dp[i][j] = taken || notTaken;
            }
        }
        return dp[n-1][sum];

    }
};



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int temp = 0;
        int n = nums.size();
        for(auto it : nums){
            temp+=it;
        }
        vector<int> prev(temp+1, 0);
        if(temp%2!=0){
            return false;
        }
        int sum = temp/2;
        prev[0] = 1;
        prev[nums[0]] = 1;

        for(int i=1;i<n;i++){
            vector<int> curr(temp+1, 0);
            curr[0]=1;
            for(int j=1;j<=sum;j++){
                bool notTaken = prev[j];
                bool taken = false;
                if(j>=nums[i]){
                    taken = prev[j-nums[i]];
                } 

                curr[j] = taken || notTaken;
            }

            prev = curr;
        }
        return prev[sum];

    }
};