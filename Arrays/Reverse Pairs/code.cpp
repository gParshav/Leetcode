class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long t1 = nums[i];
                long long t2 = nums[j];
                t2 = 2*t2; 
                if(t1>t2){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};