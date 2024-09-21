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
    void findDiameter(TreeNode* root, int& ans){

        if(root==0){
            return;
        }

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        int diameter = lh+rh;
        ans = max(ans, diameter);
        findDiameter(root->left, ans);
        findDiameter(root->right, ans);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        findDiameter(root, ans);
        return ans;
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
    int findHeight(TreeNode* root, int& ans){

        if(root==NULL){
            return 0;
        }

        int lh = findHeight(root->left, ans);
        int rh = findHeight(root->right, ans);
        ans = max(ans, lh+rh);
        return 1+max(lh, rh);

    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        findHeight(root, ans);
        return ans;
    }
};