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
    bool check(TreeNode* p, TreeNode* q){

        if(p==NULL && q==NULL){
            return true;
        }

        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }

        if(p->val!=q->val){
            return false;
        }

        int l = check(p->left, q->left);
        int r = check(p->right, q->right);
        return l && r;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};