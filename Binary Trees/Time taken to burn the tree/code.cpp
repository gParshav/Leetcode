class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> par;
        Node* start;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            for(int i=0;i<k;i++){
                Node* temp = q.front();
                if(temp->data==target){
                    start = temp;
                }
                q.pop();
                if(temp->left!=NULL){
                    par[temp->left] = temp;
                    q.push(temp->left);
                }
                
                if(temp->right!=NULL){
                    par[temp->right] = temp;
                    q.push(temp->right);
                }
                
            }
        }
        
        int ans = -1;
        queue<Node*> q2;
        unordered_map<Node*, int> vis;
        q2.push(start);
        vis[start] = 1;
        while(!q2.empty()){
            int k = q2.size();
            ans++;
            for(int i=0;i<k;i++){
                Node* temp = q2.front();
                q2.pop();
                if(temp->left!=NULL && vis[temp->left]==0){
                    q2.push(temp->left);
                    vis[temp->left]=1;
                }
                
                if(temp->right!=NULL && vis[temp->right]==0){
                    q2.push(temp->right);
                    vis[temp->right]=1;
                }
                
                if(par.find(temp)!=par.end() && vis[par[temp]]==0){
                    vis[par[temp]]=1;
                    q2.push(par[temp]);
                }
            }
        }
        return ans;
    }
};

