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
    int i = -1;
    int findIndex(int temp, vector<int>& inorder){

        for(int j=0;j<inorder.size();j++){
            if(inorder[j]==temp){
                return j;
            }
        }

        return 0;

    }

    TreeNode* find(vector<int>& preorder, vector<int>& inorder, int start, int end){
        
        if(start>end){
            return NULL;
        }
        i++;
        if(i>=preorder.size()){
            return NULL;
        }

        TreeNode* temp = new TreeNode(preorder[i]);
        int x = findIndex(preorder[i], inorder);
        temp->left = find(preorder, inorder, start, x-1);
        temp->right = find(preorder, inorder, x+1, end);
        return temp;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return find(preorder, inorder, 0, preorder.size()-1);

    }
};


class Solution {
public:
    TreeNode* bTree(int pStart, int pEnd, int iStart, int iEnd, vector<int>& inorder, vector<int>& preorder, 
        unordered_map<int,int>& mp){
        if(pStart>pEnd || iStart>iEnd){
            return NULL;
        }

        int temp = preorder[pStart];
        TreeNode* root = new TreeNode(temp);
        int idx = mp[temp];
        int len = idx - iStart;
        root->left = bTree(pStart+1, pStart+len, iStart, idx-1, inorder, preorder, mp);
        root->right = bTree(pStart+len+1, pEnd, idx+1, iEnd, inorder, preorder, mp);
        return root;


        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int,int> mp;
        int n = inorder.size();
        int pStart = 0, pEnd = n-1, iStart = 0, iEnd = n-1;
        for(int i=0;i<n;i++){
            int ele = inorder[i];
            int idx = i;
            mp[ele] = idx;
        }

        return bTree(pStart, pEnd, iStart, iEnd, inorder, preorder, mp);

    }

};