class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = -1e5;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int k = i;k<=j;k++){
                    sum+=nums[k];
                }
                ans = max(ans, sum);
            }

        }

        return ans;

    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = -1e5;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans = max(ans, sum);
            }
        }

        return ans;

    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int ans = -1e5, temp = 0;
        for(int i=0;i<n;i++){
            if(temp<0 && nums[i]>temp){
                temp = nums[i];
                ans = max(ans, temp);
                continue;
            }
            temp+=nums[i];
            ans = max(ans, temp);
        }

        return ans;

    }
};