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
    int countNodes(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(root==NULL){
            return 0;
        }
        q.push(root);

        int ans = 0;
        while(!q.empty()){
            int k = q.size();
            ans+=k;
            for(int i=0;i<k;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    q.push(temp->left);
                }

                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
        return ans;

    }
};




class Solution {
public:
    int count(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int lc = count(root->left);
        int rc = count(root->right);
        return 1+lc+rc;

    }
    int countNodes(TreeNode* root) {
        
        return count(root);

    }
};



class Solution {
public:
    void count(TreeNode* root, int& ans){

        if(root==NULL){
            return;
        }

        count(root->left, ans);
        count(root->right, ans);
        ans++;

    }
    int countNodes(TreeNode* root) {
        
        int ans = 0;
        count(root, ans);
        return ans;

    }
};