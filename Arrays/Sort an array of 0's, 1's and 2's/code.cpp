class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return;
    }
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num0 = 0, num1 = 0, num2 = 0;
        for(auto it : nums){
            if(it==0){
                num0++;
            }

            else if(it==1){
                num1++;
            }

            else{
                num2++;
            }
        }

        int j = 0;
        for(int i=0;i<num0;i++){
            nums[j] = 0;
            j++;
        }

        for(int i=0;i<num1;i++){
            nums[j] = 1;
            j++;
        }

        for(int i=0;i<num2;i++){
            nums[j] = 2;
            j++;
        }

        return;
    }

    
};


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            if(nums[mid]==0){
                nums[mid] = 1;
                nums[low] = 0;
                low++;
                mid++;
            }

            else if(nums[mid]==1){
                mid++;
            }

            else{
                nums[mid] = nums[high];
                nums[high] = 2;
                high--;
            }
        }
    }
};