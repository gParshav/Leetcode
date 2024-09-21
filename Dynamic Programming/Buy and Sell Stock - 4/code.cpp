class Solution {
public:
    int findProfit(int i, int k, int haveStock, int n, vector<int>& prices){

        if(k==0){
            return 0;
        }

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(haveStock){
            int sell = prices[i]+findProfit(i+1, k-1, 0, n, prices);
            int dontSell = findProfit(i+1, k, 1, n, prices);
            return max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, k, 1, n, prices);
            int dontBuy = findProfit(i+1, k, 0, n, prices);
            return max(buy, dontBuy);
        }
        

    }


    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size(), haveStock = 0;
        return findProfit(0, k, haveStock, n, prices);

    }
};


class Solution {
public:
    int findProfit(int i, int k, int haveStock, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){

        if(k==0){
            return 0;
        }

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(dp[i][k][haveStock]!=-1){
            return dp[i][k][haveStock];
        }

        if(haveStock){
            int sell = prices[i]+findProfit(i+1, k-1, 0, n, prices, dp);
            int dontSell = findProfit(i+1, k, 1, n, prices, dp);
            return dp[i][k][haveStock] = max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, k, 1, n, prices, dp);
            int dontBuy = findProfit(i+1, k, 0, n, prices, dp);
            return dp[i][k][haveStock] = max(buy, dontBuy);
        }
        

    }


    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size(), haveStock = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        return findProfit(0, k, haveStock, n, prices, dp);

    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
        for(int i=0;i<n;i++){
            for(int j=0;j<=1;j++){
                dp[i][0][j] = 0;
            }
        }

        for(int x=0;x<=k;x++){
            dp[n-1][x][0] = 0;
            dp[n-1][x][1] = prices[n-1];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=k;j++){
                for(int haveStock=0;haveStock<=1;haveStock++){
                    if(haveStock){
                        int sell = prices[i]+dp[i+1][j-1][0];
                        int dontSell = dp[i+1][j][1];
                        dp[i][j][haveStock] = max(sell, dontSell);
                    }

                    else{
                        int buy = -1*prices[i]+dp[i+1][j][1];
                        int dontBuy = dp[i+1][j][0];
                        dp[i][j][haveStock] = max(buy, dontBuy);
                    }
                }
            }
        }
        return dp[0][k][0];

    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> front(k+1, vector<int>(2, -1));
        for(int j=0;j<=1;j++){
            front[0][j] = 0;
        }

        for(int x=0;x<=k;x++){
            front[x][0] = 0;
            front[x][1] = prices[n-1];
        }

        for(int i=n-2;i>=0;i--){
            vector<vector<int>> curr(k+1, vector<int>(2, -1));
            for(int j=0;j<=1;j++){
                curr[0][j] = 0;
            }

            for(int x=0;x<=k;x++){
                curr[x][0] = 0;
                curr[x][1] = prices[i];
            }
            for(int j=1;j<=k;j++){
                for(int haveStock=0;haveStock<=1;haveStock++){
                    if(haveStock){
                        int sell = prices[i]+front[j-1][0];
                        int dontSell = front[j][1];
                        curr[j][haveStock] = max(sell, dontSell);
                    }

                    else{
                        int buy = -1*prices[i]+front[j][1];
                        int dontBuy = front[j][0];
                        curr[j][haveStock] = max(buy, dontBuy);
                    }
                }
            }

            front = curr;
        }
        return front[k][0];

    }
};