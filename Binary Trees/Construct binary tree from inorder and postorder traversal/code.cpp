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
    TreeNode* bTree(int postStart, int postEnd, int inStart, int inEnd, vector<int>& inorder, vector<int>& postorder, 
        unordered_map<int, int>& mp){
        
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }

        int temp = postorder[postEnd];
        TreeNode* root = new TreeNode(temp);
        int idx = mp[temp];
        int len = idx - inStart;
        root->left = bTree(postStart, postStart+len-1, inStart, idx-1, inorder, postorder, mp);
        root->right = bTree(postStart+len, postEnd-1, idx+1, inEnd, inorder, postorder, mp);
        return root;

    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> mp;
        int  n = inorder.size();
        int postStart = 0, postEnd = n-1, inStart = 0, inEnd = n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return bTree(postStart, postEnd, inStart, inEnd, inorder, postorder, mp);

    }
};