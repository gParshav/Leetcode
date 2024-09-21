class Solution {
  public:
    int calcPoints(int prev, vector<vector<int>>& points, int day){
        
        if(day<0){
            return 0;
        }
        
        
        int p = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=prev){
                p = max(p, calcPoints(i, points, day-1)+points[day][i]);
            }
        }
        
        return p;
            
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int prev = -1;
        return calcPoints(prev, points, n-1);
    }
};


class Solution {
  public:
    int calcPoints(int prev, vector<vector<int>>& points, vector<vector<int>> &maxPoints, int day){
        
        if(day<0){
            return 0;
        }
        
        if(maxPoints[day][prev]!=-1){
            return maxPoints[day][prev];
        }
        
        
        int p = INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=prev){
                p = max(p, points[day][i]+calcPoints(i, points, maxPoints, day-1));
            }
        }
        
        return maxPoints[day][prev] = p;
            
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> maxPoints(n, vector<int>(3, -1));
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            ans = max(ans, calcPoints(i, points, maxPoints, n-1));
        }
        return ans;
    }
};


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> maxPoints(n, vector<int>(3, -1));
        for(int prev=0;prev<3;prev++){
            int p = 0;
            for(int i=0;i<3;i++){
                if(i!=prev){
                    p = max(p, points[0][i]);
                }
            }
            
            maxPoints[0][prev] = p;
        }
        
        
        for(int day=1;day<n;day++){
            for(int prev=0;prev<3;prev++){
                int p = 0;
                for(int curr=0;curr<3;curr++){
                    if(curr!=prev){
                        p = max(p, points[day][curr]+maxPoints[day-1][curr]);
                    }
                }
                
                maxPoints[day][prev] = p;
            }
        }
        
        
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            ans = max(ans, maxPoints[n-1][i]);
        }
        return ans;
    }
};

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int> maxPoints(3, -1);
        for(int prev=0;prev<3;prev++){
            int p = 0;
            for(int i=0;i<3;i++){
                if(i!=prev){
                    p = max(p, points[0][i]);
                }
            }
            
            maxPoints[prev] = p;
        }
        
        
        for(int day=1;day<n;day++){
            vector<int> temp = maxPoints;
            for(int prev=0;prev<3;prev++){
                int p = 0;
                for(int curr=0;curr<3;curr++){
                    if(curr!=prev){
                        p = max(p, points[day][curr]+temp[curr]);
                    }
                }
                
                maxPoints[prev] = p;
            }
        }
        
        
        int ans = INT_MIN;
        for(int i=0;i<3;i++){
            ans = max(ans, maxPoints[i]);
        }
        return ans;
    }
};