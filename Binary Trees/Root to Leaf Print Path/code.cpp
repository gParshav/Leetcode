/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void makePaths(Node* root, vector<int> temp, vector<vector<int>>& ans){
        if(root==NULL){
            return;
        }
        if(root!=NULL && root->left==NULL && root->right==NULL){
            temp.push_back(root->data);    
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(root->data);
        makePaths(root->left, temp, ans);
        makePaths(root->right, temp, ans);
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        makePaths(root, temp, ans);
        return ans;
    }
};