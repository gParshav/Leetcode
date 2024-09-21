class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        map<int, int> mp;
        queue<pair<int, Node*>> q;
        q.push({0, root});
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                int y = q.front().first;
                Node* temp = q.front().second;
                mp[y] = temp->data;
                q.pop();
                if(temp->left!=NULL){
                    q.push({y-1, temp->left});
                }
                
                if(temp->right!=NULL){
                    q.push({y+1, temp->right});
                }
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};