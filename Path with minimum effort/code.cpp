class Solution {
public:
    bool isValid(int rows, int cols, int x, int y){

        if(x>=0 && x<rows && y>=0 && y<cols){
            return true;
        }

        return false;

    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        ans[0][0] = 0;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int curr_max = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(rows, cols, newx, newy)){
                    int diff = abs(heights[newx][newy] - heights[x][y]);
                    int temp = max(curr_max, diff);
                    if(ans[newx][newy] > temp){
                        ans[newx][newy] = temp;
                        pq.push({temp, {newx, newy}});
                    }
                }
                
            }

        }

        if(ans[rows-1][cols-1]==1e9){
            return -1;
        }
        return ans[rows-1][cols-1];


    }
};