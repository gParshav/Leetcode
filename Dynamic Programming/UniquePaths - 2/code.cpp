class Solution {
public:
    bool isValid(int m, int n, int x, int y){
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }

        return false;
    }

    int countPaths(int m, int n, int x, int y, vector<vector<int>>& obstacleGrid){

        if(x==0 && y==0){
            if(obstacleGrid[x][y]==1){
                return 0;
            }
            return 1;
        }

        if(!isValid(m, n, x, y) || obstacleGrid[x][y]==1){
            return 0;
        }

        return countPaths(m, n, x, y-1, obstacleGrid) + countPaths(m, n, x-1, y, obstacleGrid);

    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return countPaths(m, n, m-1, n-1, obstacleGrid);
        
    }
};


class Solution {
public:
    bool isValid(int m, int n, int x, int y){
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }

        return false;
    }

    int countPaths(int m, int n, int x, int y, vector<vector<int>>& paths, vector<vector<int>>& obstacleGrid){

        if(x==0 && y==0){
            if(obstacleGrid[x][y]==1){
                return paths[x][y] = 0;
            }
            return paths[x][y] = 1;
        }

        if(!isValid(m, n, x, y) || obstacleGrid[x][y]==1){
            return 0;
        }

        if(paths[x][y]!=-1){
            return paths[x][y];
        }
        return paths[x][y] = countPaths(m, n, x, y-1, paths, obstacleGrid) + countPaths(m, n, x-1, y, paths, obstacleGrid);

    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, -1));
        return countPaths(m, n, m-1, n-1, paths, obstacleGrid);
        
    }
};


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> paths(m, vector<int>(n, -1));
        if(obstacleGrid[0][0]==1){
                paths[0][0] = 0;
        }

        else{
            paths[0][0] = 1;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }

                if(obstacleGrid[i][j]==1){
                    paths[i][j] = 0;
                    continue;
                }

                int e1 = 0;
                if(j>0){
                    e1 = paths[i][j-1];
                }

                int e2 = 0;
                if(i>0){
                    e2 = paths[i-1][j];
                }
                paths[i][j] = e1 + e2;
            }
        }
        return paths[m-1][n-1];
        
    }
};




class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prevRow(n, 0);
        for(int i=0;i<m;i++){
            vector<int> currRow(n, 0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    currRow[j] = 0;
                    continue;
                }
                
                if(i==0 && j==0){
                    currRow[j] = 1;
                    continue;
                }

                int e1 = 0;
                if(j>0){
                    e1 = currRow[j-1];
                }

                int e2 = 0;
                if(i>0){
                    e2 = prevRow[j];
                }
                currRow[j] = e1 + e2;
            }

            prevRow = currRow;
        }
        return prevRow[n-1];
        
    }
};