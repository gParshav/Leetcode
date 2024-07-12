int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int target = B, ans = 0, temp = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            temp = 0;
            for(int k=i;k<=j;k++){
                temp^=A[k];
            }
            
            if(temp==B){
                ans++;
            }
        }
    }
    
    return ans; 
} 


int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int temp, ans = 0;
    for(int i=0;i<n;i++){
        temp = 0;
        for(int j=i;j<n;j++){
            temp=temp^A[j];
            if(temp==B){
                ans++;
            }
        }
    }
    
    return ans;
    
}


int Solution::solve(vector<int> &A, int B) {
    
    int n = A.size();
    int target = B, ans = 0, prevXOR, currXOR = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for(int i=0;i<n;i++){
        currXOR = currXOR^A[i];
        prevXOR = currXOR^target;
        ans+=mp[prevXOR];
        mp[currXOR]++; 
        

        
    }
    
    return ans;
    
}
