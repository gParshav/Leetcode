class Solution {
public:
    int findCnt(int i, int j, string s, string t){
        if(j<0){
            return 1;
        }

        if(i<0){
            return 0;
        }

        int taken = 0;
        if(s[i]==t[j]){
            taken = findCnt(i-1, j-1, s, t);
        }

        int notTaken = findCnt(i-1, j, s, t);
        return taken+notTaken;
    }
    int numDistinct(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        return findCnt(n1-1, n2-1, s, t);

    }
};



class Solution {
public:
    int findCnt(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j<0){
            return 1;
        }

        if(i<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int taken = 0;
        if(s[i]==t[j]){
            taken = findCnt(i-1, j-1, s, t, dp);
        }

        int notTaken = findCnt(i-1, j, s, t, dp);
        return dp[i][j] = taken+notTaken;
    }
    int numDistinct(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return findCnt(n1-1, n2-1, s, t, dp);

    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<long long>> dp(n1+1, vector<long long>(n2+1, 0));
        for(int i=0;i<=n1;i++){
            dp[i][0] = 1;
        }

        for(int j=1;j<=n2;j++){
            dp[0][j] = 0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int taken = 0;
                if(s[i-1]==t[j-1]){
                    taken = dp[i-1][j-1];
                }

                int notTaken = dp[i-1][j];
                dp[i][j] = taken;
                dp[i][j]+=notTaken;
            }
        }
        return dp[n1][n2];

    }
};



class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n1 = s.size();
        int n2 = t.size();
        vector<long long>prev(n2+1, 0);
        prev[0] = 1;
        for(int i=1;i<=n1;i++){
            vector<long long>curr(n2+1, 0);
            curr[0] = 1;
            for(int j=1;j<=n2;j++){
                int taken = 0;
                if(s[i-1]==t[j-1]){
                    taken = prev[j-1];
                }

                int notTaken = prev[j];
                curr[j] = taken;
                curr[j]+=notTaken;
            }

            prev = curr;
        }
        return prev[n2];

    }
};