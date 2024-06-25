class Solution {
public:
    void f(int i, int sum, int n, int target, vector<int> temp,  vector<int> &candidates, set<vector<int>> &setOfVectors){
        
        if(sum>target){
            return;
        }

        if(sum==target){
            setOfVectors.insert(temp);
            return;
        }

        if(i>=n){
            return;
        }

        
        int sum1 = sum+candidates[i]; 
        vector<int> temp2 = temp;
        temp2.push_back(candidates[i]);
        f(i, sum1, n, target, temp2, candidates, setOfVectors);
        f(i+1, sum1, n, target, temp2, candidates, setOfVectors);
        f(i+1, sum, n, target, temp, candidates, setOfVectors);

        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> setOfVectors;
        int i, sum = 0;
        int n = candidates.size();
        f(0, sum, n, target, temp, candidates, setOfVectors);
        while (!setOfVectors.empty()) {
            auto it = setOfVectors.begin();
            vector<int> vec = *it;
            setOfVectors.erase(it);
            ans.push_back(vec);
        }

        return ans;
    }
};