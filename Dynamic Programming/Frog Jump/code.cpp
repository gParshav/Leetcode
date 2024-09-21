class Solution {
  public:
    int f(vector<int>& height, int stair){
        if(stair<=0){
            return 0;
        }    
        
        int e2 = INT_MAX;
        int e1 = f(energy, height, stair-1)+abs(height[stair]-height[stair-1]);
        if(stair>1){
            e2 = f(energy, height, stair-2)+abs(height[stair]-height[stair-2]);
        }
        return min(e1, e2);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return f(height, n-1);
    }
};

class Solution {
  public:
    int f(vector<int> &energy, vector<int>& height, int stair){
        if(stair<=0){
            return 0;
        }    
        
        if(energy[stair]!=-1){
            return energy[stair];
        }
        
        int e2 = INT_MAX;
        int e1 = f(energy, height, stair-1)+abs(height[stair]-height[stair-1]);
        if(stair>1){
            e2 = f(energy, height, stair-2)+abs(height[stair]-height[stair-2]);
        }
        
        return energy[stair] = min(e1, e2);
    }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> energy(n, -1);
        return f(energy, height, n-1);
    }
};

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev = 0, prev2, curr;
        for(int stair=1;stair<n;stair++){
            
            int e2 = INT_MAX;
            int e1 = prev+abs(height[stair]-height[stair-1]);
            if(stair>1){
                e2 = prev2+abs(height[stair]-height[stair-2]);
            }
            
            
            
            curr = min(e1, e2);
            prev2 = prev;
            prev = curr;
            
        }
        return curr;
    }
};