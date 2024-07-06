// Brute Force Solution
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        int i, j;
        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(arr[j]>arr[i]){
                    break;
                }
            }
            
            if(j==n){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

// Better Solution
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        vector<int> tempArr(n, 0);
        int ele = -1;
        for(int i=n-1;i>=0;i--){
            ele = max(ele, arr[i]);
            tempArr[i] = ele;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]==tempArr[i]){
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

// Optimal Solution
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        int temp = -1;
        for(int i = n-1;i>=0;i--){
            temp = max(temp, arr[i]);
            if(arr[i]==temp){
                ans.push_back(arr[i]);
            }
        }
        
        int i = 0, j = ans.size()-1;
        while(i<=j){
            int temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
            i++;
            j--;
        }
        return ans;
    }
};