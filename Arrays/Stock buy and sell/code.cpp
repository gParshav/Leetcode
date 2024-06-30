class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int ans = 0, n = prices.size();
        for(int i=0;i<n-1;i++){
            int buy = prices[i];
            for(int j = i+1;j<n;j++){
                ans = max(ans, prices[j]-buy);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = 1e5;
        int ans = 0;
        for(auto it : prices){     
            ans = max(ans, it-buy);
            if(it<buy){
                buy = it;
            }
        }
        return ans;


    }
};