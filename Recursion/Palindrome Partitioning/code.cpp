// Not so good code
class Solution {
public:
    bool isPalindrome(string temp){
        int left=0;
        int right=temp.size()-1;
        while(left<=right){
            if(temp[left]!=temp[right]){
                return false;
            }

            left++;
            right--;
            continue;
        }

        return true;
    }

    void f(int start, int end, string s, vector<string> arr, vector<vector<string>> &ans) {
        
        
        

        for(int k=start;k<end;k++){
            string temp = "";
            if(k==start){
                temp+=s[k];
            }
            else{
                for(int i=start;i<=k;i++){
                    temp+=s[i];
                }
            }

            if(!isPalindrome(temp)){
                continue;
            }
            
            arr.push_back(temp);
            f(k+1, end, s, arr, ans);
            arr.pop_back();
        }

        int r = 0;
        for (const auto& str : arr) {
            r+=str.size();
            cout << str << " ";
        }
        cout << std::endl;
        if(r==s.size()){
            ans.push_back(arr);
        }

        return;
        
        


    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> arr;
        int n = s.size();
        f(0, n, s, arr, ans);
        return ans;
    }
};


// Same thing but with better code and basic modifications

class Solution {
public:
    bool isPalindrome(string temp){
        int left=0;
        int right=temp.size()-1;
        while(left<=right){
            if(temp[left]!=temp[right]){
                return false;
            }

            left++;
            right--;
            continue;
        }

        return true;
    }

    void f(int start, string s, vector<string> arr, vector<vector<string>> &ans) {
        
        for(int k=start;k<s.size();k++){
            string temp = "";
            for(int i=start;i<=k;i++){
                temp+=s[i];
            }

            if(!isPalindrome(temp)){
                continue;
            }
            
            arr.push_back(temp);
            f(k+1, s, arr, ans);
            arr.pop_back();
        }

        if(start==s.size()){
            ans.push_back(arr);
        }
        return;

    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> arr;
        f(0, s, arr, ans);
        return ans;
    }
};
