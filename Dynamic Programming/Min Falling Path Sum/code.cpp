class Solution {
public:
    int findSum(int row, int col, vector<vector<int>>& matrix){

        if(row==0){
            if(col<0 || col>=matrix.size()){
                return 1e5;
            }    
            return matrix[row][col];
        }

        if(col<0 || col>=matrix.size()){
            return 1e5;
        }
        
        int e1 = matrix[row][col]+findSum(row-1, col, matrix);
        int e2 = matrix[row][col]+findSum(row-1, col-1, matrix);
        int e3 = matrix[row][col]+findSum(row-1, col+1, matrix);
        return min(e1, min(e2, e3));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, findSum(n-1, i, matrix));
        }

        return ans;
    }
};


class Solution {
public:
    int findSum(int row, int col, vector<vector<int>>& pathSum, vector<vector<int>>& matrix){

        if(row==0){
            if(col<0 || col>=matrix.size()){
                return 1e5;
            }    
            return pathSum[row][col] = matrix[row][col];
        }

        if(col<0 || col>=matrix.size()){
            return 1e5;
        }

        if(pathSum[row][col]!=-1){
            return pathSum[row][col];
        }

        int e1 = matrix[row][col]+findSum(row-1, col, pathSum, matrix);
        int e2 = matrix[row][col]+findSum(row-1, col-1, pathSum, matrix);
        int e3 = matrix[row][col]+findSum(row-1, col+1, pathSum, matrix);
        return pathSum[row][col] = min(e1, min(e2, e3));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> pathSum(n, vector<int>(n, -1));
        for(int i=0;i<n;i++){
            ans = min(ans, findSum(n-1, i, pathSum, matrix));
        }

        return ans;
    }
};


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> pathSum(n, vector<int>(n, -1));
        for(int col=0;col<n;col++){
            pathSum[0][col] = matrix[0][col];
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int e1 = matrix[row][col]+pathSum[row-1][col];
                int e2 = INT_MAX;
                if(col>0){
                    e2 = matrix[row][col]+pathSum[row-1][col-1];
                }
                int e3 = INT_MAX; 
                if(col<n-1){
                    e3 = matrix[row][col]+pathSum[row-1][col+1];
                }
                
                pathSum[row][col] = min(e1, min(e2, e3));
            }
        }


        for(int i=0;i<n;i++){
            ans = min(ans, pathSum[n-1][i]);
        }

        return ans;
    }
};



class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int ans = INT_MAX;
        vector<int> pathSum(n, 0);
        for(int col=0;col<n;col++){
            pathSum[col] = matrix[0][col];
        }

        for(int row=1;row<n;row++){
            vector<int> curr(n, 0);
            for(int col=0;col<n;col++){
                int e1 = matrix[row][col]+pathSum[col];
                int e2 = INT_MAX;
                if(col>0){
                    e2 = matrix[row][col]+pathSum[col-1];
                }
                int e3 = INT_MAX; 
                if(col<n-1){
                    e3 = matrix[row][col]+pathSum[col+1];
                }
                
                curr[col] = min(e1, min(e2, e3));
            }
            pathSum = curr;
        }


        for(int i=0;i<n;i++){
            ans = min(ans, pathSum[i]);
        }

        return ans;
    }
};