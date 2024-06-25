// Using queues

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<vector<int>>> graph(N);
        for(auto it : edges){
            int first = it[0];
            int second = it[1];
            int dist = it[2];
            vector<int> temp;
            temp.push_back(second);
            temp.push_back(dist);
            graph[first].push_back(temp);
        }
        
        
        vector<int> ans(N, 4000000);
        ans[0] = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(auto it : graph[temp]){
                int u = temp;
                int v = it[0];
                int edge = it[1];
                if(ans[v]>ans[u]+edge){
                    ans[v] = ans[u]+edge;
                    q.push(v);
                }
            }
        }
        
        
        
        for(int i = 0;i<N;i++){
            if(ans[i] == 4000000){
                ans[i] = -1;
            }
        }
        return ans;
    }
};

// Using toplogical sort

class Solution {
  public:
     void topologicalSort(int node, stack<int> &st, vector<vector<pair<int, int>>> &graph, vector<int> &vis){
         
         vis[node] = 1;
         for(auto &it : graph[node]){
             int second = it.first;
             if(!vis[second]){
                 topologicalSort(second, st, graph, vis);
             }
         }
         
         st.push(node);
         return;
         
     }

     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        int V = N;
        vector<int> ans(V, 1e9);
        ans[0] = 0;
        vector<vector<pair<int, int>>> graph(V);
        for(auto it : edges){
            int first = it[0];
            int second = it[1];
            int dist = it[2];
            graph[first].push_back({second, dist});
        }
        stack<int> st;
        vector<int> visited(V, 0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                topologicalSort(i, st, graph, visited);        
            }
        }
        
        while(!st.empty()){
            int first = st.top();
            st.pop();
            for(auto it : graph[first]){
                int second = it.first;
                int edge_distance = it.second;
                if(ans[second]>ans[first]+edge_distance){
                    ans[second] = ans[first]+edge_distance;
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(ans[i]==1e9){
                ans[i]=-1;
            }
        }
        return ans;
    }
};