class Solution {
public:
    int maxMoney(vector<int>& nums, int i){

        if(i==0){
            return nums[0];
        }

        if(i<0){
            return 0;
        }

        int e1 = nums[i]+maxMoney(nums, i-2);
        int e2 = maxMoney(nums, i-1);

        return max(e1, e2);

    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();
        return maxMoney(nums, n-1);

    }
};


class Solution {
public:
    int findMaxMoney(vector<int>& maxMoney, vector<int>& nums, int i){

        if(i==0){
            return nums[0];
        }

        if(i>=nums.size() || i<0){
            return 0;
        }

        if(maxMoney[i]!=-1){
            return maxMoney[i];
        }

        int e1 = nums[i]+findMaxMoney(maxMoney, nums, i-2);
        int e2 = findMaxMoney(maxMoney, nums, i-1);

        return maxMoney[i]=max(e1, e2);

    }

    int rob(vector<int>& nums) {
        

        int n = nums.size();
        vector<int> maxMoney(n, -1);
        return findMaxMoney(maxMoney, nums, n-1);

    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        

        int n = nums.size();
        vector<int> maxMoney(n, -1);
        maxMoney[0] = nums[0];
        for(int i=1;i<n;i++){
            int e1 = nums[i];
            if(i>1){
                e1 = nums[i]+maxMoney[i-2];
            }
            int e2 = maxMoney[i-1];
            maxMoney[i]=max(e1, e2);

        }
        return maxMoney[n-1];

    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        

        int n = nums.size();
        int prev = nums[0], prev2 = -1;
        for(int i=1;i<n;i++){
            int e1 = nums[i];
            if(i>1){
                e1 = nums[i]+prev2;
            }
            int e2 = prev;
            prev2 = prev;
            prev=max(e1, e2);

        }
        return prev;

    }
};