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
    void find(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }

        find(root->left, ans);
        ans.push_back(root->val);
        find(root->right, ans);

    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        find(root, ans);
        int n = ans.size();
        int i;
        for(i=1;i<n;i++){
            if(ans[i]>ans[i-1]){
                continue;
            }

            else{
                break;
            }
        }

        if(i==n){
            return true;
        }

        return false;
    }
};



class Solution {
public:
    bool find(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return find(root->left, lower, root->val) && find(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        return find(root, LLONG_MIN, LLONG_MAX);
    }
};
