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
    TreeNode* find(vector<int>& preorder, int& i, int left, int right){

        if(i>=preorder.size()){
            return NULL;
        }

        if(preorder[i]>=right || preorder[i]<=left){
            return NULL;
        }

        TreeNode* temp = new TreeNode(preorder[i]);
        i++;
        temp->left = find(preorder, i, left, temp->val);
        temp->right = find(preorder,i, temp->val, right);
        return temp;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int i = 0;
        return find(preorder, i, INT_MIN, INT_MAX);
    }

};