class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<int> track(n, 0);
        int startIdx = -1, temp = -1;
        for(int i=0;i<n;i++){
            track[i] = i;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i] = 1+dp[j];
                        track[i] = j;
                    }
                }
                
                if(dp[i]>temp){
                    temp = dp[i];
                    startIdx = i;
                }
            }
        }
        
        vector<int> ans;
        if(startIdx==-1){
            return arr;
        }
        while(1){
            if(startIdx==0){
                ans.push_back(arr[startIdx]);
                break;
            }
            
            else{
                ans.push_back(arr[startIdx]);
                if(startIdx==track[startIdx]){
                    break;
                }
                else{
                    startIdx = track[startIdx];    
                }
                
            }
            
            
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};