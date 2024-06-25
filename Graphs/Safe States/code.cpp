class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<vector<int>> reversedGraph(V);
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<V;i++){
            for(auto it : graph[i]){
                reversedGraph[it].push_back(i);
            }
        }

        vector<int> outDegree(V, 0);
        for(int i=0;i<V;i++){
            int temp = graph[i].size();
            outDegree[i] = temp;
        }
        
        for(int i=0;i<V;i++){
            if(outDegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x);
            for(auto it : reversedGraph[x]){
                outDegree[it]--;
                if(outDegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;

    }
};