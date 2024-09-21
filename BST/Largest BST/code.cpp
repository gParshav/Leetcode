/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool isValid(Node* root, int& temp, int low, int high){
        
        if(root==NULL){
            return true;
        }
        
        if(root->data<=low || root->data>=high){
            return false;
        }
        
        bool l = isValid(root->left, temp, low, root->data);
        temp++;
        bool r = isValid(root->right, temp, root->data, high);
        return l&&r;
    }
    
    void find(Node* root, int& ans){
        
        if(root==NULL){
            return;
        }
        
        int temp = 0;
        if(isValid(root, temp, INT_MIN, INT_MAX)){
            ans = max(ans, temp);
        }
        
        find(root->left, ans);
        find(root->right, ans);
        
    }
    
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans = 1;
    	find(root, ans);
    	return ans;
    	
    }
};