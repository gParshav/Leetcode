class Solution {
public:
    bool isValid(int m, int n, int x, int y){

        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }

        return false;
    }

    int minSum(int m, int n, int x, int y, vector<vector<int>>& grid){
        if(x==0 && y==0){
            return grid[x][y];
        }

        if(!isValid(m, n, x, y)){
            return 201;
        }

        int e1 = grid[x][y] + minSum(m, n, x, y-1, grid);
        int e2 = grid[x][y] + minSum(m, n, x-1, y, grid);

        return min(e1, e2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        return minSum(m, n, m-1, n-1, grid);

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

    int findMinSum(int m, int n, int x, int y, vector<vector<int>>& grid, vector<vector<int>>& minSum){
        if(x==0 && y==0){
            return minSum[x][y] = grid[x][y];
        }

        if(!isValid(m, n, x, y)){
            return 1e5;
        }

        if(minSum[x][y]!=-1){
            return minSum[x][y];
        }

        int e1 = grid[x][y] + findMinSum(m, n, x, y-1, grid, minSum);
        int e2 = grid[x][y] + findMinSum(m, n, x-1, y, grid, minSum);

        return minSum[x][y] = min(e1, e2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minSum(m, vector<int>(n, -1));
        return findMinSum(m, n, m-1, n-1, grid, minSum);

    }
};



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> minSum(m, vector<int>(n, -1));
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(x==0 && y==0){
                    minSum[x][y] = grid[x][y];
                    continue;
                }

                int e1 = 1e5;
                if(y>0){
                    e1 = grid[x][y] + minSum[x][y-1];
                }

                int e2 = 1e5;
                if(x>0){
                    e2 = grid[x][y] + minSum[x-1][y];;
                }
                
                minSum[x][y] = min(e1, e2);

            }
        }
        return minSum[m-1][n-1];

    }
};




class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prevRow(n, 0);
        for(int x=0;x<m;x++){
            vector<int> currRow(n, 0);
            for(int y=0;y<n;y++){
                if(x==0 && y==0){
                    currRow[y] = grid[x][y];
                    continue;
                }

                int e1 = 1e5;
                if(y>0){
                    e1 = grid[x][y] + currRow[y-1];
                }

                int e2 = 1e5;
                if(x>0){
                    e2 = grid[x][y] + prevRow[y];;
                }
                
                currRow[y] = min(e1, e2);

            }
            prevRow = currRow;
        }
        return prevRow[n-1];

    }
};