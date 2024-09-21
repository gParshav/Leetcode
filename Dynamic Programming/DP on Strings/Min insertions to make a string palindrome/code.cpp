class Solution {
public:
    int findLen(int i, int j, string& s, string& t){
        if(i<0 || j<0){
            return 0;
        }

        if(s[i]==t[j]){
            return 1+findLen(i-1, j-1, s, t);
        }

        return max(findLen(i-1, j, s, t), findLen(i, j-1, s, t));
    }
    int minInsertions(string s) {
        
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        int len = findLen(n-1, n-1, s, t);
        return n - len;

    }
};


class Solution {
public:
    int findLen(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return dp[i][j] = 1+findLen(i-1, j-1, s, t, dp);
        }

        return dp[i][j] = max(findLen(i-1, j, s, t, dp), findLen(i, j-1, s, t, dp));
    }
    int minInsertions(string s) {
        
        int n = s.size();
        string t = s;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        reverse(t.begin(), t.end());
        int len = findLen(n-1, n-1, s, t, dp);
        return n - len;

    }
};


class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        string t = s;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        reverse(t.begin(), t.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        int len = dp[n][n];
        return n - len;

    }
};



class Solution {
public:
    int minInsertions(string s) {
        
        int n = s.size();
        string t = s;
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        reverse(t.begin(), t.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    curr[j] = 1+prev[j-1];
                }

                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
                
            }

            prev = curr;
        }
        int len = prev[n];
        return n - len;

    }
};