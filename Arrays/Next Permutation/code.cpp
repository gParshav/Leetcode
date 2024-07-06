// brute Force Approach(Gives TLE)
class Solution {
public:
    
    void makePermutations(vector<int>& nums, vector<int>& temp, set<vector<int>> &st, vector<int> &visited){

        if(temp.size()==nums.size()){
            st.insert(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                temp.push_back(nums[i]);
                visited[i] = 1;
                makePermutations(nums, temp, st, visited);
                temp.pop_back();
                visited[i] = 0;
            }
        }

    }

    void nextPermutation(vector<int>& nums) {
        
        vector<int> nums2 = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(n, 0);
        set<vector<int>> st;
        makePermutations(nums, temp, st, visited);
        int index=-1, j=0;
        for(auto it : st){
            ans.push_back(it);
        }
        for(auto it : ans){
            if(it==nums2){
                index = j;
                break;
            }
            j++;
        }


        if(index==ans.size()-1){
            nums = ans[0];
        }

        else{
            nums = ans[index+1];
        }

        return;
    }
};


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int pivotIndex = -1, n = nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                pivotIndex = i-1;
                break;
            }
        }

        if(pivotIndex==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        
        int lowestHigh = 101;
        int highIndex = -1;
        for(int i=pivotIndex;i<n;i++){
            if(nums[i]>nums[pivotIndex]){
                if(lowestHigh>nums[i]){
                    highIndex = i;
                }
                lowestHigh = min(lowestHigh, nums[i]);
            }
        }

        int temp = nums[pivotIndex];
        nums[pivotIndex] = nums[highIndex];
        nums[highIndex] = temp;
        sort(nums.begin()+pivotIndex+1, nums.end());

    }
};