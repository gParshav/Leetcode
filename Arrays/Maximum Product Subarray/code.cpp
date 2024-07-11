class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN, prod = 1, n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                prod = 1;
                for(int k=i;k<=j;k++){
                    prod = prod*nums[k];
                }

                ans = max(ans, prod);
            }
        }

        return ans;

    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        long long int ans = INT_MIN, prod = 1, n = nums.size();
        for(int i=0;i<n;i++){
            prod = 1;
            for(int j=i;j<n;j++){
                prod = prod*nums[j];
                ans = max(ans, prod);
            }
        }

        return (int)ans;

    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        long long currProd = 1, ans = INT_MIN, n = nums.size();
        vector<long long> preFix(n, 0);
        vector<long long> suFix(n, 0);
        for(long long i=0;i<n;i++){
            
            currProd = currProd*nums[i];
            preFix[i] = currProd;
            if(nums[i]==0){
                currProd = 1;
                continue;
            }
        }

        currProd = 1;
        for(long long i=n-1;i>=0;i--){
             currProd = currProd*nums[i];
             suFix[i] = currProd;
             if(nums[i]==0){
                currProd = 1;
                continue;
            }
        }

        for(auto it : preFix){
            ans = max(it, ans);
        }

        for(auto it : suFix){
            ans = max(it, ans);
        }

        

        return (int)ans;

    }
};