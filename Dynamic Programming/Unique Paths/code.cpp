class Solution {
public:
    bool isValid(int m, int n, int x, int y){

        if(x<m && x>=0 && y<n && y>=0){
            return true;
        }

        return false;

    }

    int countPath(int m, int n, int x, int y){

        if(x==0 && y==0){
            return 1;
        }

        if(!isValid(m, n, x, y)){
            return 0;
        }

        return countPath(m, n, x, y-1)+countPath(m, n, x-1, y);
        

    }

    int uniquePaths(int m, int n) {
        
        return countPath(m, n, m-1, n-1);
    }
};


class Solution {
public:
    bool isValid(int m, int n, int x, int y){

        if(x<m && x>=0 && y<n && y>=0){
            return true;
        }

        return false;

    }

    int countPath(int m, int n, int x, int y, vector<vector<int>> &paths){

        if(x==0 && y==0){
            return paths[x][y] = 1;
        }

        if(!isValid(m, n, x, y)){
            return 0;
        }

        if(paths[x][y]!=-1){
            return paths[x][y];
        }

        return paths[x][y] = countPath(m, n, x, y-1, paths)+countPath(m, n, x-1, y, paths);
        

    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> paths(m, vector<int>(n, -1));
        return countPath(m, n, m-1, n-1, paths);
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> paths(m, vector<int>(n, -1));
        paths[0][0] = 1;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(x==0 && y==0){
                    continue;
                }
                int e1 = 0;
                if(y>0){
                    e1 = paths[x][y-1];
                }

                int e2 = 0;
                if(x>0){
                    e2 = paths[x-1][y];
                }
                paths[x][y] = e1+e2;
            }
        }
        return paths[m-1][n-1];
    }
};



class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> prevRow(n, 0);
        for(int x=0;x<m;x++){
            vector<int> currRow(n, 0);
            for(int y=0;y<n;y++){
                if(x==0 && y==0){
                    currRow[y] = 1;
                    continue;
                }
                int e1 = 0;
                if(y>0){
                    e1 = currRow[y-1];
                }

                int e2 = 0;
                if(x>0){
                    e2 = prevRow[y];
                }
                currRow[y] = e1+e2;
            }

            prevRow = currRow;
        }
        return prevRow[n-1];
    }
};