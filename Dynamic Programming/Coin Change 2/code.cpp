class Solution {
public:
    int find(int i, int amount, vector<int>& coins){
        	
        if(amount==0){
            return 1;
        }

        if(i==0){
            if(amount>=coins[0] && amount%coins[0]==0){
                return 1;
            }

            return 0;
        }

        if(amount<0){
            return 0;
        }


        int taken = find(i, amount-coins[i], coins);
        int notTaken = find(i-1, amount, coins);
        return taken+notTaken;
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        return find(n-1, amount, coins);

    }
};


class Solution {
public:
    int find(int i, int amount, vector<int>& coins, vector<vector<int>>& dp){
        	
        if(amount==0){
            return 1;
        }

        if(i==0){
            if(amount>=coins[0] && amount%coins[0]==0){
                return 1;
            }

            return 0;
        }

        if(amount<0){
            return 0;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int taken = find(i, amount-coins[i], coins, dp);
        int notTaken = find(i-1, amount, coins, dp);
        return dp[i][amount] = taken+notTaken;
    }

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return find(n-1, amount, coins, dp);

    }
};


class Solution {
public:

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }

        for(int i=0;i<=amount;i++){
            if(i>=coins[0] && i%coins[0]==0){
                dp[0][i] = 1;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int taken = 0;
                if(j>=coins[i]){
                    taken = dp[i][j-coins[i]];
                }
                int notTaken = dp[i-1][j];
                dp[i][j] = taken+notTaken;
            }
        }


        return dp[n-1][amount];

    }
};




class Solution {
public:

    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<int> prev(amount+1, 0);
        prev[0] = 1;
        for(int i=0;i<=amount;i++){
            if(i>=coins[0] && i%coins[0]==0){
                prev[i] = 1;
            }
        }

        for(int i=1;i<n;i++){
            vector<int> curr(amount+1, 0);
            curr[0] = 1;
            for(int k=0;k<=amount;k++){
                if(k>=coins[0] && k%coins[0]==0){
                    curr[k] = 1;
                }
            }

            for(int j=0;j<=amount;j++){
                int taken = 0;
                if(j>=coins[i]){
                    taken = curr[j-coins[i]];
                }
                int notTaken = prev[j];
                curr[j] = taken+notTaken;
            }

            prev = curr;
        }


        return prev[amount];

    }
};