class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = -1;
        int n = nums.size();
        for(int j=0;j<n;j++){
            if(nums[j]==0){
                continue;
            }

            i++;
            nums[i] = nums[j];
        }

        if(i==-1){
            return;
        }

        for(int k=i+1;k<n;k++){
            nums[k] = 0;
        }

    }
};