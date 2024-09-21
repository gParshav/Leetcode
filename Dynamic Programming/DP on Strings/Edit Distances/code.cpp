class Solution {
public:
    int findOps(int i, int j, string& word1, string& word2){
        

        if(i<0 && j<0){
            //When the entire word2 has been achieved
            return 0;
        }

        if(j<0){
            //When the entire word2 has been achieved
            //Delete whatever is remaining in word1
            return i+1;
        }

        if(i<0){
            //Insert everything that is remaining to be found in word2
            return j+1;
        }

        if(word1[i]==word2[j]){
            //Do nothing
            return findOps(i-1, j-1, word1, word2);
        }

        else{
            int del = 1+findOps(i-1, j, word1, word2); 
            int ins = 1+findOps(i-1, j-1, word1, word2);
            int insLater = 1+findOps(i, j-1, word1, word2);
            return min(del, min(ins, insLater));
        }


    }


    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        if(n2==0){
            return n1;
        }
        return findOps(n1-1, n2-1, word1, word2);
        
    }
};


class Solution {
public:
    int findOps(int i, int j, string& word1, string& word2, vector<vector<int>>& dp){
        

        if(i<0 && j<0){
            //When the entire word2 has been achieved
            return 0;
        }

        if(j<0){
            //When the entire word2 has been achieved
            //Delete whatever is remaining in word1
            return i+1;
        }

        if(i<0){
            //Insert everything that is remaining to be found in word2
            return j+1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i]==word2[j]){
            //Do nothing
            return dp[i][j] = findOps(i-1, j-1, word1, word2, dp);
        }

        else{
            int del = 1+findOps(i-1, j, word1, word2, dp); 
            int ins = 1+findOps(i-1, j-1, word1, word2, dp);
            int insLater = 1+findOps(i, j-1, word1, word2, dp);
            return dp[i][j] = min(del, min(ins, insLater));
        }


    }


    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return findOps(n1-1, n2-1, word1, word2, dp);
        
    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i=1;i<=n1;i++){
            dp[i][0] = i;
        }

        for(int j=1;j<=n2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    //Do nothing
                    dp[i][j] = dp[i-1][j-1];
                }

                else{
                    int del = 1+dp[i-1][j]; 
                    int ins = 1+dp[i-1][j-1];
                    int insLater = 1+dp[i][j-1];
                    dp[i][j] = min(del, min(ins, insLater));
                }
            }
        }
        return dp[n1][n2];
        
    }
};



class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int>prev(n2+1, 0);
        for(int j=1;j<=n2;j++){
            prev[j] = j;
        }
        for(int i=1;i<=n1;i++){
            vector<int>curr(n2+1, 0);
            curr[0] = i;
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    //Do nothing
                    curr[j] = prev[j-1];
                }

                else{
                    int del = 1+prev[j]; 
                    int ins = 1+prev[j-1];
                    int insLater = 1+curr[j-1];
                    curr[j] = min(del, min(ins, insLater));
                }
            }

            prev = curr;
        }
        return prev[n2];
        
    }
};