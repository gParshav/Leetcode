class Solution {
public:
    void f(int i, int n, vector<vector<int>> &ans, vector<int>& nums, vector<int> temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        f(i+1, n, ans, nums, temp);
        temp.pop_back();
        f(i+1, n, ans, nums, temp);


    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        f(0, n, ans, nums, temp);
        return ans;
    }
};


// Solution 2

class Solution {
public:
    void f(int i, int n, vector<vector<int>> &ans, vector<int>& nums, vector<int> temp){
        if(i>=n){
            ans.push_back(temp);
            return;
        }

        vector<int> temp2 = temp;
        temp2.push_back(nums[i]);
        f(i+1, n, ans, nums, temp2);
        f(i+1, n, ans, nums, temp);


    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp;
        f(0, n, ans, nums, temp);
        return ans;
    }
};