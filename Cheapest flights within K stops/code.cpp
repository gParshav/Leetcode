class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<int>> ans(n, vector<int>(k+1, 1e9));
        vector<vector<pair<int, int>>> graph(n);
        for(auto it : flights){
            int first = it[0];
            int second = it[1];
            int price = it[2];
            graph[first].push_back({second, price});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for(int i=0;i<=k;i++){
            ans[src][i] = 0;
        }

        // pq.push({curr_price, {node, stops}})
        pq.push({0, {src, 0}});
        while(!pq.empty()){
            int curr_price = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            
            pq.pop();
            for(auto it : graph[node]){
                int second = it.first;
                
                int edge_weight = it.second;
                int new_stops = stops+1;
                if(second == dst){
                    new_stops = stops;
                }
                if(new_stops<=k){
                    if(ans[second][new_stops]>ans[node][stops]+edge_weight){
                        ans[second][new_stops] = ans[node][stops]+edge_weight;
                        pq.push({ans[node][stops]+edge_weight, {second, new_stops}});
                    }
                }

            }

        }
        
        int cheapestPrice = 1e9;
        for(int i=0;i<=k;i++){
            cheapestPrice = min(cheapestPrice, ans[dst][i]);
        }   

        if(cheapestPrice == 1e9){
            return -1;
        }

        return cheapestPrice;

    }
};