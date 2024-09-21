/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            int k = q.size();
            vector<int> level;
            for(int i=0;i<k;i++){
                TreeNode* temp = q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }

            if(flag==0){
                ans.push_back(level);
                flag = 1;
                continue;
            }

            else{
                reverse(level.begin(), level.end());
                ans.push_back(level);
                flag = 0;
                continue;
            }
        }

        return ans;

    }
};