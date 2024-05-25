//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<vector<int>> graph(N);
        for(auto it : edges){
            int first = it[0];
            int second = it[1];
            graph[first].push_back(second);
            graph[second].push_back(first);
        }
        
        vector<int> ans(N, 1000000);
        ans[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : graph[temp]){
                int u = temp;
                int v = it;
                int dist = ans[u];
                if(ans[v]>ans[u]+1){
                    ans[v] = ans[u]+1;
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(ans[i] == 1000000){
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends