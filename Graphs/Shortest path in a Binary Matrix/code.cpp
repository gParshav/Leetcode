class Solution {
public:
    bool isValid(int n, int x, int y){
        if(x>=0 && x<n && y>=0 && y<n){
            return true;
        }

        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        queue<pair<int, int>> q;
        int n = grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        q.push({0, 0});
        dist[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
            int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
            for(int i=0;i<8;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(n, newx, newy) && dist[newx][newy]>dist[x][y]+1 && grid[newx][newy] == 0){
                    dist[newx][newy] = dist[x][y]+1;
                    q.push({newx, newy});
                }
            }
        }

        if(dist[n-1][n-1] == 1e9){
            return -1;
        }
        return dist[n-1][n-1];
    }
};