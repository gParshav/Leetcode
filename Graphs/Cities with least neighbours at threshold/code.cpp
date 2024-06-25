class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        vector<int> temp(n, 0);
        for(auto it : edges){
            int src = it[0];
            int dst = it[1];
            int wt = it[2];
            matrix[src][dst] = wt;
            matrix[dst][src] = wt;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    matrix[i][j] = 0;
                }   
            }
        }
       

        for(int via = 0;via<n;via++){
            for(int src = 0;src<n;src++){
                for(int dst = 0;dst<n;dst++){
                    matrix[src][dst] = min(matrix[src][dst], matrix[src][via]+matrix[via][dst]);
                }
            }
        }

        for(int i=0;i<n;i++){
            int k = 0;
            for(int j=0;j<n;j++){
                if(i!=j && matrix[i][j]<=distanceThreshold){
                    k++;
                }
            }

            temp[i] = k;
        }

        int ans = 0;
        int x = 1e9;
        for(int i=0;i<n;i++){
            if(temp[i]<=x){
                x = temp[i];
                ans = i;
            }
        }

        return ans;
    }
};