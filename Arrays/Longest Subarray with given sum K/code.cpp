// Brute Force:(For all numbers):

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int ans = 0;
        int sum;
        for(int i=0;i<N;i++){
            sum=0;
            for(int j=i;j<N;j++){
                sum+=A[j];
                if(sum==K){
                  ans = max(ans, j-i+1);  
                }
            }
        }
        
        return ans;
    } 
    

};


// Better for all numbers:
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int, int> mp;
        int currSum=0;
        int ans = 0;
        for(int i=0;i<N;i++){
            currSum+=A[i];
            if(currSum==K){
                ans=i+1;
            }
            
            else if(mp[currSum - K]!=0){
                ans=max(ans, i+1-mp[currSum - K]);    
            }
            
            if(mp[currSum]==0){
                mp[currSum] = i+1;    
            }
        }
        
        return ans;
    } 

};




// Optimal(For non-negative numbers):
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int left = 0, right = 0; // 2 pointers
        long long sum = A[0];
        int maxLen = 0;
        while (right < N) {
            // if sum > k, reduce the subarray from left
            // until sum becomes less or equal to k:
            while (left <= right && sum > K) {
                sum -= A[left];
                left++;
            }
    
            // if sum = k, update the maxLen i.e. answer:
            if (sum == K) {
                maxLen = max(maxLen, right - left + 1);
            }
    
            // Move forward thw right pointer:
            right++;
            if (right < N) sum += A[right];
        }
    
        return maxLen;
    } 

};