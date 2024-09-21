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
    vector<vector<int>> levelOrder(TreeNode* root) {
        

        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int k = q.size();
            vector<int> temp;
            for(int i=0;i<k;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr!=NULL && curr->left){
                    q.push(curr->left);
                }

                if(curr!=NULL && curr->right){
                    q.push(curr->right);
                }

                if(curr!=NULL){
                    temp.push_back(curr->val);
                }


                
            }
            ans.push_back(temp);
        }

        return ans;

    }
};