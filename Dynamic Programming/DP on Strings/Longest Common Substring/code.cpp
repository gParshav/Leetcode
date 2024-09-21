class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x = i-1;
                int y = j-1;
                if(S1[x]==S2[y]){
                    if(x>0 && j>0 && S1[x-1]==S2[y-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    
                    else{
                        dp[i][j] = 1;
                    }
                }
                
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ans = max(ans, dp[i][j]);
            }
            
        }
        
        
        return ans;
    }
};


class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x = i-1;
                int y = j-1;
                if(S1[x]==S2[y]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                
                else{
                    dp[i][j] = 0;
                }
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};



class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x = i-1;
                int y = j-1;
                if(S1[x]==S2[y]){
                     curr[j] = 1+prev[j-1];
                }
                
                else{
                    curr[j] = 0;
                }
                
                ans = max(ans, curr[j]);
            }
            
            prev = curr;
        }
        
        return ans;
    }
};