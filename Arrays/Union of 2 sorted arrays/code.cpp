// Brute Force

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            st.insert(arr2[i]);
        }
        
        for(auto it : st){
            ans.push_back(it);
            st.erase(it);
        }
        
        return ans;
}


// Optimal
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        int i=0, j=0;
        while(i<n && j<m){
            
            if(i>0 && arr1[i]==arr1[i-1]){
                i++;
                continue;
            }
            
            if(j>0 && arr2[j]==arr2[j-1]){
                j++;
                continue;
            }
            
            if(arr1[i]>arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }
            
            else if(arr1[i]<arr2[j]){
                ans.push_back(arr1[i]);
                i++;
            }
            
            else{
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            
        }
        
        
        
        while(i<n){
            if(i>0 && arr1[i]==arr1[i-1]){
                i++;
                continue;
            }
            ans.push_back(arr1[i]);
            i++;
        }
        
        while(j<m){
            if(j>0 && arr2[j]==arr2[j-1]){
                j++;
                continue;
            }
            ans.push_back(arr2[j]);
            j++;
        }
        
        return ans;
    }
};