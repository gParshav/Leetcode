// Brute Force

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        vector<int> ans;
        int n = nums.size(), cnt, ele;
        for(int i=0;i<n;i++){
            cnt = 0, ele = nums[i];
            if(ans.size()==2){
                return ans;
            }
            if(ans.size()==0 || ans[0]!=ele){
                for(int j=0;j<n;j++){
                    if(nums[j]==ele){
                        cnt++;
                    }
                }

                if(cnt>n/3){    
                    ans.push_back(ele);
                }
            }
            

        }

        return ans;

    }
};

// Better 1

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int ele = nums[0], n = nums.size(), cnt = 1;
        int k = n/3;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ele){
                cnt++;
                ele = nums[i];
            }

            else{
                if(cnt>k){
                    ans.push_back(ele);
                }
                ele = nums[i];
                cnt = 1;
            }
        }

        if(cnt>k){
            ans.push_back(ele);
        }

        return ans;

    }
};

// Better 2
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second>nums.size()/3){
                ans.push_back(it.first);
            }
        }
        return ans;

    }
};


// Optimal Solution
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        vector<int> ans;
        int n = nums.size(), cnt1=0, cnt2=0, ele1, ele2;
        for(int i=0;i<n;i++){

            if(cnt1==0 && nums[i]!=ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }

            else if(cnt2==0 && nums[i]!=ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }

            else if(nums[i]==ele1){
                cnt1++;
            }

            else if(nums[i]==ele2){
                cnt2++;
            }

            else{
                cnt1--;
                cnt2--;
            }

        }

        if(cnt1>0){
            int temp = 0;
            for(auto it : nums){
                if(it==ele1){
                    temp++;
                }
            }

            if(temp>n/3){
                ans.push_back(ele1);
            }
        }

        if(cnt2>0){
            int temp = 0;
            for(auto it : nums){
                if(it==ele2){
                    temp++;
                }
            }

            if(temp>n/3){
                ans.push_back(ele2);
            }
        }
            

        return ans;

    }
};