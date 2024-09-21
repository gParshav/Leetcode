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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* temp = root;
        while(temp!=NULL){
            if(temp->val>val){
                if(temp->left==NULL){
                    temp->left = new TreeNode(val);
                    return root;
                }

                temp=temp->left;
            }

            else{
                if(temp->right==NULL){
                    temp->right = new TreeNode(val);
                    return root;
                }

                temp=temp->right;
            }
        }

        return new TreeNode(val);

    }
};