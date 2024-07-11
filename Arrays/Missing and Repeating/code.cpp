class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        int repeating=-1, missing=1;
        for(int i=1;i<=n;i++){
            int cnt = 0;
            for(auto it : arr){
                if(it==i){
                    cnt++;
                }
            }
            
            if(cnt==0){
                missing = i;
            }
            
            else if(cnt==2){
                repeating = i;
            }
            
        }
        
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        int repeating=-1, missing=-1;
        unordered_map<int, int> mp;
        for(auto it : arr){
            mp[it]++;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                missing = i;
            }
            
            if(mp[i]==2){
                repeating = i;
            }
            
            if(repeating!=-1 && missing!=-1){
                break;
            }
            
        }
        
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};


class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int repeating=-1, missing=1;
        for(int i=1;i<=n;i++){
            int ind = i-1;
            if(arr[ind]==missing){
                missing++;
            }
            
            else if(arr[ind]!=i){
                repeating = arr[ind];
            }
            
        }
        
        ans.push_back(repeating);
        ans.push_back(missing);
        return ans;
    }
};


class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> ans;
        long long repeating, missing, temp=0, temp2=0, temp3;
        for(int i=1;i<=n;i++){
            int ind = i-1;
            temp+=arr[ind]-i;
            temp2+=((long long)arr[ind]*(long long)arr[ind])-((long long)i*(long long)i);
            
        }
        
        temp3 = temp2/temp;
        missing = (temp3-temp)/2;
        repeating = (temp3+temp)/2;
        
        missing = repeating - temp;
        ans.push_back((int)repeating);
        ans.push_back((int)missing);
        return ans;
    }
};