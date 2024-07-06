class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> pos;
        vector<int> neg;
        vector<int> ans;
        int i = 0, j = 0;
        
        for(auto it : nums){
            if(it>0){
                pos.push_back(it);
            }

            else{
                neg.push_back(it);
            }
        }
        int n1 = pos.size(), n2 = neg.size();
        
        while(i<n1 && j<n2){
            ans.push_back(pos[i]);
            ans.push_back(neg[j]);
            i++;
            j++;
        }

        while(i<n1){
            ans.push_back(nums[i]);
            i++;
        }

        while(j<n2){
            ans.push_back(nums[j]);
            j++;
        }

        return ans;

    }
};


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0, j = 1;
        for(auto it : nums){
            if(it>0){
                ans[i] = it;
                i+=2;
            }

            else{
                ans[j] = it;
                j+=2;
            }
        }
        return ans;

    }
};