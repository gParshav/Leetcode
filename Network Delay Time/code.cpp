class Solution {
public:

    void topologicalSort(int src, vector<int> &visited, stack<int> &st, vector<vector<pair<int, int>>> &graph){

        visited[src] = 1;

        for(auto it : graph[src]){
            int second = it.first;
            if(!visited[second]){
                topologicalSort(second, visited, st, graph);
            }
        }

        st.push(src);
        return;

    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int, int>>> graph(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int ans = -1;
        for(auto it : times){
            int first = it[0];
            int second = it[1];
            int dist = it[2];
            graph[first].push_back({second, dist});
        }

        vector<int> distance(n+1, 1e9);
        distance[k] = 0;
        while(!pq.empty()){
            int src = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it : graph[src]){
                int second = it.first;
                int edge_weight = it.second;
                if(distance[second]>dist+edge_weight){
                    distance[second] = dist+edge_weight;
                    pq.push({dist+edge_weight, second});
                }
            }
            
        }

        for(int i=1;i<=n;i++){

            if(distance[i]==1e9){
                return -1;
            }
            ans = max(ans, distance[i]);

            
        }



        return ans;
    }
};