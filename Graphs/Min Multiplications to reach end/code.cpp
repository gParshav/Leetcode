//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        vector<int> dist(100000, 1e9);
        int MOD = 100000;
        int ans = 1e9;
        dist[start] = 0;
        while(!pq.empty()){
            int steps = pq.top().first;
            int num = pq.top().second;
            pq.pop();
            for(int i=0;i<arr.size();i++){
                int k = (num*arr[i])%MOD;
                if(steps+1<dist[k]){
                   dist[k] = steps+1;
                   pq.push({steps+1, k});
                }
            
            }    
            
            
        }
        if(dist[end]==1e9){
            return -1;
        }
        return dist[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends