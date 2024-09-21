class Solution {
  public:
    int cost(vector<int>& height, int step, int k){
        
        if(step==0){
            return 0;
        }
        
        
        int c = INT_MAX;
        for(int i=1;i<=k;i++){
            if(step-i>=0){
                c = min(c, cost(height, step-i, k)+abs(height[step]-height[step-i]));    
            }
            
        }
        
        return c;
            
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return cost(height, n-1, k);
    }
};


class Solution {
  public:
    int cost(vector<int>& minCost, vector<int>& height, int step, int k){
        
        if(step==0){
            return 0;
        }
        
        if(minCost[step]!=-1){
            return minCost[step]; 
        }
        
        
        int c = INT_MAX;
        for(int i=1;i<=k;i++){
            if(step-i>=0){
                c = min(c, cost(minCost, height, step-i, k)+abs(height[step]-height[step-i]));    
            }
            
        }
        
        
        return minCost[step]=c;      
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> minCost(n, -1);
        return cost(minCost, height, n-1, k);
    }
};

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> minCost(n, -1);
        minCost[0] = 0;
        for(int step=1;step<n;step++){
            int c = INT_MAX;
            for(int i=1;i<=k;i++){
                if(step-i>=0){
                    c = min(c, minCost[step-i]+abs(height[step]-height[step-i]));    
                }
                
            }
            
            
            minCost[step]=c;
        }
        return minCost[n-1];
    }
};