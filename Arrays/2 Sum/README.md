Again this problem also follows the clear pattern of solving array problems which is, for loops(brute force), hashing and 2 pointers.
Only factor being that 2 pointers approach is not faster than the hashing method.

Brute Force:
Iterate through all the pair using 2 for loops
Time Complexity - O(N^2)
Space Complexity - O(1)

Better:
Use a hash map for storing the indexes for all the elements, then iterate through the array once and at all elements find if the remaining element is there in the hash map.(Gets slightly confusing with non-unique elements). Check the note below.
Time Complexity - O(N)
Space Complexity - O(N)

Optimal:(Not really optimal but whatever)
Just a YES or NO - 
    - Sort the array and do the 2 pointer thing.
Need to return indices - 
    - Since you are sorting the array, you need to preserve the old indices, or else find them from the old array.
    Using a new data structure with the element and the indices is interesting as you get to learn about customizing the sort() function.
Time Complexity - O(N)+O(N*logN)
Space Complexity - O(N)


Note - 
<!-- This will work -->
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


<!-- This wont work -->
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]] = i;
        }
        
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
        }
        return { -1, -1};
    }
};


Why will it not work?
It will actually. I just got confused.