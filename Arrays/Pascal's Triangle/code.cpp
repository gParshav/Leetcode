class Solution {
public:
    vector<int> f(int size){

        vector<int> temp(size, 1);
        int num = 1;
        for(int i=1;i<size;i++){
            num = num*(size-i)/(i);
            temp[i] = num;
            
        }
        return temp;

    }


    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=1;i<=numRows;i++){

            vector<int> temp = f(i);
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        vector<int> prev;
        for(int i=0;i<numRows;i++){

            int size = i+1;
            vector<int> temp(size, 1);
            for(int i=1;i<size-1;i++){
                if(prev.size()>0){
                    temp[i] = prev[i]+prev[i-1];
                }
            }
            prev = temp;
            ans.push_back(temp);

        }
        return ans;
    }
};