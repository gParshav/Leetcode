class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int x=i;x<=j;x++){
                    sum+=nums[x];
                }

                if(sum==k){
                    ans++;
                }

            }
        }

        return ans;

    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int ans = 0, n = nums.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                
                sum+=nums[j];
                if(sum==k){
                    ans++;
                }

            }
        }

        return ans;

    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size(), currSum = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            int req = currSum - k;
            if(mp.find(req)!=mp.end()){
                ans+=mp[req];
            }

            mp[currSum]++;


        }

        return ans;

    }
};