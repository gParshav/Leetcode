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
    TreeNode* findAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        
        if(root==NULL){
            return NULL;
        }

        if(root==p || root==q){
            return root;
        }

        TreeNode* leftFind = findAncestor(root->left, p, q);
        TreeNode* rightFind = findAncestor(root->right, p, q);
        if(leftFind!=NULL && rightFind!=NULL){
            return root;
        }

        if(leftFind==NULL && rightFind!=NULL){
            return rightFind;
        }

        if(leftFind!=NULL && rightFind==NULL){
            return leftFind;
        }

        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findAncestor(root, p, q);
    }
};