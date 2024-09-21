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
    int findHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1+max(lh, rh);
    }


    bool checkBalance(TreeNode* root){

        if(root==NULL){
            return true;
        }

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        if(abs(lh-rh)>1){
            return false;
        }

        if(checkBalance(root->left)==false || checkBalance(root->right)==false){
            return false;
        }

        return true;



    }
    
    bool isBalanced(TreeNode* root) {

        return checkBalance(root);    

    }
};




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
    int findBalance(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int leftHeight = findBalance(root->left);
        int rightHeight = findBalance(root->right);
        if(leftHeight==-1 || rightHeight==-1){
            return -1;
        }
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }


        return 1+max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        int x = findBalance(root);
        if(x==-1){
            return false;
        }
        return true;    

    }
};