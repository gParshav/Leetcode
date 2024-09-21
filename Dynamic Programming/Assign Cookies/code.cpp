class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans=0, i=g.size()-1, j=s.size()-1;
        while(i>=0 && j>=0){
            if(s[j]>=g[i]){
                ans++;
                i--;
                j--;
            }

            else{
                i--;
            }
        }
        return ans;
    }
};