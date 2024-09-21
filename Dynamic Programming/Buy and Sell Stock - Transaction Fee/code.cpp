class Solution {
public:
    int findProfit(int i, int n, int haveStock, vector<int>& prices, int fee){

        if(i==n-1){
            if(haveStock){
                if(prices[i]>fee){
                    return prices[i] - fee;
                }

                return 0;
            }

            else{
                return 0;
            }
        }

        if(haveStock){
            int sell = prices[i]-fee+findProfit(i+1, n, 0, prices, fee);
            int dontSell = findProfit(i+1, n, 1, prices, fee);
            return max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i] + findProfit(i+1, n, 1, prices, fee);
            int dontBuy = findProfit(i+1, n, 0, prices, fee);
            return max(buy, dontBuy);
        }

    }


    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size(), haveStock = 0;
        return findProfit(0, n, haveStock, prices, fee);
        
    }
};

class Solution {
public:
    int findProfit(int i, int n, int haveStock, vector<int>& prices, int fee, vector<vector<int>>& dp){

        if(i==n-1){
            if(haveStock){
                if(prices[i]>fee){
                    return prices[i] - fee;
                }

                return 0;
            }

            else{
                return 0;
            }
        }

        if(dp[i][haveStock]!=-1){
            return dp[i][haveStock];
        }

        if(haveStock){
            int sell = prices[i]-fee+findProfit(i+1, n, 0, prices, fee, dp);
            int dontSell = findProfit(i+1, n, 1, prices, fee, dp);
            return dp[i][haveStock] = max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i] + findProfit(i+1, n, 1, prices, fee, dp);
            int dontBuy = findProfit(i+1, n, 0, prices, fee, dp);
            return dp[i][haveStock] = max(buy, dontBuy);
        }

    }


    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size(), haveStock = 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(0, n, haveStock, prices, fee, dp);
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size(), haveStock = 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[n-1][0] = 0;
        if(prices[n-1]>fee){
            dp[n-1][1] = prices[n-1] - fee;
        }

        else{
            dp[n-1][1] = 0;
        }

        for(int i=n-2;i>=0;i--){
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i]-fee+dp[i+1][0];
                    int dontSell = dp[i+1][1];
                    dp[i][haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i] + dp[i+1][1];
                    int dontBuy = dp[i+1][0];
                    dp[i][haveStock] = max(buy, dontBuy);
                }
            }
        }
        
        return dp[0][0];
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n=prices.size();
        vector<int> front(2, 0);
        vector<int> curr(2, 0);
        front[0] = 0;
        if(prices[n-1]>fee){
            front[1] = prices[n-1] - fee;
        }

        else{
            front[1] = 0;
        }

        for(int i=n-2;i>=0;i--){
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i]-fee+front[0];
                    int dontSell = front[1];
                    curr[haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i] + front[1];
                    int dontBuy = front[0];
                    curr[haveStock] = max(buy, dontBuy);
                }
            }

            front = curr;
        }
        
        return front[0];
        
    }
};