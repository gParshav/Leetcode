class Solution {
public:
    int findProfit(int i, int cnt, int haveStock, int n, vector<int>& prices){

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(cnt==2){
            return 0;
        }

        if(haveStock){
            int sell = prices[i]+findProfit(i+1, cnt+1, 0, n, prices);
            int dontSell = findProfit(i+1, cnt, 1, n, prices);
            return max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, cnt, 1, n, prices);
            int dontBuy = findProfit(i+1, cnt, 0, n, prices);
            return max(buy, dontBuy);
        }

    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), cnt = 0, haveStock = 0;
        return findProfit(0, cnt, haveStock, n, prices);

    }
};


class Solution {
public:
    int findProfit(int i, int cnt, int haveStock, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){

        if(i==n-1){
            if(haveStock){
                return prices[i];
            }

            else{
                return 0;
            }
        }

        if(cnt==2){
            return 0;
        }

        if(dp[i][haveStock][cnt]!=-1){
            return dp[i][haveStock][cnt];
        }

        if(haveStock){
            int sell = prices[i]+findProfit(i+1, cnt+1, 0, n, prices, dp);
            int dontSell = findProfit(i+1, cnt, 1, n, prices, dp);
            return dp[i][haveStock][cnt] = max(sell, dontSell);
        }

        else{
            int buy = -1*prices[i]+findProfit(i+1, cnt, 1, n, prices, dp);
            int dontBuy = findProfit(i+1, cnt, 0, n, prices, dp);
            return dp[i][haveStock][cnt] = max(buy, dontBuy);
        }

    }

    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), cnt = 0, haveStock = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return findProfit(0, cnt, haveStock, n, prices, dp);

    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(), cnt = 0, haveStock = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][2] = 0;
            }
        }

        for(int i=0;i<=2;i++){
            dp[n-1][1][i] = prices[n-1];
            dp[n-1][0][i] = 0;
        }

        for(int i=n-2;i>=0;i--){
            for(int haveStock=0;haveStock<=1;haveStock++){
                for(int cnt=1;cnt>=0;cnt--){
                    if(haveStock){
                        int sell = prices[i]+dp[i+1][0][cnt+1];
                        int dontSell = dp[i+1][1][cnt];
                        dp[i][haveStock][cnt] = max(sell, dontSell);
                    }

                    else{
                        int buy = -1*prices[i]+dp[i+1][1][cnt];
                        int dontBuy = dp[i+1][0][cnt];
                        dp[i][haveStock][cnt] = max(buy, dontBuy);
                    }
                }
            }
        }
        return dp[0][0][0];

    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> front(2, vector<int>(3, 0));
        for(int j=0;j<=1;j++){
            front[j][2] = 0;
        }
    
        for(int i=0;i<=2;i++){
            front[1][i] = prices[n-1];
            front[0][i] = 0;
        }

        for(int i=n-2;i>=0;i--){
            vector<vector<int>> curr(2, vector<int>(3, 0));
            for(int j=0;j<=1;j++){
                curr[j][2] = 0;
            }
        
            for(int k=0;k<=2;k++){
                curr[1][k] = prices[i];
                curr[0][k] = 0;
            }
            for(int haveStock=0;haveStock<=1;haveStock++){
                for(int cnt=1;cnt>=0;cnt--){
                    if(haveStock){
                        int sell = prices[i]+front[0][cnt+1];
                        int dontSell = front[1][cnt];
                        curr[haveStock][cnt] = max(sell, dontSell);
                    }

                    else{
                        int buy = -1*prices[i]+front[1][cnt];
                        int dontBuy = front[0][cnt];
                        curr[haveStock][cnt] = max(buy, dontBuy);
                    }
                }
            }

            front = curr;
        }
        return front[0][0];

    }
};