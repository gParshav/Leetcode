class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int i = l;
         int j = m+1;
         vector<int> temp;
         while(i<=m && j<=r){
             
             if(arr[i]<=arr[j]){
                 temp.push_back(arr[i]);
                 i++;
             }
             
             else{
                 temp.push_back(arr[j]);
                 j++;
             }
             
         }
         
         while(i<=m){
            temp.push_back(arr[i]);
            i++;
         }
         
         while(j<=r){
            temp.push_back(arr[j]);
            j++;
         }
         
         
        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
};