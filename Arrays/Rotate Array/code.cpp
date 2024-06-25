// Brute Force
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    
        int n = nums.size();
        k = k%n;
        vector<int> temp;
        // Push rightmost in temp
        for(int i=n-k;i<n;i++){
            temp.push_back(nums[i]);
        }

        // Sort rightmost part of nums
        for(int i=n-1;i>=k;i--){
            nums[i] = nums[i-k];
        }

        // Sort leftmost part of nums
        for(int i=0;i<k;i++){
            nums[i] = temp[i];
        }

        return;
    }
};


// Slightly better and cleaner
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;
        vector<int> temp;
        for(auto it : nums){
            temp.push_back(it);
        }

        for(int i=0;i<n;i++){
            nums[i] = temp[(n+i-k) % n];
        }

    }
};

// Optimal
class Solution {
public:
    void freverse(int start, int end, vector<int>& nums){

        while(start<=end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        k = k%n;
        freverse(0, n-1, nums);
        freverse(0, k-1, nums);
        freverse(k, n-1, nums);

    }
};