//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ans(V, 1000000);
        
        queue<int> q;
        ans[S] = 0;
        q.push(S);
        while(!q.empty()){
            int first = q.front();
            q.pop();
            int n = adj[first].size();
            for(int i=0;i<n;i++){
                int second = adj[first][i][0];
                int dist = adj[first][i][1];
                if(ans[second]>dist+ans[first]){
                    ans[second] = dist+ans[first];
                    q.push(second);
                }
 
            }
        }
        
        for(int i=0;i<V;i++){
            if(ans[i]==1000000){
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends