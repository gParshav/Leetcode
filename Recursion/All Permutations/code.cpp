class Solution {
public:
    void makePermutations(vector<int>& nums, vector<int>& temp, vector<vector<int>> &ans, vector<int> &visited){

        if(temp.size()==nums.size()){
            ans.push_back(temp);
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                temp.push_back(nums[i]);
                visited[i] = 1;
                makePermutations(nums, temp, ans, visited);
                temp.pop_back();
                visited[i] = 0;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> visited(n, 0);
        makePermutations(nums, temp, ans, visited);
        return ans;

    }
};



