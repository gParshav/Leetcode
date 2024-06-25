class Solution {
public:
    void f(int open, int close, int n, vector<string> &ans, string temp){

        if(open==n && close == n){
            ans.push_back(temp);
            return;
        }

        if(open<n){
            f(open+1, close, n, ans, temp+'(');
        }

        if(close<open){
            f(open, close+1, n, ans, temp+')');
        }

        
        

    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        int open = 0;
        int close = 0;
        f(open, close, n, ans, temp);
        return ans;
    }
};