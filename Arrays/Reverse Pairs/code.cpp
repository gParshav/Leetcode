class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int ans=0, n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long t1 = nums[i];
                long long t2 = nums[j];
                t2 = 2*t2; 
                if(t1>t2){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


class Solution {
public:
    int merge(vector<int>& nums, int start, int mid, int end){

        int left = start;
        int right = mid+1;
        vector<int> temp;
        int cnt = 0;
        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }

            else{
                temp.push_back(nums[right]);
                right++;
            }

        }

        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right<=end){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=start;i<=end;i++){
            nums[i] = temp[i-start];
        }

        temp.clear();
        return cnt;

    }

    int countPairs(vector<int>& arr, int start, int mid, int end){

        int left = start;
        int right = mid+1;
        int cnt = 0;
        while(left<=mid && right<=end){
            long long t1 = arr[left];
            long long t2 = arr[right];
            t2 = 2*t2;
            if(t1>t2){
                cnt+=mid-left+1;
                right++;
            }

            else{
                left++;
            }
        }
        return cnt;

    }


    int mergeSort(vector<int>& nums, int start, int end){
        int cnt = 0;
        if(start>=end){
            return cnt;
        }
        int mid = (start+end)/2;
        cnt+=mergeSort(nums, start, mid);
        cnt+=mergeSort(nums, mid+1, end);
        cnt+=countPairs(nums, start, mid, end);
        cnt+=merge(nums, start, mid, end);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();
        return mergeSort(nums, 0, n-1);

    }
};