// Brute Force
// Use sets
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int> st;
        for(auto it : nums){
            st.insert(it);
        }

        int ans = 0;
        for(auto it : st){
            st.erase(it);
            nums[ans] = it;
            ans++;
        }

        return ans;

    }
};

// Optimal Solution
// 2 Pointer Approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int prevIndex = 1; 
        if(n==1){
            return prevIndex;
        }

        int temp = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            nums[prevIndex++] = nums[i];
        }

        return prevIndex;

    }
};