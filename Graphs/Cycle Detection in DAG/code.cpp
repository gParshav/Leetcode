//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src, vector<int> &visited, vector<int> &pathVisited, vector<int> adj[]){
        
        visited[src] = 1;
        pathVisited[src] = 1;
        for(auto it : adj[src]){
            if(visited[it]==1 && pathVisited[it]){
                return true;
            }
            
            else if(visited[it]==0 && dfs(it, visited, pathVisited, adj) == true){
                return true;
            }
            
        }
        
        pathVisited[src] = 0;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends