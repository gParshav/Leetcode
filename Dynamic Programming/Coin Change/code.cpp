class Solution {
public:
    int minCoins(int i, vector<int>& coins, int amt){
        if(i<0){
            if(amt==0){
                return 0;
            }

            return 1e9;
        }

        int notTaken = minCoins(i-1, coins, amt);
        int taken = 1e9;
        if(amt>=coins[i]){
            taken = 1 + minCoins(i, coins, amt-coins[i]);
        }

        int ans = min(notTaken, taken);
        return ans; 

    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int n = coins.size();
        int ans = minCoins(n-1, coins, amount);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};


// Memoization 1
class Solution {
public:
    int minCoins(int i, vector<int>& coins, int amt, vector<vector<int>>& dp){
        
        if(i<0){
            if(amt==0){
                return 0;
            }

            return 1e9;
        }

        if(dp[i][amt]!=-1){
            return dp[i][amt];
        }

        int notTaken = minCoins(i-1, coins, amt, dp);
        int taken = 1e9;
        if(amt>=coins[i]){
            taken = 1 + minCoins(i, coins, amt-coins[i], dp);
        }

        int ans = min(notTaken, taken);
        return dp[i][amt] = ans; 

    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = minCoins(n-1, coins, amount, dp);
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};

// Memoization 2

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0){
                dp[0][j] = j/coins[0];
            }

            else{
                dp[0][j] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            for(int amt=0;amt<=amount;amt++){
                int notTaken = 1e9;
                if(i>0){
                    notTaken = dp[i-1][amt];
                }
                int taken = 1e9;
                if(amt>=coins[i]){
                    taken = 1 + dp[i][amt-coins[i]];
                }

                dp[i][amt] = min(notTaken, taken);
            }
        }
        
        if(dp[n-1][amount]==1e9){
            return -1;
        }
        return dp[n-1][amount];
    }
};


class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        for(int j=0;j<=amount;j++){
            if(j%coins[0]==0){
                prev[j] = j/coins[0];
            }

            else{
                prev[j] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            vector<int> curr(amount+1, 0);
            for(int j=0;j<=amount;j++){
                if(j%coins[0]==0){
                    curr[j] = j/coins[0];
                }

                else{
                    curr[j] = 1e9;
                }
            }
            for(int amt=0;amt<=amount;amt++){
                int notTaken = 1e9;
                if(i>0){
                    notTaken = prev[amt];
                }
                int taken = 1e9;
                if(amt>=coins[i]){
                    taken = 1 + curr[amt-coins[i]];
                }

                curr[amt] = min(notTaken, taken);
            }

            prev=curr;
        }
        
        if(prev[amount]==1e9){
            return -1;
        }
        
        return prev[amount];
    }
};