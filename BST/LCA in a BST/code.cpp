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
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){

        if(root==NULL){
            return NULL;
        }

        if(root==p || root==q){
            return root;
        }

        TreeNode* leftSearch = find(root->left, p, q);
        TreeNode* rightSearch = find(root->right, p, q);
        if(leftSearch!=NULL && rightSearch!=NULL){
            return root;
        }

        if(leftSearch!=NULL && rightSearch==NULL){
            return leftSearch;
        }

        if(leftSearch==NULL && rightSearch!=NULL){
            return rightSearch;
        }

        return NULL;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return find(root, p, q);

    }
};