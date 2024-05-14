class Solution {
public:
    bool dfs(int src, vector<vector<int>>& graph, vector<int> &colors, int col){

        if(colors[src]==!col){
            return false;
        }

        for(auto it : graph[src]){
            if(colors[it]==-1){
                if(dfs(it, graph, colors, !col) == false){
                    return false;
                }
                
            }

            else if(colors[it]==col){
                return false;
            }
        }

        return true;

    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> colors(n+1, -1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                if(dfs(i, graph, colors, 0) == false){
                    return false;
                }

            }
        }

        return true;

        
    }
};