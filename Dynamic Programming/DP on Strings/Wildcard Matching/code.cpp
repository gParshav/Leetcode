class Solution {
public:
    bool findMatch(int i, int j, string& s, string& p){
        

        if(i<0 && j<0){
            return true;
        }

        if(i<0 && p[j]=='*'){
            return findMatch(i, j-1, s, p);
        }

        if(i<0 || j<0){
            return false;
        }

        if(p[j]=='*'){
            bool once = findMatch(i-1, j-1, s, p);
            bool more = findMatch(i-1, j, s, p);
            bool three = findMatch(i, j-1, s, p);
            return once || more || three; 
            
        }
        
        else if(s[i]==p[j] || p[j]=='?'){
            return findMatch(i-1, j-1, s, p);
        }

        return false;

    }

    bool isMatch(string s, string p) {
        
        int n1 = s.size();
        int n2 = p.size();
        return findMatch(n1-1, n2-1, s, p);

    }
};





class Solution {
public:
    bool findMatch(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        

        if(i<0 && j<0){
            return true;
        }

        if(i<0 && p[j]=='*'){
            return findMatch(i, j-1, s, p, dp);
        }

        if(i<0 || j<0){
            return false;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(p[j]=='*'){
            bool once = findMatch(i-1, j-1, s, p, dp);
            bool more = findMatch(i-1, j, s, p, dp);
            bool three = findMatch(i, j-1, s, p, dp);
            return dp[i][j] = once || more || three; 
            
        }
        
        else if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j] =findMatch(i-1, j-1, s, p, dp);
        }

        return false;

    }

    bool isMatch(string s, string p) {
        
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return findMatch(n1-1, n2-1, s, p, dp);

    }
};




class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        dp[0][0] = 1;
        int k=1;
        while(p[k-1]=='*' && k<=n2){
            dp[0][k] = 1;
            k++;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(p[j-1]=='*'){
                    bool once = dp[i-1][j-1];
                    bool more = dp[i-1][j];
                    bool three = dp[i][j-1];
                    dp[i][j] = once || more || three; 
                    continue;
                    
                }
                
                else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }

            }
        }
        return dp[n1][n2];

    }
};





class Solution {
public:
    bool isMatch(string s, string p) {
        
        int n1 = s.size();
        int n2 = p.size();
        vector<int> prev(n2+1, 0);
        prev[0] = 1;
        int k=1;
        while(p[k-1]=='*' && k<=n2){
            prev[k] = 1;
            k++;
        }

        for(int i=1;i<=n1;i++){
            vector<int> curr(n2+1, 0);
            int k=1;
            while(p[k-1]=='*' && k<=n2){
                curr[k] = 1;
                k++;
            }
            for(int j=1;j<=n2;j++){
                if(p[j-1]=='*'){
                    bool once = prev[j-1];
                    bool more = prev[j];
                    bool three = curr[j-1];
                    curr[j] = once || more || three; 
                    continue;
                    
                }
                
                else if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j] = prev[j-1];
                }

            }
            prev = curr;
        }


        return prev[n2];

    }
};