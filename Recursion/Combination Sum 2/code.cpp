// Brute Force
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
        f(i+1, sum1, n, target, temp2, candidates, setOfVectors);
        f(i+1, sum, n, target, temp, candidates, setOfVectors);

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<vector<int>> setOfVectors;
        sort(candidates.begin(), candidates.end());
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


// Better Approach/ Optimized
class Solution {
public:

    void f(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &temp){
        

        if(target==0){
            ans.push_back(temp);
            return;
        }

        for(int i = ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }

            if(arr[i]>target){
                break;
            }

            temp.push_back(arr[i]);
            f(i+1, target-arr[i], arr, ans, temp);
            temp.pop_back();
        }

    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        f(0, target, candidates, ans, temp);
        return ans;
    }
};
