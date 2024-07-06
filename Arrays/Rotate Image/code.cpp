class Solution {
public:
    void rearrange(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& visited, int val){
        
        int n = matrix.size();
        int newi = j;
        int newj = n-1-i;
        int temp = matrix[newi][newj];
        matrix[newi][newj] = val;
        if(visited[newi][newj]==0){
            visited[newi][newj]=1;
            rearrange(newi, newj, matrix, visited, temp);
        }
        
        return;

    }

    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>>visited(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0){
                    visited[i][j] = 1;
                    rearrange(i, j, matrix, visited, matrix[i][j]);
                }
            }
        }

        return;


    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>>ans(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int newi = j;
                int newj = n-1-i;
                ans[newi][newj] = matrix[i][j];
            }
        }

        matrix = ans;

        return;


    }
};


class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;

            }
        }
        return;


    }

    void reverse(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i=0;i<n;i++){
            int start = 0;
            int end = n-1;
            while(start<=end){
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;

            }
        }
        return;


    }


    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        transpose(matrix);
        reverse(matrix);
        return;


    }
};