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
class BSTIterator {

    vector<int> inO;
    int index = 0;
public:
    
    void inorder(TreeNode* root, vector<int> &inO){
        if(root==NULL){
            return;
        }

        inorder(root->left, inO);
        inO.push_back(root->val);
        inorder(root->right, inO);
    }

    BSTIterator(TreeNode* root) {
        
        inorder(root, inO);
    }
    
    int next() {
        index++;
        return inO[index-1];
    }
    
    bool hasNext() {
        
        if(index<inO.size()){
            return true;
        }

        return false;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 
 class BSTIterator {

    stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        
        while(root!=NULL){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* temp = st.top();
        int ans = temp->val;
        st.pop();
        TreeNode* temp2 = temp->right;
        if(temp2!=NULL){
            st.push(temp->right);
            while(temp2->left!=NULL){
                st.push(temp2->left);
                temp2 = temp2->left;
            }
        }
        return ans;
    }
    
    bool hasNext() {
        
        if(!st.empty()){
            return true;
        }

        return false;
    }
};