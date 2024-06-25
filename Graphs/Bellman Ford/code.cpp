vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int first = it[0];
                int second = it[1];
                int wt = it[2];
                if(distance[first]!=1e8 && distance[second]>distance[first]+wt){
                    distance[second] = distance[first]+wt;
                }
            }
        }
        
        for(auto it : edges){
                int first = it[0];
                int second = it[1];
                int wt = it[2];
                if(distance[first]!=1e8 && distance[second]>distance[first]+wt){
                    // distance[second] = distance[first]+wt;
                    vector<int> ans;
                    ans.push_back(-1);
                    return ans;
                }
            }
        return distance;
        
    }