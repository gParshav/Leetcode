class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/2;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i]){
                    cnt++;
                }
            }
            if(cnt>k){
                return nums[i];
            }
        }

        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int k = nums.size()/2;
        int ele = nums[k];
        int temp = 0;
        for(auto it : nums){
            if(it==ele){
                temp++;
            }
        }

        if(temp>k){
            return ele;
        }

        return -1;

    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        int n = nums.size();
        int k = n/2;
        for(auto it : mp){
            if(it.second>k){
                return it.first;
            }
        }

        return -1;

    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/2;
        int ele, cnt = 0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele = nums[i];
                cnt = 1;
            }

            else if(nums[i]==ele){
                cnt++;
            }

            else{
                cnt--;
            }

            
        }

        int temp;
        for(int i=0;i<n;i++){
            if(nums[i]==ele){
                temp++;
            }
        }

        if(temp>k){
            return ele;
        }

        return -1;
    }
};