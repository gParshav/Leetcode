class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int, int> mp;
        mp[0] = 0;
        int currSum = 0, ans = -1;
        for(int i=0;i<n;i++){
            currSum+=arr[i];
            if(mp.find(currSum)!=mp.end()){
                ans = max(ans, i-mp[currSum]+1);
            } 
            
            if(currSum!=0 && mp[currSum]==0){
                mp[currSum] = i+1;    
            }
            
        }
        
        if(ans==-1){
            return 0;
        }
        return ans;
    }
};