class Solution {
public:
    void f(int idx, vector<string> &ans, vector<string> arr, string temp, string digits){
        if(idx>=digits.size()){
            ans.push_back(temp);
            return;
        }

        int x = digits[idx] - '0';
        for(int i=0;i<arr[x].size();i++){
            
            temp.push_back(arr[x][i]);
            f(idx+1, ans, arr, temp, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        vector<string> ans;
        vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp = "";
        int i = 0;
        f(0, ans, arr, temp, digits);
        return ans;
    }
};