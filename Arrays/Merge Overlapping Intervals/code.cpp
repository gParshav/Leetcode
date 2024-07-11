class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        int n = intervals.size(),i = 1, t=0;
        if(n==1){
            return intervals;
        }
        while(i<n){
            int ele1 = intervals[i-1][0];
            int ele2 = intervals[i-1][1];
            if(intervals[i][0]<=ele2){
                while(i<n && intervals[i][0]<=ele2){
                    if(i==n-1){
                        t=1;
                    }
                    ele1 = min(ele1, intervals[i][0]);
                    ele2 = max(ele2, intervals[i][1]);
                    i++;

                }

                ans.push_back({ele1, ele2});

            }

            else{
                ans.push_back({intervals[i-1][0], intervals[i-1][1]});
            }
            
            i++;
            
        }

        if(t==0){
            ans.push_back({intervals[n-1][0], intervals[n-1][1]});
        }

        return ans;


    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        ans.push_back({intervals[0][0], intervals[0][1]});
        int n = intervals.size();
        int ele1 = intervals[0][0], ele2 = intervals[0][1], ptr = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ele2){
                ele2 = max(ele2, intervals[i][1]);
                ans[ptr][1] = ele2;
            }

            else{
                ans.push_back({intervals[i][0], intervals[i][1]});
                ele1 = intervals[i][0];
                ele2 = intervals[i][1];
                ptr++;
            }
        }
        return ans;

    }
};