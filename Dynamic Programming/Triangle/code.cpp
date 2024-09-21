class Solution {
public:
    int countTotal(int i, int height, vector<vector<int>>& triangle){

        if(height==0){
            return triangle[0][0];
        }

        if(i<0 || i>=triangle[height].size()){
            return 1e5;
        }

        int e1 = triangle[height][i]+countTotal(i, height-1, triangle);
        int e2 = triangle[height][i]+countTotal(i-1, height-1, triangle);

        return min(e1, e2);

    }


    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans, countTotal(i, n-1, triangle));
        }

        return ans;
        

    }
};



class Solution {
public:
    int countTotal(int i, int height, vector<vector<int>>& mtot, vector<vector<int>>& triangle){

        if(height==0){
            return mtot[0][height] = triangle[0][0];
        }

        if(i<0 || i>=triangle[height].size()){
            return 1e5;
        }

        if(mtot[i][height]!=-1){
            return mtot[i][height];
        }

        int e1 = triangle[height][i]+countTotal(i, height-1, mtot, triangle);
        int e2 = triangle[height][i]+countTotal(i-1, height-1, mtot, triangle);

        return mtot[i][height] = min(e1, e2);

    }


    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> mtot(n, vector<int>(n, -1));
        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans, countTotal(i, n-1, mtot, triangle));
        }

        return ans;
        

    }
};


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> prev(n, 0);
        prev[0] = triangle[0][0];
        for(int height=1;height<n;height++){
            vector<int> curr(n, 0);
            for(int i=0;i<triangle[height].size();i++){
                int e1 = 1e5;
                if(i<triangle[height-1].size()){
                    e1 = triangle[height][i]+prev[i];
                }
                int e2 = 1e5;
                if(i>0){
                    e2 = triangle[height][i]+prev[i-1];
                }
                curr[i] = min(e1, e2);
            }

            prev = curr;
        }


        int ans = INT_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans, prev[i]);
        }

        return ans;
        

    }
};