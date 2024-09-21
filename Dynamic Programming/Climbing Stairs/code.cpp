class Solution {
public:
    int f(int n){

        if(n<=1){
            return 1;
        }

        return f(n-1)+f(n-2);

    }

    int climbStairs(int n) {

       return f(n);

    }
};


class Solution {
public:
    int f(vector<int> &temp, int n){

        if(n<=1){
            return 1;
        }

        if(temp[n]!=-1){
            return temp[n];
        }

        return temp[n] = f(temp, n-1)+f(temp, n-2);

    }

    int climbStairs(int n) {

       vector<int> temp(n+1, -1);
       return f(temp, n);

    }
};


class Solution {
public:
    int climbStairs(int n) {

       vector<int> temp(n+1, -1);
       temp[0] = 1;
       temp[1] = 1;
       for(int i=2;i<=n;i++){
            temp[i] = temp[i-1]+temp[i-2];
       }
       return temp[n];

    }
};


class Solution {
public:
    int climbStairs(int n) {

       int prev2 = 1, prev = 1, curr;
       if(n<=1){
        return 1;
       }
       for(int i=2;i<=n;i++){
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
       }
       return curr;

    }
};