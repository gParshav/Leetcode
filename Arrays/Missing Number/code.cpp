// Brute Force
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int flag = 0;
        for(int i=0;i<=n;i++){
            flag = 0;
            for(auto it : nums){
                if(it==i){
                    flag = 1;
                    break;
                }
            }

            if(flag==0){
                return i;
            }
        }

        return -1;

    }
};

// Better
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }

        for(int i=0;i<=n;i++){
            if(mp[i]==0){
                return i;
            }
        }

        return -1;

    }
};


//Optimal 1

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = (n*(n+1))/2, temp=0;
        for(auto it : nums){
            temp+=it;
        }
        return sum-temp;

    }
};

//Optimal 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for(int i=0;i<n;i++){
            xor1 = xor1^(i+1);
            xor2 = xor2^nums[i];
        }

        return xor1^xor2;

    }
};