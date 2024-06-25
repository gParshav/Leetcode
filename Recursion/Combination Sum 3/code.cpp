class Solution {
public:

    void f(int ind, int k, int target, vector<int> temp, vector<int> &nums, vector<vector<int>> &ans){

        if(k==0 && target==0){
            ans.push_back(temp);
            return;
        }

        if(ind>=nums.size()){
            return;
        }

        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }

            temp.push_back(nums[i]);
            f(i+1, k-1, target-nums[i], temp, nums, ans);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        
        vector<int> temp;
        vector<vector<int>> ans;
        f(0, k, n, temp, nums, ans);
        return ans;


    }
};