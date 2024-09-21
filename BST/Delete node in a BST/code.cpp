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
    TreeNode* findNode(TreeNode* root, TreeNode*& parent, int key){

        if(root==NULL){
            return NULL;
        }

        if(root->left!=NULL && root->left->val==key){
            parent = root;
        }

        if(root->right!=NULL && root->right->val==key){
            parent = root;
        }

        if(root->val==key){
            return root;
        }

        if(root->val>key){
            return findNode(root->left, parent, key);
        }

        else{
            return findNode(root->right, parent, key);
        }

        return NULL;

    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent = NULL;
        TreeNode* keyNode = findNode(root, parent, key);
        if(keyNode==NULL){
            return root;
        }

        if(keyNode->right!=NULL){
            keyNode->val = keyNode->right->val;
            TreeNode* temp = keyNode->left;
            TreeNode* temp2 = keyNode->right;
            keyNode->left = keyNode->right->left;
            keyNode->right = keyNode->right->right;
            while(keyNode->left!=NULL){
                keyNode=keyNode->left;
            }

            keyNode->left = temp;
        }

        else if(keyNode->left!=NULL){
            keyNode->val = keyNode->left->val;
            TreeNode* temp = keyNode->right;
            TreeNode* temp2 = keyNode->left;
            keyNode->right = keyNode->left->right;
            keyNode->left = keyNode->left->left;
            while(keyNode->right!=NULL){
                keyNode=keyNode->right;
            }

            keyNode->right = temp;
            
        }

        else{
            if(parent!=NULL){
                if(parent->left!=NULL && parent->left->val == key){
                    parent->left = NULL;
                }

                else if(parent->right!=NULL && parent->right->val == key){
                    parent->right = NULL;
                }
            }

            else{
                return NULL;
            }
        }   

        return root;
    }
};