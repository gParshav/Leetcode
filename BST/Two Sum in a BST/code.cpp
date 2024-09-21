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
    void findInorder(vector<int> &arr, TreeNode* root){

        if(root==NULL){
            return;
        }

        findInorder(arr, root->left);
        arr.push_back(root->val);
        findInorder(arr, root->right);
    }


    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        findInorder(arr, root);
        int i=0, j=arr.size()-1;
        while(i<j){
            
            if(arr[i]+arr[j]==k){
                return true;
            }

            else if(arr[i]+arr[j]<k){
                i++;
            }

            else{
                j--;
            }
        }

        return false;
    }
};


class Solution {
public:
    int lowestElement(stack<TreeNode*>& lst, TreeNode* root){

        TreeNode* temp = root;
        while(temp!=NULL){
            lst.push(temp);
            temp = temp->left;
        }

        int ans = lst.top()->val;
        return ans;
    }

    int highestElement(stack<TreeNode*>& rst, TreeNode* root){

        TreeNode* temp = root;
        while(temp!=NULL){
            rst.push(temp);
            temp = temp->right;
        }

        int ans = rst.top()->val;
        return ans;
    }


    int nextElement(stack<TreeNode*>& lst){

        if(lst.empty()){
            return 1e5;
        }
        TreeNode* temp = lst.top();
        lst.pop();
        temp = temp->right;
        while(temp!=NULL){
            lst.push(temp);
            temp = temp->left;
        }
        int ans = lst.top()->val;
        return ans;
    }

    int prevElement(stack<TreeNode*>& rst){

        if(rst.empty()){
            return 1e5;
        }
        TreeNode* temp = rst.top();
        rst.pop();
        temp = temp->left;
        while(temp!=NULL){
            rst.push(temp);
            temp = temp->right;
        }
        int ans = rst.top()->val;
        return ans; 
    }


    bool findTarget(TreeNode* root, int k) {
        
        stack<TreeNode*> lst;
        stack<TreeNode*> rst;
        int a = lowestElement(lst, root);
        int b = highestElement(rst, root);
        while(a<b){
            if(a+b==k){
                return true;
            }

            else if(a+b<k){
                a = nextElement(lst);
            }

            else{
                b = prevElement(rst);
            }
        }

        return false;

    }
};