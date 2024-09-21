/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> par;
        queue<TreeNode*> q;
        if(root==NULL){
            return ans;
        }

        q.push(root);
        while(!q.empty()){
            
            int k2 = q.size();
            for(int i=0;i<k2;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                    par[temp->left] = temp;
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                    par[temp->right] = temp;
                }
            }
        }
        // Find the parent of each node
        queue<TreeNode*> q2;
        int cnt = -1;
        unordered_map<TreeNode *, int> vis;
        q2.push(target);
        while(!q2.empty()){
            cnt++;
            int len = q2.size();
            for(int i=0;i<len;i++){
                TreeNode* temp = q2.front();
                if(cnt==k){
                    ans.push_back(temp->val);
                }
                q2.pop();
                vis[temp] = 1;
                if(temp->left!=NULL && vis[temp->left]==0){
                    q2.push(temp->left);
                    vis[temp->left] = 1;
                }

                if(temp->right!=NULL && vis[temp->right]==0){
                    q2.push(temp->right);
                    vis[temp->right] = 1;
                }

                if(par.find(temp)!=par.end() && par[temp]!=NULL && vis[par[temp]]==0){
                    q2.push(par[temp]);
                    vis[par[temp]] = 1;
                }
            }
        }

        // Iterate the tree radially starting from the target node
        return ans;

    }
};