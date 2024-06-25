class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int V = numCourses;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> ans;
        for(auto it : prerequisites){
            int first = it[0];
            int second = it[1];
            graph[first].push_back(second);

        }

        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
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

        if(ans.size()==V){
            return true;
        }

        return false;


    }
};