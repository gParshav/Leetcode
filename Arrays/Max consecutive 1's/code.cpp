class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int prev = 0, ans = 0;
        for(auto it : nums){
            if(it==1){
                prev++;
                if(prev>ans){
                    ans=prev;
                }
            }

            else{
                prev = 0;
            }
        }

        return ans;
    }
};