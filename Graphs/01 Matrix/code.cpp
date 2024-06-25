// Solution 1

class Solution {
public:
    bool isValid(int x, int y, int row, int col){
        if(x>=0 && y>=0 && x<row && y<col){
            return true;
        }

        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> ans(row, vector<int>(col, -1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx, newy, row, col) && visited[newx][newy]!=1){
                    visited[newx][newy] = 1;
                    q.push({{newx, newy}, dist+1});
                    ans[newx][newy] = dist+1;
                }
            }
        }

        return ans;


        
    }
};

// Solution 2
// Just slightly better

class Solution {
public:
    bool isValid(int x, int y, int row, int col){
        if(x>=0 && y>=0 && x<row && y<col){
            return true;
        }

        return false;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        queue<pair<int, int>> q;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        vector<vector<int>> ans(row, vector<int>(col, -1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            int dist = ans[x][y];
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx, newy, row, col) && ans[newx][newy]==-1){
                    q.push({newx, newy});
                    ans[newx][newy] = dist+1;
                }
            }
        }

        return ans;


        
    }
};