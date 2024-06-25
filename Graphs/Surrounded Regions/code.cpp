// Method 1 - BFS

class Solution {
public:
    bool isValid(int x, int y, int rows, int columns){
        if(x>=0 && x<rows && y>=0 && y<columns){
            return true;
        }

        return false;
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> temp(rows, vector<int>(columns, -1));
        vector<vector<int>> visited(rows, vector<int>(columns, -1));
        queue<pair<int, int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i==0 || j==0 || i==rows-1 || j==columns-1){
                    if(board[i][j]=='O'){
                        q.push({i, j});
                        temp[i][j] = 1;
                        visited[i][j] = 1;
                    }
                }

                else{
                    continue;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            visited[x][y] = 1;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(isValid(newx, newy, rows, columns) && board[newx][newy]=='O' && visited[newx][newy]==-1){
                    q.push({newx, newy});
                    temp[newx][newy] = 1;
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(temp[i][j]==1){
                    board[i][j] = 'O';
                }

                else{
                    board[i][j] = 'X';
                }
            }
        }

        return ;

    }
};


// Method 2 - DFS

class Solution {
public:
    bool isValid(int x, int y, int rows, int columns){
        if(x>=0 && x<rows && y>=0 && y<columns){
            return true;
        }

        return false;
    }

    void dfs(int x, int y, int rows, int columns, vector<vector<int>> &visited, vector<vector<int>> &ans, 
    vector<vector<char>>& board){

        visited[x][y] = 1;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isValid(newx, newy, rows, columns) && visited[newx][newy] == -1 && board[newx][newy]=='O'){
                ans[newx][newy] = 1;
                dfs(newx, newy, rows, columns, visited, ans, board);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> visited(rows, vector<int>(columns, -1));
        vector<vector<int>> ans(rows, vector<int>(columns, -1));
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(i==0 || j==0 || i==rows-1 || j==columns-1){
                    if(visited[i][j]==-1 && board[i][j]=='O'){
                        ans[i][j] = 1;
                        dfs(i, j, rows, columns, visited, ans, board);
                }
                }
                
            }
        }


        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(ans[i][j]==-1){
                    board[i][j] = 'X';
                }

                else{
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};