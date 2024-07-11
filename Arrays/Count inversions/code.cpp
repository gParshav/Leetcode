class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long int start, long long int mid, long long int end){
        
        long long int cnt = 0;
        vector<long long int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            
            else{
                cnt+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long int i=start;i<=end;i++){
            arr[i] = temp[i-start];
        }
        
        return cnt;
    }
    
    
    long long int mergeSort(long long arr[], long long int start, long long int end){
       
        long long int cnt = 0;
        if(start>=end){
            return 0;
        }
        long long int mid = (start+end)/2;
        cnt+=mergeSort(arr, start, mid);
        cnt+=mergeSort(arr, mid+1, end);
        cnt+=merge(arr, start, mid, end);
        return cnt;
        
    }
    
    
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        
        return mergeSort(arr, 0, n-1);
    }
};


class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int cnt=0;
    void merge(long long arr[], long long int start, long long int mid, long long int end){
        

        vector<long long int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            
            else{
                cnt+=mid-left+1;
                temp.push_back(arr[right]);
                right++;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        
        for(long long int i=start;i<=end;i++){
            arr[i] = temp[i-start];
        }
        
        return;
    }
    
    
    void mergeSort(long long arr[], long long int start, long long int end){
       

        if(start>=end){
            return;
        }
        long long int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
        return;
        
    }
    
    
    long long int inversionCount(long long arr[], int n) {
        // Your Code Here
        
        mergeSort(arr, 0, n-1);
        return cnt;
    }
};