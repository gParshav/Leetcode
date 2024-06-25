class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if(x>=0 && x<rows && y>=0 && y<cols){
            return true;
        }

        return false;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || j==0 || i==rows-1 || j==cols-1){
                    if(grid[i][j]==1 && visited[i][j]==0){
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx, newy, grid) && grid[newx][newy]==1 && visited[newx][newy]==0){
                    visited[newx][newy] = 1;
                    q.push({newx, newy});
                }
            }
        }

        int ans = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j]==0 && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};