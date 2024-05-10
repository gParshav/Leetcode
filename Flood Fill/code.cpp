class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        int row = image.size();
        int startColor = image[sr][sc];
        if(startColor==newColor){
            return image;
        }
        int col = image[0].size();
        q.push({sr, sc});
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            image[x][y] = newColor;
            q.pop();
            for(int i=0;i<4;i++){
                int newx = x+dx[i];
                int newy = y+dy[i];
                if(newx>=0 && newx<row && newy>=0 && newy<col && image[newx][newy]==startColor){
                    image[newx][newy] = newColor;
                    q.push({newx, newy});
                }
                
            }
        }

        return image;
    }
};