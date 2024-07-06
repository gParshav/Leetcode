// Brute Force Solution
class Solution {
public:
    void makeRowZero(int row, vector<vector<int>>& matrix){

        int cols = matrix[0].size();
        for(int i=0;i<cols;i++){
            if(matrix[row][i]!=0){
                matrix[row][i] = 1104;
            }
        }

    }

    void makeColZero(int col, vector<vector<int>>& matrix){

        int rows = matrix.size();
        for(int i=0;i<rows;i++){
            if(matrix[i][col]!=0){
                matrix[i][col] = 1104;
            }
            
        }

    }


    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    makeRowZero(i, matrix);
                    makeColZero(j, matrix);
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1104){
                    matrix[i][j] = 0;
                }
            }
        }

        

    }
};



// Better 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        vector<int> rows;
        vector<int> cols;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for(int i=0;i<rows.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[rows[i]][j] = 0;
            }
        }

        for(int i=0;i<cols.size();i++){
            for(int j=0;j<matrix.size();j++){
                matrix[j][cols[i]] = 0;
            }
        }

        return;

    }
};


// Better 2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        vector<int> rows(nrow, 0);
        vector<int> cols(ncol, 0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i=0;i<nrow;i++){
            for(int j=0;j<ncol;j++){
                if(rows[i]==1 || cols[j]==1){
                    matrix[i][j] = 0;
                }
            }
        }

        return;

    }
};


// Optimal
