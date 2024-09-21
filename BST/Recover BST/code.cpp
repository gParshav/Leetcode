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
    void inorder(TreeNode* root, vector<int>& arr){

        if(root==NULL){
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

    }

    void correct(TreeNode* root, vector<int>& arr, int& i){

        if(root==NULL){
            return;
        }

        correct(root->left, arr, i);
        root->val = arr[i];
        i++;
        correct(root->right, arr, i);
    }

    void recoverTree(TreeNode* root) {
        
        vector<int> arr;
        int i=0;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        correct(root, arr, i);

    }
};