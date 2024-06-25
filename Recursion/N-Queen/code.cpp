class Solution {
public:
    bool isValid(int row, int col, vector<vector<int>> &temp){
        int n = temp.size();
        for(int i=0;i<n;i++){
            if(i!=row){
                if(temp[i][col]==1){
                    return false;
                }
            }
            
        }

        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            i--;
            j--;
            if(i>=0 && j>=0 && temp[i][j]==1){
                return false;
            }

        }

        i = row;
        j = col;
        while(i<n && j<n){
            i++;
            j++;
            if(i<n && j<n && temp[i][j]==1){
                return false;
            }

        }

        i = row;
        j = col;
        while(i<n && j>=0){
            i++;
            j--;
            if(i<n && j>=0 && temp[i][j]==1){
                return false;
            }

        }

        i = row;
        j = col;
        while(i>=0 && j<n){
            i--;
            j++;
            if(i>=0 && j<n && temp[i][j]==1){
                return false;
            }

        }

        

        return true;
    }
    

    void f(int row, int n, vector<vector<vector<int>>> &ans, vector<vector<int>> temp) {

        if(row>=n){
            ans.push_back(temp);
            return;
        }

        for(int col=0;col<n;col++){
            if(isValid(row, col, temp)){
                temp[row][col] = 1;
                f(row+1, n, ans, temp);
                temp[row][col] = 0;
            }

        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> temp(n, vector<int>(n, 0));
        vector<vector<vector<int>>> ans;
        f(0, n, ans, temp);
        vector<vector<string>> ans2;
        for(int i=0;i<ans.size();i++){
            vector<string> mat;
            for(int j=0;j<n;j++){
                string row = "";
                for(int k=0;k<n;k++){
                    int ele = ans[i][j][k];
                    if(ele==0){
                        row+=".";
                    }

                    else{
                        row+='Q';
                    }
                }
                mat.push_back(row);
            }
            ans2.push_back(mat);


        }
        return ans2;
    }
};

// Much neater and a cleaner code.

class Solution {
public:

    bool isSafe(int row, int col, vector<string> &board, int n){
        
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        col = dupcol;
        row = duprow;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }

            col--;
        }


        col = dupcol;
        row = duprow;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }

            row++;
            col--;
        }


        return true;

    }

    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){

        if(col==n){
            ans.push_back(board);
        }

        for(int row=0;row<n;row++) {
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }

        solve(0, board, ans, n);
        return ans;
    }
};