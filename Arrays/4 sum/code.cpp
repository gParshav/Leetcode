class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
        set<vector<int>> st;
        int n = nums.size();
        for(int a=0;a<n;a++){
            for(int b=a+1;b<n;b++){
                for(int c=b+1;c<n;c++){
                    for(int d=c+1;d<n;d++){
                        long long sum = nums[a]+nums[b];
                        sum+=nums[c]+nums[d];
                        if(sum==target){
                            vector<int> temp = {nums[a],nums[b],nums[c],nums[d]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>> st;
        int n = nums.size();
        for(int a=0;a<n;a++){
            for(int b=a+1;b<n;b++){
                set<long long> mp;
                for(int c=b+1;c<n;c++){
                    long long sum = nums[a]+nums[b];
                    sum+=nums[c];
                    long long req = target - sum;
                    if(mp.find(req)!=mp.end()){
                        vector<int> temp = {nums[a],nums[b],nums[c],(int)req};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    mp.insert(nums[c]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int a=0;a<n;a++){
            if(a!=0 && nums[a]==nums[a-1]){
                continue;
            }
            for(int b=a+1;b<n;b++){
                if(b!=a+1 && nums[b]==nums[b-1]){
                    continue;
                }
                int c = b+1;
                int d = n-1;
                while(c<d){
                    long long sum = nums[a]+nums[b];
                    sum+=nums[c];
                    sum+=nums[d];
                    if(sum==target){
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;
                        while(c<n && nums[c]==nums[c-1]){
                            c++;
                        }

                        while(d>0 && nums[d]==nums[d+1]){
                            d--;
                        }
                    }

                    else if(sum>target){
                        d--;    
                    }

                    else{
                        c++;
                    }
                }
            }
        }
        

        
        return ans;
    }
};