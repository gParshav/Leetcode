class Solution {
public:
    bool isValid(int x1, int y1, int y2, int rows, int cols){
        if(x1<0 || x1>=rows ||  y1<0 || y2<0 || y1>=cols || y2>=cols){
            return false;
        }

        return true;
    }

    int countCherry(int x1, int y1, int y2, vector<vector<int>>& grid){

        if(x1==0 && y1==0 && y2==grid[0].size()-1){
            return grid[x1][y1]+grid[x1][y2];
        }

        if(!isValid(x1, y1, y2, grid.size(), grid[0].size())){
            return -1e5;
        }

        int dy[] = {-1, 0, 1};
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int newy1 = y1+dy[i];
                int newy2 = y2+dy[j];
                if(y1==y2){
                    ans = max(ans, grid[x1][y1]+countCherry(x1-1, newy1, newy2, grid));
                    
                } 

                else{
                    ans = max(ans, grid[x1][y1]+grid[x1][y2]+countCherry(x1-1, newy1, newy2, grid));
                }
            }
            
            


        }

        return ans;  
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = INT_MIN;
        for(int c1 = 0;c1<cols;c1++){
            for(int c2=0;c2<cols;c2++){
                ans = max(ans, countCherry(rows-1, c1, c2, grid));

            }
        }

        return ans;

    }
};



class Solution {
public:
    bool isValid(int x1, int y1, int y2, int rows, int cols){
        if(x1<0 || x1>=rows ||  y1<0 || y2<0 || y1>=cols || y2>=cols){
            return false;
        }

        return true;
    }

    int countCherry(int x1, int y1, int y2, vector<vector<vector<int>>>& cherry, vector<vector<int>>& grid){

        if(x1==0 && y1==0 && y2==grid[0].size()-1){
            return cherry[x1][y1][y2] = grid[x1][y1]+grid[x1][y2];
        }

        if(!isValid(x1, y1, y2, grid.size(), grid[0].size())){
            return -1e5;
        }

        if(cherry[x1][y1][y2]!=-1){
            return cherry[x1][y1][y2];
        }

        int dy[] = {-1, 0, 1};
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int newy1 = y1+dy[i];
                int newy2 = y2+dy[j];
                if(y1==y2){
                    ans = max(ans, grid[x1][y1]+countCherry(x1-1, newy1, newy2, cherry, grid));
                    
                } 

                else{
                    ans = max(ans, grid[x1][y1]+grid[x1][y2]+countCherry(x1-1, newy1, newy2, cherry, grid));
                }
            }

        }

        return cherry[x1][y1][y2] = ans;  
    }

    int cherryPickup(vector<vector<int>>& grid) {
        
        
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = INT_MIN;
        vector<vector<vector<int>>> cherry(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        for(int c1 = 0;c1<cols;c1++){
            for(int c2=0;c2<cols;c2++){
                ans = max(ans, countCherry(rows-1, c1, c2, cherry, grid));

            }
        }

        return ans;

    }
};



// Not yet able to understand tabulation and space optimization. Will update soon.