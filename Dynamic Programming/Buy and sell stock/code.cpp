class Solution {
public:

    int findProfit(int i, vector<int>& prices, int k){

        if(i==0){
            if(k==0){
                return 0;
            }

            if(k==1){
                return -1*prices[0];
            }
        }

        if(k==0){
            int sell = prices[i] + findProfit(i-1, prices, 1);
            int dontSell = findProfit(i-1, prices, 0);
            return max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i];
            int dontBuy = findProfit(i-1, prices, 1);
            return max(buy, dontBuy);
        }   

    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int k=0, temp=0;
        return findProfit(n-1, prices, k);
    }
};


class Solution {
public:

    int findProfit(int i, vector<int>& prices, int k, vector<vector<int>>& dp){

        if(i==0){
            if(k==0){
                return 0;
            }

            if(k==1){
                return -1*prices[0];
            }
        }

        if(dp[i][k]!=-1){
            return dp[i][k]; 
        }

        if(k==0){
            int sell = prices[i] + findProfit(i-1, prices, 1, dp);
            int dontSell = findProfit(i-1, prices, 0, dp);
            return dp[i][k] = max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i];
            int dontBuy = findProfit(i-1, prices, 1, dp);
            return dp[i][k] = max(buy, dontBuy);
        }   

    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int k=0, temp=0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(n-1, prices, k, dp);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {  
        int n = prices.size();
        int k=0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -1*prices[0];
        for(int i=1;i<n;i++){
            for(int k=0;k<=1;k++){
                if(k==0){
                    int sell = prices[i] + dp[i-1][1];
                    int dontSell = dp[i-1][0];
                    dp[i][k] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i];
                    int dontBuy = dp[i-1][1];
                    dp[i][k] = max(buy, dontBuy);
                }
            }
            
        }
        return dp[n-1][0];
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {  
        int n = prices.size();
        int k=0;
        vector<int> prev(2, 0);
        prev[0] = 0;
        prev[1] = -1*prices[0];
        for(int i=1;i<n;i++){
            vector<int> curr(2, 0);
            curr[0] = 0;
            curr[1] = -1*prices[0];
            for(int k=0;k<=1;k++){
                if(k==0){
                    int sell = prices[i] + prev[1];
                    int dontSell = prev[0];
                    curr[k] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i];
                    int dontBuy = prev[1];
                    curr[k] = max(buy, dontBuy);
                }

                
            }
            prev = curr;
            
        }
        return prev[0];
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {  
        int n = prices.size();
        int k=0;
        int prevx = 0;
        int prevy = -1*prices[0];
        for(int i=1;i<n;i++){
            int currx = 0;
            int curry = -1*prices[0];
            for(int k=0;k<=1;k++){
                if(k==0){
                    int sell = prices[i] + prevy;
                    int dontSell = prevx;
                    currx = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i];
                    int dontBuy = prevy;
                    curry = max(buy, dontBuy);
                }

                
            }
            prevx = currx;
            prevy = curry;
            
        }
        return prevx;
    }
};