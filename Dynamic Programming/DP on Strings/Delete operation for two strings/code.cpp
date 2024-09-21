class Solution {
public:

    int findLen(int i, int j, string& word1, string& word2){

        if(i<0 || j<0){
            return 0;
        }

        if(word1[i]==word2[j]){
            return 1+findLen(i-1, j-1, word1, word2);
        }

        return max(findLen(i-1, j, word1, word2), findLen(i, j-1, word1, word2));

    }

    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        int lcs = findLen(n1-1, n2-1, word1, word2);
        return n1+n2-2*lcs;
    }
};



class Solution {
public:

    int findLen(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){

        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            return dp[i][j] = 1+findLen(i-1, j-1, word1, word2, dp);
        }

        return dp[i][j] = max(findLen(i-1, j, word1, word2, dp), findLen(i, j-1, word1, word2, dp));

    }

    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        int lcs = findLen(n1-1, n2-1, word1, word2, dp);
        return n1+n2-2*lcs;
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }

                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int lcs = dp[n1][n2];
        return n1+n2-2*lcs;
    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> prev(n2+1, 0);
        vector<int> curr(n2+1, 0);
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    curr[j] = 1+prev[j-1];
                }

                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }

            prev=curr;
        }

        int lcs = prev[n2];
        return n1+n2-2*lcs;
    }
};