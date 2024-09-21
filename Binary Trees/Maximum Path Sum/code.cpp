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
    int findSum(TreeNode* root, int& ans){

        if(root==NULL){
            return 0;
        }

        int s1 = findSum(root->left, ans);
        int s2 = findSum(root->right, ans);
        int sum = root->val + s1 + s2;
        ans = max(ans, sum);
        return max(0, max(root->val+s1, root->val+s2));

    }


    int maxPathSum(TreeNode* root) {
        
        int ans = -1e4;
        int x = findSum(root, ans);
        return ans;
    }
};