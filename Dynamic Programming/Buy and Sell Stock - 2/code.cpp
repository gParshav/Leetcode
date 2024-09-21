class Solution {
public:
    int findProfit(int i, vector<int>& prices, int haveStock){

        if(i==prices.size()-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }


        if(haveStock){

            int sell = prices[i]+findProfit(i, prices, 0);
            int dontSell = findProfit(i+1, prices, 1);
            return max(sell, dontSell);

        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, prices, 1);
            int dontBuy  = findProfit(i+1, prices, 0);
            return max(buy, dontBuy);
        }

    }

    int maxProfit(vector<int>& prices) {
        
        int haveStock = 0;
        return findProfit(0, prices, haveStock);

    }
};


class Solution {
public:
    int findProfit(int i, int n, vector<int>& prices, int haveStock, vector<vector<int>>& dp){

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

            int sell = prices[i]+findProfit(i, n, prices, 0, dp);
            int dontSell = findProfit(i+1, n, prices, 1, dp);
            return dp[i][haveStock] = max(sell, dontSell);

        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, n, prices, 1, dp);
            int dontBuy  = findProfit(i+1, n, prices, 0, dp);
            return dp[i][haveStock] = max(buy, dontBuy);
        }

    }

    int maxProfit(vector<int>& prices) {
        
        int haveStock = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findProfit(0, n, prices, haveStock, dp);

    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int haveStock = 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        dp[n-1][0] = 0;
        dp[n-1][1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i]+dp[i][0];
                    int dontSell = dp[i+1][1];
                    dp[i][haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i]+dp[i+1][1];
                    int dontBuy  = dp[i+1][0];
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
        int haveStock = 0;
        int n = prices.size();
        vector<int> front(2, -1);
        front[0] = 0;
        front[1] = prices[n-1];
        for(int i=n-2;i>=0;i--){
            vector<int> curr(2, -1);
            curr[0] = 0;
            curr[1] = prices[n-1];
            for(int haveStock=0;haveStock<=1;haveStock++){
                if(haveStock){
                    int sell = prices[i]+curr[0];
                    int dontSell = front[1];
                    curr[haveStock] = max(sell, dontSell);
                }

                else{
                    int buy = -1*prices[i]+front[1];
                    int dontBuy  = front[0];
                    curr[haveStock] = max(buy, dontBuy);
                }
            }
            front = curr;
        }
        return front[0];

    }
};