class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> track(n, 0);
        int startIdx = 0, temp = 0;
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        for(int i=0;i<n;i++){
            track[i] = i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        track[i] = j;
                        dp[i] = max(dp[i], 1+dp[j]);
                    }
                }
            }

            if(dp[i]>temp){
                temp = dp[i];
                startIdx = i;
            }
        }

        while(1){
            ans.push_back(nums[startIdx]);
            if(startIdx==0 || startIdx==track[startIdx]){
                break;
            }

            startIdx = track[startIdx];
        }

        reverse(nums.begin(), nums.end());
        return ans;

    }
};