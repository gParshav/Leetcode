class Solution{
public:
    int find(int i, int W, int val[], int wt[]){
        
        
        if(i<0){
            return 0;
        }
        
        if(W==0){
            return 0;
        }
        
        int notTaken = find(i-1, W, val, wt);
        int taken = 0;
        if(wt[i]<=W){
            taken = val[i]+find(i, W-wt[i], val, wt);
        }
        
        return max(taken, notTaken);
            
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        return find(N-1, W, val, wt);
    }
};




class Solution{
public:
    int find(int i, int W, int val[], int wt[], vector<vector<int>>& dp){
        
        
        if(i<0){
            return 0;
        }
        
        if(W==0){
            return 0;
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int notTaken = find(i-1, W, val, wt, dp);
        int taken = 0;
        if(wt[i]<=W){
            taken = val[i]+find(i, W-wt[i], val, wt, dp);
        }
        
        return dp[i][W] = max(taken, notTaken);
            
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1, -1));
        return find(N-1, W, val, wt, dp);
    }
};




class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N, vector<int>(W+1, 0));
        for(int j=0;j<=W;j++){
            int temp = j/wt[0];
            dp[0][j] = temp*val[0];
        }
        
        for(int i=1;i<N;i++){
            for(int j=0;j<=W;j++){
                int notTaken = dp[i-1][j];
                int taken = 0;
                if(wt[i]<=j){
                    taken = val[i]+dp[i][j-wt[i]];
                }
                
                dp[i][j] = max(taken, notTaken);
            }
        }
        
        return dp[N-1][W];
    }
};




class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        
        vector<int> prev(W+1, 0);
        for(int j=0;j<=W;j++){
            int temp = j/wt[0];
            prev[j] = temp*val[0];
        }
        
        for(int i=1;i<N;i++){
            vector<int> curr(W+1, 0);
            for(int j=0;j<=W;j++){
                int temp = j/wt[0];
                curr[j] = temp*val[0];
            }
            
            for(int j=0;j<=W;j++){
                int notTaken = prev[j];
                int taken = 0;
                if(wt[i]<=j){
                    taken = val[i]+curr[j-wt[i]];
                }
                
                curr[j] = max(taken, notTaken);
            }
            
            prev = curr;
        }
        
        return prev[W];
    }
};