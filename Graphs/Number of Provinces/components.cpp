class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &visited, int &ans, int V){
        visited[V] = 1;
        for(int i=0;i<isConnected[V-1].size();i++){
            int ele = i+1;
            int connected = isConnected[V-1][i];
            if(visited[ele]==0 && ele!=V && connected==1){
                dfs(isConnected, visited, ans, ele);
            }

        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();
        vector<int> visited(V+1, 0);
        int ans = 0;
        for(int i=1;i<=V;i++){
            if(visited[i]==0){
                ans+=1;
                dfs(isConnected, visited, ans, i);
            }
            
        }
        
        return ans;
    }
};