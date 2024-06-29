// Brute Force Approach:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i, j};
                }
            }
        }

        return {};
    }
       
};


// Better Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};
    }
};

// Better Approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                if(mpp[moreNeeded]!=i){
                    return {mpp[moreNeeded], i};
                }
                
            }
        }
        return { -1, -1};
    }
};


// Optimal Approach 1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int i=0, j=n-1;
        while(i<j){

            if(nums2[i]+nums2[j]==target){
                return "YES";
            }

            else if(nums2[i]+nums2[j]>target){
                j--;
            }

            else{
                i++;
            }
        }

        return "NO";
    }
       
};




// Optimal Approach2(If we need to return the indexes of the elements)
class Solution {
public:
    vector<int> findIndex(vector<int> &nums, int n1, int n2){
       
        int i, j;
        for(int k=0;k<nums.size();k++){
            if(nums[k]==n1){
                i = k;
                break;
            }
        }
        for(int k=0;k<nums.size();k++){
            if(k==i){
                continue;
            }
            if(nums[k]==n2){
                j = k;
                break;
            }
        }
        return {i, j};
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        int i=0, j=n-1;
        while(i<j){

            if(nums2[i]+nums2[j]==target){
                return findIndex(nums, nums2[i], nums2[j]);
            }

            else if(nums2[i]+nums2[j]>target){
                j--;
            }

            else{
                i++;
            }
        }

        return {};
    }
       
};

// Optimal Approach2(If we need to return the indexes of the elements)
class Solution {
public:
    // Comparator struct
    struct CompareFirst {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first < b.first;
        }
    };

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int, int>> nums2;
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums2.push_back({nums[i], i});
        }

        sort(nums2.begin(), nums2.end(), CompareFirst());

        int i=0, j=n-1;
        while(i<j){
            int ele1 = nums2[i].first;
            int idx1 = nums2[i].second;
            int ele2 = nums2[j].first;
            int idx2 = nums2[j].second;
            if(ele1+ele2==target){
                return {idx1, idx2};
            }

            else if(ele1+ele2>target){
                j--;
            }

            else{
                i++;
            }
        }

        return {};

    }
};