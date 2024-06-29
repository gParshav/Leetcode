// Brute Force Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second==1){
                return it.first;
            }
        }

        return -1;
    }
};


// Optimal Solution
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto it : nums){
            ans = ans^it;
        }
        return ans;
    }
};
