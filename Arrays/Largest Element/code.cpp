// Brute Force Approach:
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        sort(arr.begin(), arr.end());
        return arr[n-1];
    }
};

// Iterative/Recursive Approach:
class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int ans = -1;
        for(int i=0;i<n;i++){
            if(arr[i]>ans){
                ans=arr[i];
            }
        }
        
        return ans;
    }
};