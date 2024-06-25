//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void f(int i, int num, string temp, vector<string> &ans){
        
        if(i==num){
            ans.push_back(temp);
            return;
        }
        
        f(i+1, num, temp+'0', ans);
        if(temp.size()==0){
            f(i+1, num, temp+'1', ans);
        }
        if(i>0 && temp[i-1]!='1'){
            f(i+1, num, temp+'1', ans);    
        }
    }
    
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> ans;
        int i=0;
        string temp = "";
        f(i, num, temp, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends