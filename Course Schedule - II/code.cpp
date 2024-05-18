class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        vector<int> ans;
        queue<int> q;
        vector<int> indegree(V, 0);
        vector<vector<int>> graph(V);
        for(auto it : prerequisites){
            int x = it[0];
            int y = it[1];
            graph[y].push_back(x);
        }

        for(int i=0;i<V;i++){
            for(auto it : graph[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it : graph[temp]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }

        }

        if(ans.size()!=V){
            return {};
        }
        
        return ans;

    }
};