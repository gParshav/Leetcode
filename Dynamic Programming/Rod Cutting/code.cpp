class Solution{
  public:
    int find(int i, int price[], int n){
        
        if(i<0 || n<=0){
            return 0;
        }
        int notTaken = find(i-1, price, n);
        int taken = 0;
        if(n>=i+1){
            taken = price[i]+find(i, price, n-i-1);
        }
        
        return max(taken, notTaken);
            
    }
    
    int cutRod(int price[], int n) {
        //code here
        return find(n-1, price, n);
    }
};


class Solution{
  public:
    int find(int i, int price[], int n, vector<vector<int>>& dp){
        
        if(i<0 || n<=0){
            return 0;
        }
        
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        
        int notTaken = find(i-1, price, n, dp);
        int taken = 0;
        if(n>=i+1){
            taken = price[i]+find(i, price, n-i-1, dp);
        }
        
        return dp[i][n] = max(taken, notTaken);
            
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return find(n-1, price, n, dp);
    }
};


class Solution{
  public:
    int find(int i, int price[], int n, vector<vector<int>>& dp){
        
        int notTaken = find(i-1, price, n, dp);
        int taken = 0;
        if(n>=i+1){
            taken = price[i]+find(i, price, n-i-1, dp);
        }
        
        return dp[i][n] = max(taken, notTaken);
            
    }
    
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        int k = 1;
        for(int i=1;i<=n;i++){
            dp[0][i] = price[0]*k;
            k++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTaken = dp[i-1][j];
                int taken = 0;
                if(j>=i+1){
                    taken = price[i]+dp[i][j-i-1];
                }
                
                dp[i][j] = max(taken, notTaken);
            }
        }
        return dp[n-1][n];
    }
};



class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int k = 1;
        vector<int> prev(n+1, 0);
        for(int i=1;i<=n;i++){
            prev[i] = price[0]*k;
            k++;
        }
        for(int i=1;i<n;i++){
            vector<int> curr(n+1, 0);
            k = 1;
            for(int x=1;x<=n;x++){
                curr[x] = price[0]*k;
                k++;
            }
            for(int j=0;j<=n;j++){
                int notTaken = prev[j];
                int taken = 0;
                if(j>=i+1){
                    taken = price[i]+curr[j-i-1];
                }
                
                curr[j] = max(taken, notTaken);
            }
            
            prev = curr;
        }
        return prev[n];
    }
};