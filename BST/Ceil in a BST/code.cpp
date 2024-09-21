int findCeil(Node* root, int input) {
    int ans=1e5+1;
    if (root == NULL) return -1;
    while(root!=NULL){
        if(root->data==input){
            return input;
        }
        
        if(root->data>input){
            ans = min(ans, root->data);
            root = root->left;
        }
        
        else{
           root=root->right; 
        }
    }
    
    if(ans==1e5+1){
        return -1;
    }
    
    return ans;
    // Your code here
}