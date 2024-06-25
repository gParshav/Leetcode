// Solution 1(Doesn't work, gives a TLE): (20/55 test cases passed)

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<long long int, long long int>>> graph(n);
        for(auto it : roads){
            long long int first = it[0];
            long long int second = it[1];
            long long int weight = it[2];
            graph[first].push_back({second, weight});
            graph[second].push_back({first, weight});
        }

        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        vector<long long int> distance(n, 1e9);
        distance[0] = 0;
        pq.push({0, 0});
        unordered_map<long long int, long long int> mp;
        while(!pq.empty()){
            long long int src = pq.top().second;
            long long int curr_dist = pq.top().first;
            pq.pop();
            if(src == n-1){
                mp[curr_dist]++;
            }

            for(auto it : graph[src]){
                int second = it.first;
                int edge_weight = it.second;
                if(distance[second] >= curr_dist+edge_weight){
                    distance[second] = curr_dist+edge_weight;
                    pq.push({curr_dist+edge_weight, second});
                }
            }

        }
        
        const long long MOD = 1000000007;
        return mp[distance[n-1]]%MOD;
        
    }
};


Solution 2(Works): (55/55 test cases passed)

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<long long int, long long int>>> graph(n);
        vector<long long int> ways(n, 0);
        const long long MOD = 1000000007;
        ways[0] = 1;
        for(auto it : roads){
            long long int first = it[0];
            long long int second = it[1];
            long long int weight = it[2];
            graph[first].push_back({second, weight});
            graph[second].push_back({first, weight});
        }

        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
        vector<long long int> distance(n, LLONG_MAX);
        distance[0] = 0;
        pq.push({0, 0});
        unordered_map<long long int, long long int> mp;
        while(!pq.empty()){
            long long int src = pq.top().second;
            long long int curr_dist = pq.top().first;
            pq.pop();
            

            for(auto it : graph[src]){
                int second = it.first;
                int edge_weight = it.second;
                if(distance[second] > curr_dist+edge_weight){
                    distance[second] = curr_dist+edge_weight;
                    pq.push({curr_dist+edge_weight, second});
                    // ways[second] = 1;
                    ways[second] = ways[src];
                }

                else if(distance[second] == curr_dist+edge_weight){
                    ways[second] = (ways[second]+ways[src])%MOD;
                }
                    
                
            }

        }
        
        
        // return mp[distance[n-1]]%MOD;

        return ways[n-1];
        
    }
};