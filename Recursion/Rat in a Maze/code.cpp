// Nice and clean code. Done all by myself.
class Solution{
    public:
    bool isValid(int i, int j, int n){
        if(i>=0 && j>=0 && i<n && j<n){
            return true;
        }
        
        return false;
    }   
    
    void f(int x, int y, int n, string &temp, vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> &vis){
        
        if(x==n-1 && y==n-1){
            ans.push_back(temp);
        }
        
        int dy[] = {-1, 0, 1, 0};
        int dx[] = {0, 1, 0, -1};
        string dir = "LDRU";
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isValid(newx, newy, n) && m[newx][newy] == 1 && vis[newx][newy]== 0){
                char k = dir[i];
                temp.push_back(k);
                vis[newx][newy] = 1;
                f(newx, newy, n, temp, m, ans, vis);
                vis[newx][newy] = 0;
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0 || m[n-1][n-1]==0){
            return ans;
        }   
        
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string temp = "";
        vis[0][0] = 1;
        f(0, 0, n, temp, m, ans, vis);
        return ans;
    }
};