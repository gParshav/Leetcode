class Solution {
public:
    int findMaxMoney(int i, int start, int end, vector<int>& nums){

        if(i==start){
            return nums[start];
        }

        if(i<start){
            return 0;
        }

        int e1 = INT_MIN;
        if(i==end){
            e1 = findMaxMoney(i-2, start+1, end, nums) + nums[i];
        }
        else{
            e1 = findMaxMoney(i-2, start, end, nums) + nums[i];
        }
        int e2 = findMaxMoney(i-1, start, end, nums);
        return max(e1, e2);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        return findMaxMoney(n-1, start, end, nums);
    }
};




class Solution {
public:
    int findMaxMoney(vector<int>& maxMoney, int i, int start, int end, vector<int>& nums){

        if(i==start){
            return nums[start];
        }

        if(i<start){
            return 0;
        }

        if(maxMoney[i]!=-1){
            return maxMoney[i];
        }

        int e1 = findMaxMoney(maxMoney, i-2, start, end, nums) + nums[i];
        int e2 = findMaxMoney(maxMoney, i-1, start, end, nums);
        return maxMoney[i]=max(e1, e2);

    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0], nums[1]);
        }
        int start = 0, end = n-2;
        vector<int> maxMoney(n, -1);
        vector<int> maxMoney2(n, -1);
        int ans1 = findMaxMoney(maxMoney, n-2, 0, n-2, nums);
        int ans2 = findMaxMoney(maxMoney2, n-1, 1, n-1, nums);
        return max(ans1, ans2);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0], nums[1]);
        }
        int start = 0, end = n-2;
        vector<int> maxMoney(n, -1);
        maxMoney[start] = nums[start];
        for(int i=start+1;i<=end;i++){
            int e1 = nums[i];
            if(i>start+1){
                e1 = maxMoney[i-2] + nums[i];
            }
            int e2 = maxMoney[i-1];
            maxMoney[i]=max(e1, e2);
        }
        int ans1 = maxMoney[n-2];
        start = 1, end = n-1;
        vector<int> maxMoney2(n, -1);
        maxMoney2[start] = nums[start];
        for(int i=start+1;i<=end;i++){
            int e1 = nums[i];
            if(i>start+1){
                e1 = maxMoney2[i-2] + nums[i];
            }
            int e2 = maxMoney2[i-1];
            maxMoney2[i]=max(e1, e2);
        }
        int ans2 = maxMoney2[n-1];
        return max(ans1, ans2);
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }

        if(n==2){
            return max(nums[0], nums[1]);
        }
        int start = 0, end = n-2;
        int prev = nums[start], prev2 = -1;
        for(int i=start+1;i<=end;i++){
            int e1 = nums[i];
            if(i>start+1){
                e1 = prev2 + nums[i];
            }
            int e2 = prev;
            prev2=prev;
            prev=max(e1, e2);
        }
        int ans1 = prev;
        start = 1, end = n-1;
        prev = nums[start], prev2 = -1;
        for(int i=start+1;i<=end;i++){
            int e1 = nums[i];
            if(i>start+1){
                e1 = prev2 + nums[i];
            }
            int e2 = prev;
            prev2 = prev;
            prev=max(e1, e2);
        }
        int ans2 = prev;
        return max(ans1, ans2);
    }
};