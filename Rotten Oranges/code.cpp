class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        int total = 0;
        int k = 0, cnt = 0, ans=0;
        queue<pair<int, int>> q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }

                if(grid[i][j]!=0){
                    total++;
                }
            }
        }

        if(total==0){
            return 0;
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty()){
            k = q.size();
            cnt+=k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy]==1){
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }

            }

            ans=ans+1;

        }

        if(total==cnt){
            return ans-1;
        }
        return -1;


    }
};