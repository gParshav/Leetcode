class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        for(auto it : st){
            ans.push_back(it);
            st.erase(it);
        }

        return ans;


    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
            unordered_map<int, int> mp;
            for(int j=i+1;j<n;j++){
                int req = -1*(nums[i]+nums[j]);
                if(mp.find(req)!=mp.end() && mp[req]!=i && mp[req]!=j){
                    vector<int> temp = {nums[i], nums[j], req};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                mp[nums[j]] = j;
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;


    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                   ans.push_back({nums[i],nums[j], nums[k]});
                   j++;
                   k--; 
                   while(j<n && nums[j]==nums[j-1]){
                        j++;
                   }

                   while(k>=0 && nums[k]==nums[k+1]){
                        k--;
                   }

                }

                else if(sum>0){
                    k--;
                }

                else if(sum<0){
                    j++;
                }
            }
        }

        return ans;


    }
};