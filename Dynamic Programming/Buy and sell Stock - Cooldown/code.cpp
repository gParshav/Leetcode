class Solution {
public:
    int findProfit(int i, int haveStock, int n, vector<int>& prices){

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(haveStock){
            int sell = prices[i];
            if(i<n-2){
                sell = prices[i]+findProfit(i+2, 0, n, prices);
            }
            int dontSell = findProfit(i+1, 1, n, prices);
            return max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, 1, n, prices);
            int dontBuy = findProfit(i+1, 0, n, prices);
            return max(buy, dontBuy);
        }

    }


    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), haveStock = 0;
        return findProfit(0, haveStock, n, prices);

    }
};


class Solution {
public:
    int findProfit(int i, int haveStock, int n, vector<int>& prices, vector<vector<int>>& dp){

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(dp[i][haveStock]!=-1){
            return dp[i][haveStock];
        }

        if(haveStock){
            int sell = prices[i];
            if(i<n-2){
                sell = prices[i]+findProfit(i+2, 0, n, prices, dp);
            }
            int dontSell = findProfit(i+1, 1, n, prices, dp);
            return dp[i][haveStock] = max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, 1, n, prices, dp);
            int dontBuy = findProfit(i+1, 0, n, prices, dp);
            return dp[i][haveStock] = max(buy, dontBuy);
        }

    }


    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), haveStock = 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(0, haveStock, n, prices, dp);

    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i];
                    if(i<n-2){
                        sell = prices[i]+dp[i+2][0];
                    }
                    int dontSell = dp[i+1][1];
                    dp[i][haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i]+dp[i+1][1];
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
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> front(2, 0);
        vector<int> front2(2, 0);
        front[0] = 0;
        front[1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            curr[0] = 0;
            curr[1] = prices[i];
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i];
                    if(i<n-2){
                        sell = prices[i]+front2[0];
                    }
                    int dontSell = front[1];
                    curr[haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i]+front[1];
                    int dontBuy = front[0];
                    curr[haveStock] = max(buy, dontBuy);
                }
            }

            front2 = front;
            front = curr;

        }
        return front[0];

    }
};